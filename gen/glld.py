#!/usr/bin/env python3

import os
import sys
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
    try:
        tree = ET.parse(filepath)
    except FileNotFoundError as err:
        print(f'{__file__}: {err}')
        sys.exit(1)
    return (tree)


def gl_parsexml(tree: ET.ElementTree):
    root = tree.getroot()
    if root.tag != 'registry':
        print(f'{__file__}: root error')
        sys.exit(1)

    # 'parse' dictionary of parsed lists
    parse = { 'enums'      : [],
              'commands'   : [],
              'feature'    : [],
              'extensions' : [] }

    # iterate over the 'registry' node
    for child in root:

        if child.tag == 'enums':
            parse['enums'].append(gl_parsexml_enums(child))

        elif child.tag == 'commands':
            parse['commands'].append(gl_parsexml_commands(child))

        elif child.tag == 'feature':
            parse['feature'].append(gl_parsexml_feature(child))

        elif child.tag == 'extensions':
            parse['extensions'].append(gl_parsexml_extensions(child))

    return (parse)


# ==========================
# SECTION: xml parser - enum
# ==========================

def gl_parsexml_enums(element: ET.Element):
    result = { 'name' : element.get('name'),
               'type' : element.get('type'),
               'enum' : [ ] }

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
    result = { 'ptype' : None,
               'name'  : None }

    if element.text:
        result['ptype'] = element.text.strip()

    for child in element:
        if child.tag == 'ptype':
            if result['ptype'] is not None:
                result['ptype'] += ' '
            result['ptype'] = f'{child.text.strip()}'.rstrip() 
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
                param['ptype'] = f'{child.text.strip()}'.rstrip() 
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

    require = element.findall('require')
    if require is not None:
        result['require'].append(gl_parsexml_require(require))

    return (result)


# ================================
# SECTION: xml parser - extensions
# ================================

def gl_parsexml_extensions(element: ET.Element):
    result = { 'name'      : element.get('name'),
               'supported' : element.get('supported'),
               'require'   : [ ] }

    require = element.findall('require')
    if require is not None:
        result['require'].append(gl_parsexml_require(require))

    return (result)


# ===============
# SECTION: loader
# ===============

def opengl_loader(parse: glParse):
    # open and read 'template.h'
    fstr = ''
    with open(f'{path}/template.h') as f:
        fstr = f.read()

    # Simple templates...

    # <<glld-author>>
    fstr = fstr.replace('<<glld-author>>', author)

    # <<glld-version>>
    fstr = fstr.replace('<<glld-version>>', version)

    # <<glld-licence>>
    fstr = fstr.replace('<<glld-licence>>', licence)

    # <<glld-profile>>
    fstr = fstr.replace('<<glld-gl-profile>>', gl_profile)

    # <<glld-glversion>>
    fstr = fstr.replace('<<glld-gl-version>>', gl_version)

    # <<glld-glesversion>>
    fstr = fstr.replace('<<glld-gl-es-version>>', gl_es_version)

    # <<glld-glscversion>>
    fstr = fstr.replace('<<glld-gl-sc-version>>', gl_es_version)

    # Advanced templates...
    
    # <<glld-gl-version-macros>>
    fstr = fstr.replace('<<glld-gl-version-macros>>', glld_gl_version_macros(parse))
    
    # <<glld-gl-extension-macros>>
    fstr = fstr.replace('<<glld-gl-extension-macros>>', glld_gl_extension_macros(parse))
    
    # <<glld-gl-enums>>
    fstr = fstr.replace('<<glld-gl-enums>>', glld_gl_enums(parse))
    
    # <<glld-gl-func-ptr>>
    fstr = fstr.replace('<<glld-gl-func-ptr>>', glld_gl_func_ptr(parse))
    
    # <<glld-gl-func-declr-0>>
    fstr = fstr.replace('<<glld-gl-func-declr-0>>', glld_gl_func_declr(parse, 0))
    
    # <<glld-gl-func-declr-1>>
    fstr = fstr.replace('<<glld-gl-func-declr-1>>', glld_gl_func_declr(parse, 1))
    
    # <<glld-gl-func-macros>>
    fstr = fstr.replace('<<glld-gl-func-macros>>', glld_gl_func_macros(parse))
    
    # <<glld-gl-func-nameaddr>>
    fstr = fstr.replace('<<glld-gl-func-nameaddr>>', glld_gl_func_nameaddr(parse))

    # open and write 'glld.h'
    with open('glld.h', 'w') as f:
        f.write(fstr)


# =================
# SECTION: template
# =================

def glld_gl_version_macros(parse: glParse):
    feats = parse.feats
    if feats is None:
        return (None)

    result = ''
    for feat in feats:
        result += f'# define {feat.name}\n'

    return (result.rstrip())


def glld_gl_extension_macros(parse: glParse):
    exts = parse.exts
    if exts is None:
        return (None)

    result = '# if defined (GLLD_EXTENSIONS)\n'
    for ext in exts:
        result += f'#  define {ext.name}\n'
    result += '# endif\n'

    return (result.rstrip())


def glld_gl_enums(parse: glParse):
    feats = parse.feats
    if feats is None:
        return (None)

    exts = parse.exts
    if exts is None:
        return (None)

    enums = parse.enums
    if enums is None:
        return (None)

    result = ''
    for feat in feats:
        reqs = feat.reqs
        # skip if this feature doesn't have any enums
        if len(reqs) == 1:
            if len(reqs[0].enums) == 0:
                continue

        result += f'# if defined ({feat.name})\n'
        for req in reqs:
            for e_str in req.enums:
                enum = next(enum for enum in enums if enum.name == e_str)
                result += f'#  define {enum.name} {enum.value}\n'
        result += '# endif\n'

    result += '#\n# if defined (GLLD_EXTENSIONS)\n'
    for ext in exts:
        reqs = ext.reqs
        # skip if this extension doesn't have any enums
        if len(reqs) == 1:
            if len(reqs[0].enums) == 0:
                continue

        result += f'#  if defined ({ext.name})\n'
        for req in reqs:
            for e_str in req.enums:
                enum = next(enum for enum in enums if enum.name == e_str)
                result += f'#   define {enum.name} {enum.value}\n'
        result += '#  endif\n'
    result += '# endif\n'

    return (result.rstrip())


def glld_gl_func_ptr(parse: glParse):
    feats = parse.feats
    if feats is None:
        return (None)

    exts = parse.exts
    if exts is None:
        return (None)

    cmds = parse.cmds
    if cmds is None:
        return (None)

    result = ''
    for feat in feats:
        reqs = feat.reqs
        # skip if this feature doesn't have any cmds
        if len(reqs) == 1:
            if len(reqs[0].cmds) == 0:
                continue

        result += f'\n/* {feat.name} */\n'
        for req in reqs:
            for c_str in req.cmds:
                cmd = next(cmd for cmd in cmds if cmd.name == c_str)

                func = f'typedef {cmd.proto.ptype}'
                func += f' (APIENTRYP PFN{cmd.name.upper()}PROC) ('
                # append parameters between braces
                for param in cmd.params:
                    func += f'{param.ptype}, '
                # remove trailing comma if exists...
                if func[-2:] == ', ':
                    func = func[:-2]
                # or insert 'void' keyword between braces
                else:
                    func += 'void'
                func += ');\n'

                # append 'func' to 'result'
                result += func

    for ext in exts:
        reqs = ext.reqs
        # skip if this extension doesn't have any enums
        if len(reqs) == 1:
            if len(reqs[0].cmds) == 0:
                continue

        for req in reqs:
            for c_str in req.cmds:
                cmd = next(cmd for cmd in cmds if cmd.name == c_str)

                func = f'typedef {cmd.proto.ptype}'
                func += f' (APIENTRYP PFN{cmd.name.upper()}PROC) ('
                # append parameters between braces
                for param in cmd.params:
                    func += f'{param.ptype}, '
                # remove trailing comma if exists...
                if func[-2:] == ', ':
                    func = func[:-2]
                # or insert 'void' keyword between braces
                else:
                    func += 'void'
                func += ');\n'
                
                # check if 'func' already exists in 'result'
                if result.rfind(func) != -1:
                    continue

                # append 'func' to 'result'
                result += func

    return (result.rstrip())


def glld_gl_func_declr(parse: glParse, mode):
    feats = parse.feats
    if feats is None:
        return (None)

    exts = parse.exts
    if exts is None:
        return (None)

    cmds = parse.cmds
    if cmds is None:
        return (None)

    result = ''
    for feat in feats:
        reqs = feat.reqs
        # skip if this feature doesn't have any cmds
        if len(reqs) == 1:
            if len(reqs[0].cmds) == 0:
                continue

        for req in reqs:
            for c_str in req.cmds:
                cmd = next(cmd for cmd in cmds if cmd.name == c_str)

                func = ''
                match (mode):
                    # mode: 0 - regular declarations
                    case (0):
                        func += f'PFN{cmd.name.upper()}PROC '
                        func += f'glld_{cmd.name};\n'
                        # check if 'func' already exists in 'result'
                        if result.rfind(func) != -1:
                            continue

                    # mode: 1 - extern declarations
                    case (1):
                        func += 'extern '
                        func += f'PFN{cmd.name.upper()}PROC '
                        func += f'glld_{cmd.name};\n'

                # append 'func' to 'result'
                result += func

    for ext in exts:
        reqs = ext.reqs
        # skip if this extension doesn't have any enums
        if len(reqs) == 1:
            if len(reqs[0].cmds) == 0:
                continue

        for req in reqs:
            for c_str in req.cmds:
                cmd = next(cmd for cmd in cmds if cmd.name == c_str)

                func = ''
                match (mode):
                    # mode: 0 - regular declarations
                    case (0):
                        func += f'PFN{cmd.name.upper()}PROC '
                        func += f'glld_{cmd.name};\n'
                        # check if 'func' already exists in 'result'
                        if result.rfind(func) != -1:
                            continue

                    # mode: 1 - extern declarations
                    case (1):
                        func += 'extern '
                        func += f'PFN{cmd.name.upper()}PROC '
                        func += f'glld_{cmd.name};\n'

                # append 'func' to 'result'
                result += func

    return (result.rstrip())


def glld_gl_func_macros(parse: glParse):
    feats = parse.feats
    if feats is None:
        return (None)

    exts = parse.exts
    if exts is None:
        return (None)

    cmds = parse.cmds
    if cmds is None:
        return (None)

    result = ''
    for feat in feats:
        reqs = feat.reqs
        # skip if this feature doesn't have any cmds
        if len(reqs) == 1:
            if len(reqs[0].cmds) == 0:
                continue

        result += f'# if defined ({feat.name})\n'
        for req in reqs:
            for c_str in req.cmds:
                cmd = next(cmd for cmd in cmds if cmd.name == c_str)

                func  =  '#  define '
                func += f'{cmd.name} '
                func += f'glld_{cmd.name}\n'

                # append 'func' to 'result'
                result += func
        result += '# endif\n'

    result += '#\n# if defined (GLLD_EXTENSIONS)\n'
    for ext in exts:
        reqs = ext.reqs
        # skip if this extension doesn't have any enums
        if len(reqs) == 1:
            if len(reqs[0].cmds) == 0:
                continue

        result += f'#  if defined ({feat.name})\n'
        for req in reqs:
            for c_str in req.cmds:
                cmd = next(cmd for cmd in cmds if cmd.name == c_str)

                func  =  '#   define '
                func += f'{cmd.name} '
                func += f'glld_{cmd.name}\n'

                # append 'func' to 'result'
                result += func
        result += '#  endif\n'
    result += '# endif\n'

    return (result.rstrip())


def glld_gl_func_nameaddr(parse: glParse):
    feats = parse.feats
    if feats is None:
        return (None)

    exts = parse.exts
    if exts is None:
        return (None)

    cmds = parse.cmds
    if cmds is None:
        return (None)

    result = ''
    for feat in feats:
        reqs = feat.reqs
        # skip if this feature doesn't have any cmds
        if len(reqs) == 1:
            if len(reqs[0].cmds) == 0:
                continue

        for req in reqs:
            for c_str in req.cmds:
                cmd = next(cmd for cmd in cmds if cmd.name == c_str)

                name = f'   {{ \"{cmd.name}\", (void **) &glld_{cmd.name} }},\n'
                # check if 'name' already exist in 'result'
                if result.rfind(name) != -1:
                    continue

                # append 'name' to 'result'
                result += name

    for ext in exts:
        reqs = ext.reqs
        # skip if this extension doesn't have any enums
        if len(reqs) == 1:
            if len(reqs[0].cmds) == 0:
                continue

        for req in reqs:
            for c_str in req.cmds:
                cmd = next(cmd for cmd in cmds if cmd.name == c_str)

                name = f'   {{ \"{cmd.name}\", (void **) &glld_{cmd.name} }},\n'
                # check if 'name' already exist in 'result'
                if result.rfind(name) != -1:
                    continue

                # append 'name' to 'result'
                result += name

    return (result.rstrip())

# =============
# SECTION: main
# =============

if __name__ == '__main__':
    try:
        tree = gl_loadxml(f'{path}/xml/gl.xml')
        parse = gl_parsexml(tree)
        opengl_loader(parse)
    except Exception as err:
        print(f'{__file__}: {err}')
        sys.exit(1)
