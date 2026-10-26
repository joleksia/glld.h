#!/usr/bin/env python3

import os
import sys
import traceback
import xml.etree.ElementTree as ET


path    = os.path.dirname(__file__)
name    = 'glld.h'
version = '3.0'
author  = 'Jakub Oleksiak (yakubofficialmail@gmail.com)'
licence = 'GNU LESSER GENERAL PUBLIC LICENSE Version 3, 29 June 2007'


gl_profile = 'core'

# Source: https://en.wikipedia.org/wiki/OpenGL#History
gl_version = '4.6'
gl_version_list: list = [
    '1.0', '1.1', '1.2', '1.2.1', '1.3', '1.4', '1.5',
    '2.0', '2.1',
    '3.0', '3.1', '3.2', '3.3',
    '4.0', '4.1', '4.2', '4.3', '4.4', '4.5', '4.6'
]


# Source: https://en.wikipedia.org/wiki/OpenGL_ES#Versions
gl_es_version = '3.2'
gl_es_version_list: list = [
    '1.0', '1.1',
    '2.0',
    '3.0', '3.1', '3.2'
]


# Source: https://en.wikipedia.org/wiki/OpenGL_SC
gl_sc_version = '2.0'
gl_sc_version_list: list = [
    '1.0',
    '2.0'
]


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
            parse['types'].extend(gl_parsexml_types(child))

        elif child.tag == 'enums':
            parse['enums'].append(gl_parsexml_enums(child))

        elif child.tag == 'commands':
            parse['commands'].append(gl_parsexml_commands(child))

        elif child.tag == 'feature':
            parse['feature'].append(gl_parsexml_feature(child))

        elif child.tag == 'extensions':
            parse['extensions'].extend(gl_parsexml_extensions(child))

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
        name = child.find('name')
        apientry = child.find('apientry')
        if apientry is not None:
            item['value'] += 'APIENTRY'
            item['value'] += apientry.tail 

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

def gl_parsexml_commands(element: ET.Element):
    result = { 'namespace' : element.get('namespace'),
               'command'   : [ ] }

    # iterate over the every child in <commands>
    for child in element:
        if child.tag == 'command':
            item = { 'name'  : None,
                     'proto' : None,
                     'param' : None,
                     'alias' : None,
                     'glx'   : None }

            proto = child.find('proto')
            if proto is not None:
                item['name']  = proto.find('name').text
                item['proto'] = gl_parsexml_proto(proto)
            
            alias = child.find('alias')
            if alias is not None:
                item['alias'] = alias.get('name')

            glx = child.find('glx')
            if glx is not None:
                pass # ...

            param = child.findall('param')
            if param is not None:
                item['param'] = gl_parsexml_param(param)

            result['command'].append(item)
   
    return (result)


def gl_parsexml_proto(element: ET.Element):
    result = { 'pname' : '',
               'ptype' : '',
               'value' : '' }

    if element.text:
        result['ptype'] = element.text.strip()
        result['value'] = element.text.strip()

    for child in element:
        if child.tag == 'ptype':
            result['ptype'] = f'{child.text.strip()}'.rstrip() 

            if len(result['value']):
                result['value'] += ' '
            result['value'] += result['ptype']
            if child.tail.strip():
                result['value'] += f' {child.tail.strip()}'.rstrip()

        elif child.tag == 'name':
            result['pname'] = child.text

    return (result)


def gl_parsexml_param(elements: list(ET.Element)):
    result = [ ]
    for element in elements:
        param = { 'pname'  : '',
                  'ptype'  : '',
                  'value'  : '',
                  'group'  : element.get('group'),
                  'class'  : element.get('class'),
                  'len'    : element.get('len') }

        if element.text:
            param['ptype'] = element.text.strip()
            param['value'] = element.text.strip()

        for child in element:
            if child.tag == 'ptype':
                param['ptype'] = f'{child.text.strip()}'.rstrip() 

                if len(param['value']):
                    param['value'] += ' '
                param['value'] += param['ptype']
                if child.tail.strip():
                    param['value'] += f' {child.tail.strip()}'.rstrip()

            elif child.tag == 'name':
                param['pname'] = child.text

        result.append(param)

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

# =============================
# SECTION: xml parser - feature
# =============================

def gl_parsexml_feature(element: ET.Element):
    result = { 'api'     : element.get('api'),
               'name'    : element.get('name'),
               'number'  : element.get('number'),
               'require' : [ ] }

    for require in element.findall('require'):
        result['require'].append(gl_parsexml_require(require))

    return (result)


def gl_parsexml_feature_typedep(parse, feature):
    types = parse['types']
    types_names = { }
    for type in types:
        types_names[type['name']] = type

    commands = parse['commands']
    commands_names = { }
    for command in commands:
        for child in command['command']:
            commands_names[child['name']] = child

    # extract 'commands' from the 'feature'
    r_command = [ ]
    f_command = [ ]
    for require in feature['require']:
        r_command.extend(require['command'])
    f_command = [ commands_names[name] for name in r_command if name in commands_names ]

    # iterate on every command of the 'feature' and extract the types
    gl_types = [ ]
    for command in f_command:
        # append 'proto' 'ptype' if not in 'gl_types'
        proto = command['proto']['ptype']
        if proto not in gl_types:
            gl_types.append(proto)

        # append 'param' 'ptype's if not in 'gl_types'
        for param in command['param']:
            ptype = param['ptype']
            if ptype not in gl_types:
                gl_types.append(ptype)

    # return required 'types'
    result = [ types_names[name] for name in gl_types if name in types_names ]
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

        for require in child.findall('require'):
                extension['require'].append(gl_parsexml_require(require))

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
               .replace('<<glld-gl-es-version>>', gl_es_version) \
               .replace('<<glld-gl-sc-version>>', gl_es_version) \

    # Advanced templates...
    
    fstr = fstr.replace('<<glld-gl-feature>>',      glld_c_gl_main(parse, parse['feature']))    \
               .replace('<<glld-gl-extensions>>',   glld_c_gl_main(parse, parse['extensions'])) \
               .replace('<<glld-gl-glapi>>',        glld_c_gl_glapi(parse))                     \
               .replace('<<glld-gl-extern>>',       glld_c_gl_extern(parse))                    \
               .replace('<<glld-gl-global>>',       glld_c_gl_global(parse))                    \
               .replace('<<glld-gl-load>>',         glld_c_gl_load(parse))                      \
               .replace('<<glld-gl-bind>>',         glld_c_gl_bind(parse))                      \

    # open and write 'output' file
    with open(output, 'w') as f:
        f.write(fstr)


# list of already used types
u_type = [ ]
def glld_c_gl_main(parse, bases):
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
            commands_names[child['name']] = child

    # list of already used types
    global u_type

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

        # match requirements to desired types, enums and commands
        f_type = [ types_names[name] for name in r_type if name in types_names ]
        f_enum = [ enums_names[name] for name in r_enum if name in enums_names ]
        f_command = [ commands_names[name] for name in r_command if name in commands_names ]

        # get dependent types of the 'base'
        d_type = gl_parsexml_feature_typedep(parse, base)

        # extend 'f_type' by 'd_type'
        f_type = [ type for type in f_type if type not in u_type ]
        f_type.extend( [ type for type in d_type if type not in u_type ] )

        # update 'u_type' used types with 'f_type' and 'd_type'
        u_type.extend( [ type for type in f_type if type not in u_type ] )

        # insert lines
        lines.append(f'# if !defined ({base['name']}) /* {{{{{{ */')
        lines.append(f'#  define {base['name']} 1')
       
        # insert 'f_type'
        if len(f_type):
            lines.append('')
            for type in f_type:
                lines.append(type['value'])

        # insert 'f_enum'
        if len(f_enum):
            if len(f_type):
                lines.append('')
            for enum in f_enum:
                lines.append(f'#  define {enum['name']} {enum['value']}')
   
        # insert 'f_command'
        if len(f_command):
            lines.append('')
            for command in f_command:
                pname = command['proto']['pname']
                ptype = command['proto']['ptype']
                param = [ ]
                for child in command['param']:
                     param.append(f'{child['value']}')
                lines.append(f'typedef {ptype} (APIENTRY *PFN{pname.upper()}PROC) ({', '.join(param)});')
            lines.append('')
        lines.append(f'# endif /* {base['name']} */ /* }}}}}} */')
    return ('\n'.join(lines))


def glld_c_gl_glapi(parse):
    commands = parse['commands']
    commands_names = { }
    for command in commands:
        for child in command['command']:
            commands_names[child['name']] = child

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
                name = command['proto']['pname']
                line = f'\tPFN{name.upper()}PROC {name};'
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
                name = command['proto']['pname']
                line = f'\tPFN{name.upper()}PROC {name};'
                if line not in lines:
                    lines.append(line)
    
    return ('\n'.join(lines))


def glld_c_gl_extern(parse):
    commands = parse['commands']
    commands_names = { }
    for command in commands:
        for child in command['command']:
            commands_names[child['name']] = child

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

        # insert lines
        lines.append(f'# if defined ({feature['name']}) /* {{{{{{ */')
       
        # insert 'f_command'
        if len(f_command):
            lines.append('')
            for command in f_command:
                name = command['proto']['pname']
                line = f'extern PFN{name.upper()}PROC {name};'
                lines.append(line)
            lines.append('')
        lines.append(f'# endif /* {feature['name']} */ /* }}}}}} */')
    
    extensions = parse['extensions']
    for extension in extensions:
        requires = extension['require']

        # extract required commands from 'extension' 
        r_command = [ ]
        for require in requires:
            r_command.extend(require['command'])

        # match requirements to desired commands
        f_command = [ commands_names[name] for name in r_command if name in commands_names ]

        # insert lines
        lines.append(f'# if defined ({extension['name']}) /* {{{{{{ */')
       
        # insert 'f_command'
        if len(f_command):
            lines.append('')
            for command in f_command:
                name = command['proto']['pname']
                line = f'extern PFN{name.upper()}PROC {name};'
                lines.append(line)
            lines.append('')
        lines.append(f'# endif /* {extension['name']} */ /* }}}}}} */')
    return ('\n'.join(lines))


def glld_c_gl_global(parse):
    commands = parse['commands']
    commands_names = { }
    for command in commands:
        for child in command['command']:
            commands_names[child['name']] = child

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
                name = command['proto']['pname']
                line = f'PFN{name.upper()}PROC {name};'
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
                name = command['proto']['pname']
                line = f'PFN{name.upper()}PROC {name};'
                if line not in lines:
                    lines.append(line)
    
    return ('\n'.join(lines))


def glld_c_gl_load(parse):
    commands = parse['commands']
    commands_names = { }
    for command in commands:
        for child in command['command']:
            commands_names[child['name']] = child

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
                name = command['proto']['pname']
                line = f'\tpApi->{name} = (PFN{name.upper()}PROC) pLoad("{name}");'
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
                name = command['proto']['pname']
                line = f'\tpApi->{name} = (PFN{name.upper()}PROC) pLoad("{name}");'
                if line not in lines:
                    lines.append(line)
    
    return ('\n'.join(lines))


def glld_c_gl_bind(parse):
    commands = parse['commands']
    commands_names = { }
    for command in commands:
        for child in command['command']:
            commands_names[child['name']] = child

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
                name = command['proto']['pname']
                line = f'\t{name} = pApi->{name};'
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
                name = command['proto']['pname']
                line = f'\t{name} = pApi->{name};'
                if line not in lines:
                    lines.append(line)
    
    return ('\n'.join(lines))

# =============
# SECTION: main
# =============

if __name__ == '__main__':
    try:
        # load and parse 'gl.xml'
        gl_xml = gl_loadxml(f'{path}/xml/gl.xml')
        gl_parse = gl_parsexml(gl_xml)
        
        # output module: C Header
        glld_c_template(gl_parse, f'{path}/template.h', 'glld.h')

    except Exception as e:
        traceback.print_exception(e)
        sys.exit(1)
