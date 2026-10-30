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
    parse = { 'types'      : [],
              'enums'      : [],
              'commands'   : [],
              'feature'    : [],
              'extensions' : [] }

    # iterate over the 'registry' node
    for child in tree.getroot():

        if child.tag == 'types':
            types = gl_parsexml_types(child)
            if types is not None:
                parse['types'].extend(types)

        elif child.tag == 'enums':
            enums = gl_parsexml_enums(child)
            if enums is not None:
                parse['enums'].append(enums)

        elif child.tag == 'commands':
            commands = gl_parsexml_commands(child)
            if commands is not None:
                parse['commands'].append(commands)

        elif child.tag == 'feature':
            feature = gl_parsexml_feature(child)
            if feature is not None:
                parse['feature'].append(feature)

        elif child.tag == 'extensions':
            extensions = gl_parsexml_extensions(child)
            if extensions is not None:
                parse['extensions'].extend(extensions)

    return (parse)

# ===========================
# SECTION: xml parser - types
# ===========================

def gl_parsexml_types(element: ET.Element):
    result = [ ]

    # iterate over the every child in <types>
    for child in element:
        item = { 'name'     : child.get('name'),
                 'value'    : child.text or '',
                 'requires' : child.get('requires') }

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
        result.append(item)
        
    return (result)

# ===========================
# SECTION: xml parser - enums
# ===========================

def gl_parsexml_enums(element: ET.Element):
    result = { 'namespace' : element.get('namespace'),
               'type'      : element.get('type'),
               'enum'      : [ ] }

    # iterate over the every child in <enums>
    for child in element:
        if child.tag == 'enum':
            item = { 'name'  : child.get('name'),
                     'value' : child.get('value'),
                     'group' : child.get('group') }

            result['enum'].append(item)

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
    result = { 'namespace' : element.get('namespace'),
               'command'   : [ ] }

    # iterate over the every child in <commands>
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

            result['command'].append(item)
   
    return (result)

# =============================
# SECTION: xml parser - require
# =============================

def gl_parsexml_require(element: ET.Element):
    result = { 'type'    : [ ],
               'enum'    : [ ],
               'command' : [ ] }

    for child in element:
        if child.tag == 'type':
            result['type'].append(child.get('name'))
        elif child.tag == 'enum':
            result['enum'].append(child.get('name'))
        elif child.tag == 'command':
            result['command'].append(child.get('name'))
    return (result)


def gl_parsexml_require_dependencies(parse, feature):
    types = parse['types']
    types_names = { }
    for type in types:
        types_names[type['name']] = type

    commands = parse['commands']
    commands_names = { }
    for command in commands:
        for child in command['command']:
            commands_names[child['pname']] = child

    # extract 'commands' from the 'feature'
    r_command = [ ]
    f_command = [ ]
    for require in feature['require']:
        r_command.extend(require['command'])
    f_command = [ commands_names[name] for name in r_command if name in commands_names ]

    # iterate on every command of the 'feature' and extract the types
    result = [ ]
    for command in f_command:
        # get proto's 'ptype'
        ptype = command['proto']['ptype']
        
        # find type matching 'ptype'
        for type in types:
            if type['name'] in ptype and type not in result:
                result.append(type)

        # append 'param' 'ptype's if not in 'gl_types'
        for param in command['param']:
            ptype = param['ptype']

            # find type matching 'ptype'
            for type in types:
                if type['name'] in ptype and type not in result:
                    result.append(type)

    return (result)

# =============================
# SECTION: xml parser - feature
# =============================

def gl_parsexml_feature(element: ET.Element):
    result = { 'api'     : element.get('api'),
               'name'    : element.get('name'),
               'number'  : element.get('number'),
               'require' : [ ] }

    # 'gl' not supported: return 'None'
    if result['api'] != 'gl':
        return (None)

    for requires in element.findall('require'):
        require = gl_parsexml_require(requires)
        if require is not None:
            result['require'].append(require)

    return (result)

# ================================
# SECTION: xml parser - extensions
# ================================

def gl_parsexml_extensions(element: ET.Element):
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
            require = gl_parsexml_require(requires)
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


# lists of already used/defined objects
u_type = [ ]
u_enum = [ ]
u_command = [ ]

def glld_c_gl_main(parse):
    types = parse['types']
    types_names = { }
    for type in types:
        types_names[type['name']] = type

    enums = parse['enums']
    enums_names = { }
    for enum in enums:
        for child in enum['enum']:
            enums_names[child['name']] = child

    commands = parse['commands']
    commands_names = { }
    for command in commands:
        for child in command['command']:
            commands_names[child['pname']] = child

    # lists of already used/defined objects
    global u_type
    global u_enum
    global u_command

    def logic(bases):
        lines = [ ]
        for base in bases:
            requires = base['require']

            # extract required types, enums and commands from 'feature' 
            r_type = [ ]
            r_enum = [ ]
            r_command = [ ]
            for require in requires:
                r_type.extend(require['type'])
                r_enum.extend(require['enum'])
                r_command.extend(require['command'])
        
            # extract the list of type dependencies of this 'base'
            d_type = gl_parsexml_require_dependencies(parse, base)

            # names-to-object mapping 
            f_type = [ types_names[name] for name in r_type if name in types_names ]
            f_enum = [ enums_names[name] for name in r_enum if name in enums_names ]
            f_command = [ commands_names[name] for name in r_command if name in commands_names ]
           
            # append absent, non-used type dependencies
            f_type.extend( [ type for type in d_type if type not in u_type and type not in f_type ] )
            
            # extract already used objects
            f_type = [ type for type in f_type if type not in u_type ]
            f_enum = [ enum for enum in f_enum if enum not in u_enum ]
            f_command = [ command for command in f_command if command not in u_command ]
            
            # append already used objects
            u_type.extend( [ type for type in f_type if type not in u_type ] )
            u_enum.extend( [ enum for enum in f_enum if enum not in u_enum ] )
            u_command.extend( [ command for command in f_command if command not in u_command ] )

            # insert lines
            name = base['name']
            lines.append(f'# if !defined ({name}) /* {{{{{{ */')
            lines.append(f'#  define {name} 1')
            
            # insert 'f_enum'
            if len(f_enum):
                for enum in f_enum:
                    ename  = enum['name']
                    evalue = enum['value']
                    lines.append(f'#  define {ename} {evalue}')
           
            # insert 'f_type'
            if len(f_type):
                lines.append('')
                for type in f_type:
                    lines.append(type['value'])
       
            # insert 'f_command'
            if len(f_command):
                lines.append('')
                for command in f_command:
                    param = [ ]
                    for child in command['param']:
                        ptype = child['ptype']
                        param.append(ptype)
                    
                    proto = command['proto']
                    ptype = proto['ptype']
                    pname = proto['pname']

                    lines.append(f'typedef {ptype} (APIENTRY *PFN{pname.upper()}PROC) ({", ".join(param)});')
                lines.append('')
            lines.append(f'# endif /* {name} */ /* }}}}}} */')
        return (lines)

    lines = [ ]
    lines.extend(logic(parse['feature']))
    lines.extend(logic(parse['extensions']))
    return ('\n'.join(lines))


def glld_c_gl_declare(parse, prefix: str | None):
    commands = parse['commands']
    commands_names = { }
    for command in commands:
        for child in command['command']:
            commands_names[child['pname']] = child

    def logic(bases):
        lines = [ ]
        for base in bases:
            r_command = [ ]
            for require in base['require']:
                r_command.extend(require['command'])
            f_command = [ commands_names[name] for name in r_command if name in commands_names ]
        
            # insert 'f_command'
            if len(f_command):
                for command in f_command:
                    line = ''
                    if prefix:
                        line += f'{prefix} '
                    
                    pname = command['pname']
                    if pname:
                        line += f'PFN{pname.upper()}PROC {pname};'

                    line = line.strip()
                    if line not in lines:
                        lines.append(line)
        return (lines)
        

    # list of 'lines'
    lines = [ ]
    lines.extend(logic(parse['feature']))
    lines.extend(logic(parse['extensions']))
    return ('\n'.join(lines))


def glld_c_gl_load(parse):
    commands = parse['commands']
    commands_names = { }
    for command in commands:
        for child in command['command']:
            commands_names[child['pname']] = child

    lines = [ ] 
    
    features = parse['feature']
    for feature in features:
        requires = feature['require']

        # extract required commands from 'feature' 
        r_command = [ ]
        for require in requires:
            r_command.extend(require['command'])

        # match requirements to desired commands
        f_command = [ commands_names[name] for name in r_command if name in commands_names ]

        # insert 'f_command'
        if len(f_command):
            for command in f_command:
                pname = command['pname']
                line  = f'\tpApi->{pname} = (PFN{pname.upper()}PROC) pLoad("{pname}");'
                if line not in lines:
                    lines.append(line)
    
    extensions = parse['extensions']
    for extension in extensions:
        requires = extension['require']

        # extract required commands from 'extension' 
        r_command = [ ]
        for require in requires:
            r_command.extend(require['command'])

        # match requirements to desired commands
        f_command = [ commands_names[name] for name in r_command if name in commands_names ]

        # insert 'f_command'
        if len(f_command):
            for command in f_command:
                pname = command['pname']
                line  = f'\tpApi->{pname} = (PFN{pname.upper()}PROC) pLoad("{pname}");'
                if line not in lines:
                    lines.append(line)
    
    return ('\n'.join(lines))


def glld_c_gl_bind(parse):
    commands = parse['commands']
    commands_names = { }
    for command in commands:
        for child in command['command']:
            commands_names[child['pname']] = child

    lines = [ ] 
    
    features = parse['feature']
    for feature in features:
        requires = feature['require']

        # extract required commands from 'feature' 
        r_command = [ ]
        for require in requires:
            r_command.extend(require['command'])

        # match requirements to desired commands
        f_command = [ commands_names[name] for name in r_command if name in commands_names ]

        # insert 'f_command'
        if len(f_command):
            for command in f_command:
                pname = command['pname']
                line  = f'\t{pname} = pApi->{pname};'
                if line not in lines:
                    lines.append(line)
    
    extensions = parse['extensions']
    for extension in extensions:
        requires = extension['require']

        # extract required commands from 'extension' 
        r_command = [ ]
        for require in requires:
            r_command.extend(require['command'])

        # match requirements to desired commands
        f_command = [ commands_names[name] for name in r_command if name in commands_names ]

        # insert 'f_command'
        if len(f_command):
            for command in f_command:
                pname = command['pname']
                line  = f'\t{pname} = pApi->{pname};'
                if line not in lines:
                    lines.append(line)
    
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
