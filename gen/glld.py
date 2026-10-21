#!/usr/bin/env python3

import os
import sys
import traceback
import xml.etree.ElementTree as ET


path    = os.path.dirname(__file__)
name    = 'glld.h'
version = '2.1'
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
    parse = { 'enums'      : [],
              'commands'   : [],
              'feature'    : [],
              'extensions' : [] }

    # iterate over the 'registry' node
    for child in tree.getroot():

        if child.tag == 'enums':
            parse['enums'].append(gl_parsexml_enums(child))

        elif child.tag == 'commands':
            parse['commands'].append(gl_parsexml_commands(child))

        elif child.tag == 'feature':
            parse['feature'].append(gl_parsexml_feature(child))

        elif child.tag == 'extensions':
            parse['extensions'] = gl_parsexml_extensions(child)

    return (parse)


# ==========================
# SECTION: xml parser - enum
# ==========================

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


# =============================
# SECTION: xml parser - command
# =============================

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
    result = { 'name'  : None,
               'ptype' : None, }

    if element.text:
        result['ptype'] = element.text.strip()

    for child in element:
        if child.tag == 'ptype':
            if result['ptype'] is not None:
                result['ptype'] += ' '
            else:
                result['ptype'] = ''
            result['ptype'] += f'{child.text.strip()}'.rstrip() 
            if child.tail.strip():
                result['ptype'] += f' {child.tail.strip()}'.rstrip()

        elif child.tag == 'name':
            result['name'] = child.text

    return (result)


def gl_parsexml_param(elements: list(ET.Element)):
    result = [ ]
    for element in elements:
        param = { 'name'   : None,
                  'ptype'  : None,
                  'group'  : element.get('group'),
                  'class'  : element.get('class'),
                  'length' : element.get('len') }

        if element.text:
            param['ptype'] = element.text.strip()

        for child in element:
            if child.tag == 'ptype':
                if param['ptype'] is not None:
                    param['ptype'] += ' '
                else:
                    param['ptype'] = ''
                param['ptype'] += f'{child.text.strip()}'.rstrip() 
                if child.tail.strip():
                    param['ptype'] += f' {child.tail.strip()}'.rstrip()

            elif child.tag == 'name':
                param['name'] = child.text

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


# ===============
# SECTION: loader
# ===============

def opengl_loader(parse):
    # open and read 'template.h'
    fstr = ''
    with open(f'{path}/template.h') as f:
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
               .replace('<<glld-gl-sc-version>>', gl_es_version)

    # Advanced templates...
    
    fstr = fstr.replace('<<glld-gl-macros>>',                glld_gl_macros(parse))                \
               .replace('<<glld-gl-enums>>',                 glld_gl_enums(parse))                 \
               .replace('<<glld-gl-functions>>',             glld_gl_functions(parse))             \
               .replace('<<glld-gl-function-macros>>',       glld_gl_function_macros(parse))       \
               .replace('<<glld-gl-function-array>>',        glld_gl_function_array(parse))        \
               .replace('<<glld-gl-function-declarations>>', glld_gl_function_declarations(parse))

    # open and write 'glld.h'
    with open('glld.h', 'w') as f:
        f.write(fstr)


# =================
# SECTION: template
# =================

def glld_gl_macros(parse):
    features = parse['feature']
    if features is None:
        return (None)
    
    extensions = parse['extensions']
    if extensions is None:
        return (None)

    items = [ ]
    for feature in features:
        items.append(f'# define {feature['name']}')

    items.append('# if defined (GLLD_EXTENSIONS)')
    for extension in extensions:
        items.append(f'#  define {extension['name']}')
    items.append('# endif')

    return ('\n'.join(items))


def glld_gl_enums(parse):
    features = parse['feature']
    if features is None:
        return (None)

    extensions = parse['extensions']
    if extensions is None:
        return (None)

    enums = parse['enums']
    if enums is None:
        return (None)

    items = [ ]
    for feature in features:
        requires = feature['require']
        if not any(require['enum'] for require in requires):
            continue

        items.append(f'# if defined ({feature['name']}) /* {{{{{{ */')
        for require in requires:
            for string in require['enum']:
                enum = None
                for group in enums:
                    for item in group['enum']:
                        if item['name'] == string:
                            enum = item
                if enum is None:
                    continue

                items.append(f'#  define {enum['name']} {enum['value']}')
        
        items.append('# endif /* }}} */')

    items.append('# if defined (GLLD_EXTENSIONS)')
    for extension in extensions:
        requires = extension['require']
        if not any(require['enum'] for require in requires):
            continue

        items.append(f'#  if defined ({extension['name']}) /* {{{{{{ */')
        for require in requires:
            for string in require['enum']:
                enum = None
                for group in enums:
                    for item in group['enum']:
                        if item['name'] == string:
                            enum = item
                if enum is None:
                    continue

                items.append(f'#   define {enum['name']} {enum['value']}')

        items.append('# endif /* }}} */')

    items.append('# endif')

    return ('\n'.join(items))


def glld_gl_functions(parse):
    features = parse['feature']
    if features is None:
        return (None)

    extensions = parse['extensions']
    if extensions is None:
        return (None)

    commands = parse['commands']
    if commands is None:
        return (None)

    items = [ ]
    for feature in features:
        requires = feature['require']
        if not any(require['command'] for require in requires):
            continue

        items.append(f'# if defined ({feature['name']}) /* {{{{{{ */')
        for require in requires:
            for string in require['command']:
                command = None
                for block in commands:
                    for item in block['command']:
                        if item['name'] == string:
                            command = item
                if command is None:
                    continue
                
                name  = command['proto']['name']
                pname = command['proto']['name'].upper()
                ptype = command['proto']['ptype']
                proto = f'typedef {ptype} (APIENTRYP PFN{pname}PROC)'

                params = [ ]
                for param in command['param']:
                     params.append(param['ptype'])
                param = ', '.join(params)
                
                items.append(f'{proto} ({param});')
                items.append(f'extern PFN{pname}PROC glld_{name};')
        
        items.append('# endif /* }}} */')

    items.append('# if defined (GLLD_EXTENSIONS)')
    for extension in extensions:
        requires = extension['require']
        if not any(require['command'] for require in requires):
            continue

        items.append(f'#  if defined ({extension['name']}) /* {{{{{{ */')
        for require in requires:
            for string in require['command']:
                command = None
                for block in commands:
                    for item in block['command']:
                        if item['name'] == string:
                            command = item
                if command is None:
                    continue
               
                name  = command['proto']['name']
                pname = command['proto']['name'].upper()
                ptype = command['proto']['ptype']
                proto = f'typedef {ptype} (APIENTRYP PFN{pname}PROC)'

                params = [ ]
                for param in command['param']:
                     params.append(param['ptype'])
                param = ', '.join(params)
                
                items.append(f'{proto} ({param});')
                items.append(f'extern PFN{pname}PROC glld_{name};')

        items.append('# endif /* }}} */')

    items.append('# endif')

    return ('\n'.join(items))


def glld_gl_function_macros(parse):
    features = parse['feature']
    if features is None:
        return (None)

    extensions = parse['extensions']
    if extensions is None:
        return (None)

    commands = parse['commands']
    if commands is None:
        return (None)

    items = [ ]
    for feature in features:
        requires = feature['require']
        if not any(require['command'] for require in requires):
            continue

        items.append(f'# if defined ({feature['name']}) /* {{{{{{ */')
        for require in requires:
            for string in require['command']:
                items.append(f'#  define {string} glld_{string}')

        items.append('# endif /* }}} */')

    items.append('# if defined (GLLD_EXTENSIONS)')
    for extension in extensions:
        requires = extension['require']
        if not any(require['command'] for require in requires):
            continue

        items.append(f'#  if defined ({extension['name']}) /* {{{{{{ */')
        for require in requires:
            for string in require['command']:
                items.append(f'#  define {string} glld_{string}')

        items.append('#  endif /* }}} */')

    items.append('# endif')

    return ('\n'.join(items))


def glld_gl_function_array(parse):
    features = parse['feature']
    if features is None:
        return (None)

    extensions = parse['extensions']
    if extensions is None:
        return (None)

    commands = parse['commands']
    if commands is None:
        return (None)

    items = [ ]
    for feature in features:
        requires = feature['require']
        if not any(require['command'] for require in requires):
            continue

        items.append(f'#  if defined ({feature['name']}) /* {{{{{{ */')
        for require in requires:
            for string in require['command']:
                items.append(f'    {{ \"{string}\", (void **) &glld_{string} }},')
        items.append('#  endif /* }}} */')

    items.append('#  if  defined (GLLD_EXTENSIONS)')
    
    for extension in extensions:
        requires = extension['require']
        if not any(require['command'] for require in requires):
            continue

        items.append(f'#   if defined ({extension['name']}) /* {{{{{{ */')
        for require in requires:
            for string in require['command']:
                items.append(f'    {{ \"{string}\", (void **) &glld_{string} }},')
        
        items.append('#   endif /* }}} */')

    items.append('#  endif')

    return ('\n'.join(items))


def glld_gl_function_declarations(parse):
    features = parse['feature']
    if features is None:
        return (None)

    extensions = parse['extensions']
    if extensions is None:
        return (None)

    commands = parse['commands']
    if commands is None:
        return (None)

    items = [ ]
    for feature in features:
        requires = feature['require']
        if not any(require['command'] for require in requires):
            continue

        items.append(f'#  if defined ({feature['name']}) /* {{{{{{ */')
        for require in requires:
            for string in require['command']:
                function = f'PFN{string.upper()}PROC glld_{string};'
                for item in items:
                    if function == item:
                        function = f'extern {function}'
                        break
                items.append(function)
                
        items.append('#  endif /* }}} */')

    items.append('#  if  defined (GLLD_EXTENSIONS)')
    
    for extension in extensions:
        requires = extension['require']
        if not any(require['command'] for require in requires):
            continue

        items.append(f'#   if defined ({feature['name']}) /* {{{{{{ */')
        for require in requires:
            for string in require['command']:
                function = f'PFN{string.upper()}PROC glld_{string};'
                for item in items:
                    if function == item:
                        function = f'extern {function}'
                        break
                items.append(function)
                
        items.append('#   endif /* }}} */')

    items.append('#  endif')

    return ('\n'.join(items))

# =============
# SECTION: main
# =============

if __name__ == '__main__':
    try:
        tree = gl_loadxml(f'{path}/xml/gl.xml')
        parse = gl_parsexml(tree)
        opengl_loader(parse)
    except Exception as e:
        traceback.print_exception(e)
        sys.exit(1)
