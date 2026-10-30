#!/usr/bin/env python3

import os
import sys
import traceback
import xml.etree.ElementTree as ET


name = 'glld.h'
author = 'Jakub Oleksiak (yakubofficialmail@gmail.com)'
version = '3.1'
licence = 'GNU LESSER GENERAL PUBLIC LICENSE Version 3, 29 June 2007'

gl_profile = 'core'

# Source: https://en.wikipedia.org/wiki/OpenGL#History
gl_version = '4.6'

# ===================
# SECTION: xml parser
# ===================

def gl_loadxml(filepath: str) -> ET.ElementTree:
    return (ET.parse(filepath))


def gl_parsexml(tree: ET.ElementTree):
    # 'parse' dictionary of parsed lists
    parse = { 'types'      : { },
              'enums'      : { },
              'commands'   : { },
              'feature'    : [ ],
              'extensions' : [ ] }

    # iterate over the 'registry' node
    for child in tree.getroot():

        if child.tag == 'types':
            types = gl_parsexml_types(child)
            if types is not None:
                parse['types'].update(types)

        elif child.tag == 'enums':
            enums = gl_parsexml_enums(child)
            if enums is not None:
                parse['enums'].update(enums)

        elif child.tag == 'commands':
            commands = gl_parsexml_commands(child)
            if commands is not None:
                parse['commands'].update(commands)

        elif child.tag == 'feature':
            feature = gl_parsexml_feature(child, parse)
            if feature is not None:
                parse['feature'].append(feature)

        elif child.tag == 'extensions':
            extensions = gl_parsexml_extensions(child, parse)
            if extensions is not None:
                parse['extensions'].extend(extensions)
    return (parse)

# ===========================
# SECTION: xml parser - types
# ===========================

def gl_parsexml_types(element: ET.Element):
    result = { }
    for child in element:
        item = { 'name'  : child.get('name'),
                 'value' : child.text or '' }

        # get the inner child nodes
        apientry = child.find('apientry')
        if apientry is not None:
            item['value'] += 'APIENTRY'
            item['value'] += apientry.tail 

        name = child.find('name')
        if name is not None:
            item['name'] = name.text
            item['value'] += name.text
            item['value'] += name.tail
        
        result[item['name']] = item
    return (result)

# ===========================
# SECTION: xml parser - enums
# ===========================

def gl_parsexml_enums(element: ET.Element):
    result = { }
    for child in element:
        if child.tag == 'enum':
            item = { 'name'  : child.get('name'),
                     'value' : child.get('value') }

            result[item['name']] = item
    return (result)

# ==============================
# SECTION: xml parser - commands
# ==============================

def gl_parsexml_proto(element: ET.Element):
    result = { 'pname' : '',
               'ptype' : '' } 

    if element.text:
        result['ptype'] = element.text.strip()

    for child in element:
        match child.tag:

            case 'ptype':
                result['ptype'] += f' {child.text.strip()}'
                result['ptype']  = result['ptype'].strip()

                if child.tail:
                    result['ptype'] += f' {child.tail.strip()}'
                    result['ptype']  = result['ptype'].strip()

            case 'name':
                result['pname'] = child.text.strip()
    return (result)


def gl_parsexml_param(elements: list[ET.Element]):
    result = [ ]
    for element in elements:
        param = { 'pname'  : '',
                  'ptype'  : '' }

        if element.text:
            param['ptype'] = element.text.strip()

        for child in element:
            match child.tag:    

                case 'ptype':
                    param['ptype'] += f' {child.text.strip()}'
                    param['ptype']  = param['ptype'].strip()

                    if child.tail:
                        param['ptype'] += f' {child.tail.strip()}'
                        param['ptype']  = param['ptype'].strip()

                case 'name':
                    param['pname'] += child.text.strip()

        result.append(param)
    return (result)


def gl_parsexml_commands(element: ET.Element):
    result = { }
    for child in element:
        if child.tag == 'command':
            item = { 'pname' : None,
                     'proto' : None,
                     'param' : None }

            proto = child.find('proto')
            if proto is not None:
                item['proto'] = gl_parsexml_proto(proto)
                item['pname'] = item['proto']['pname'] 

            param = child.findall('param')
            if param is not None:
                item['param'] = gl_parsexml_param(param)

            result[item['pname']] = item
    return (result)

# =============================
# SECTION: xml parser - require
# =============================

def gl_parsexml_require(element: ET.Element, parse):
    result = { 'type'    : { },
               'enum'    : { },
               'command' : { } }

    for child in element:
        key = child.get('name')
        match child.tag:

            case 'type':
                result['type'][key] = parse['types'][key]

            case 'enum':
                result['enum'][key] = parse['enums'][key]

            case 'command':
                result['command'][key] = parse['commands'][key]

    # post-process: append dependent types
    d_type = gl_parsexml_trace_deps(parse, result)
    if d_type is not None:
        result['type'].update(d_type)

    return (result)


def gl_parsexml_trace_deps(parse, require):
    types = parse['types']
    if types is None:
        return None

    result = { }
    for command in require['command'].values():
        ptype = command['proto']['ptype']
        for key, value in types.items():
            if key in ptype and key not in result:
                result[key] = value

        for param in command['param']:
            ptype = param['ptype']

            # find type matching 'ptype'
            for key, value in types.items():
                if key in ptype and key not in result:
                    result[key] = value

    return (result)

# =============================
# SECTION: xml parser - feature
# =============================

def gl_parsexml_feature(element: ET.Element, parse):
    # 'parse' should not be 'None', but it's worth checking
    if parse is None:
        return (None)

    result = { 'api'     : element.get('api'),
               'name'    : element.get('name'),
               'number'  : element.get('number'),
               'require' : [ ] }

    # 'gl' not supported: return 'None'
    if result['api'] != 'gl':
        return (None)

    for requires in element.findall('require'):
        require = gl_parsexml_require(requires, parse)
        if require is not None:
            result['require'].append(require)

    return (result)

# ================================
# SECTION: xml parser - extensions
# ================================

def gl_parsexml_extensions(element: ET.Element, parse):
    # 'parse' should not be 'None', but it's worth checking
    if parse is None:
        return (None)

    result = [ ]
    for child in element:
        extension = { 'name'      : child.get('name'),
                      'supported' : child.get('supported'),
                      'require'   : [ ] }

        # 'gl' and 'glcore' not supported: skip
        supported = extension['supported'].split('|')
        if 'gl' not in supported and 'glcore' not in supported:
            continue
    
        for requires in child.findall('require'):
            require = gl_parsexml_require(requires, parse)
            if require is not None:
                extension['require'].append(require)

        result.append(extension)

    return (result)

# ===================
# SECTION: C template
# ===================

def glld_c_template(parse, input, output):
    # open and read 'input' file
    fstr = ''
    with open(input) as f:
        fstr = f.read()

    # Simple templates...

    fstr = fstr.replace('<<glld-author>>',        author)        \
               .replace('<<glld-version>>',       version)       \
               .replace('<<glld-version-major>>', version[0])    \
               .replace('<<glld-version-minor>>', version[2])    \
               .replace('<<glld-licence>>',       licence)       \
               .replace('<<glld-gl-profile>>',    gl_profile)    \
               .replace('<<glld-gl-version>>',    gl_version)    \

    # Advanced templates...
    
    fstr = fstr.replace('<<glld-gl-main>>',     glld_c_gl_main(parse))                      \
               .replace('<<glld-gl-glapi>>',    glld_c_gl_declare(parse, prefix='\t'))      \
               .replace('<<glld-gl-extern>>',   glld_c_gl_declare(parse, prefix='extern'))  \
               .replace('<<glld-gl-global>>',   glld_c_gl_declare(parse, prefix=None))      \
               .replace('<<glld-gl-load>>',     glld_c_gl_load(parse))                      \
               .replace('<<glld-gl-bind>>',     glld_c_gl_bind(parse))                      \

    # open and write 'output' file
    with open(output, 'w') as f:
        f.write(fstr)


def glld_c_gl_main(parse):
    used = { 'type' : set(),
             'enum' : set(),
             'command' : set() }

    # list of 'lines'
    lines = [ ]
    def logic(bases):
        for base in bases:
            new = { key : { } for key in used }

            for require in base['require']:
                for key, value in used.items():
                    for k, v in require[key].items():
                        if k not in value:
                            value.add(k)
                            new[key][k] = v

            name = base['name']
            lines.append(f'# if !defined ({name}) /* {{{{{{ */')
            lines.append(f'#  define {name} 1')
            
            for enum in new['enum'].values():
                lines.append(f'#  define {enum["name"]} {enum["value"]}')

            if new['type']:
                lines.append('')
                lines.extend(type['value'] for type in new['type'].values())
       
            if new['command']:
                lines.append('')
                for command in new['command'].values():
                    param  = command['param']
                    params = [ ]
                    for child in param:
                        params.append(child['ptype'])
                    
                    proto = command['proto']
                    pname = proto['pname']
                    ptype = proto['ptype']

                    lines.append(f'typedef {ptype} (APIENTRY *PFN{pname.upper()}PROC) ({", ".join(params)});')
                lines.append('')
            
            lines.append(f'# endif /* {name} */ /* }}}}}} */')

    logic(parse['feature'])
    logic(parse['extensions'])
    return ('\n'.join(lines))


def glld_c_gl_declare(parse, prefix: str | None):
    # list of 'lines'
    lines = [ ]
    def logic(bases):
        for base in bases:
            commands = { }
            for require in base['require']:
                commands.update(require['command'])
        
            # insert 'commands'
            for command in commands.values():
                line = ''
                if prefix is not None:
                    line += f'{prefix} '
                
                pname = command['pname']
                if pname:
                    line += f'PFN{pname.upper()}PROC {pname};'

                line = line.strip()
                if line not in lines:
                    lines.append(line)

    logic(parse['feature'])
    logic(parse['extensions'])
    return ('\n'.join(lines))


def glld_c_gl_load(parse):
    # list of 'lines'
    lines = [ ]
    def logic(bases):
        for base in bases:
            commands = { }
            for require in base['require']:
                commands.update(require['command'])
        
            # insert 'commands'
            for command in commands.values():
                pname = command['pname']
                line  = f'\tpApi->{pname} = (PFN{pname.upper()}PROC) pLoad("{pname}");'
                if line not in lines:
                    lines.append(line)

    logic(parse['feature'])
    logic(parse['extensions'])
    return ('\n'.join(lines))


def glld_c_gl_bind(parse):
    # list of 'lines'
    lines = [ ]
    def logic(bases):
        for base in bases:
            commands = { }
            for require in base['require']:
                commands.update(require['command'])

            # insert 'commands'
            for command in commands.values():
                pname = command['pname']
                line  = f'\t{pname} = pApi->{pname};'
                if line not in lines:
                    lines.append(line)

    logic(parse['feature'])
    logic(parse['extensions'])
    return ('\n'.join(lines))

# =============
# SECTION: main
# =============

if __name__ == '__main__':
    try:
        # load and parse 'gl.xml'
        gl_xml = gl_loadxml('gen/xml/gl.xml')
        gl_parse = gl_parsexml(gl_xml)
        
        # output module: C Header
        glld_c_template(gl_parse, 'gen/template.h', 'glld.h')

    except Exception as e:
        traceback.print_exception(e)
        sys.exit(1)
