APPNAME = 'decision-taking-tools'
VERSION = '0.0.1'

import sys
import os
import re

subdirs = ['MDMA']

top = '.'
out = 'build'


def options(opt):
    
    opt.load('compiler_cxx python')
    opt.add_option("-g", "--debug", action="store_true", default=False,
                   help="configures the C++ compiler for a debugging build")
    opt.add_option("-O", "--optim", action="store_true", default=False,
                   help="configures the C++ compiler for maximum optimization level")


def configure(conf):
    
    conf.load('compiler_cxx')
    conf.env.append_value('CXXFLAGS', ['-std=c++11', '-Wall', '-pedantic'])
    if conf.options.debug and conf.options.optim:
        conf.fatal('--debug and --optim options are mutually exclusive')
    elif conf.options.debug :
        conf.env.append_value('CXXFLAGS', ['-g3', '-O0'])
        conf.env.append_value('LDFLAGS', '-g')
    elif conf.options.optim :
        conf.env.append_value('CXXFLAGS', ['-Ofast', '-march=native', '-flto'])
    
    conf.load('swig')
    conf.check_swig_version((4,0,0))
    conf.env.append_value('SWIGFLAGS', ['-c++', '-python', '-fcompact', '-fvirtual', '-modern', '-Wall'])
    
    conf.load('python')
    conf.check_python_version((3,0,0))
    conf.check_python_headers()
    
    # conf.recurse(subdirs) # if any sub-directory has a wscript, its configuration is run as well


def build(bld):
    
    for m in subdirs :
         
        srcs = bld.path.ant_glob(m + '/src/*.cpp')
        interface = bld.path.find_node(m + '/include/_' + m + '.i')
        includes = [bld.path.find_dir(m + '/include')]
        bld(features='pyext cxx cxxshlib',
            source=[interface, srcs],
            includes=includes,
            target='py/_' + m)
    
    bld.add_group() # forces all processes to sync before continuing
    for m in subdirs :
        
        bld(features='subst',
            source=m + '/include/' + m + '.py',
            target='py/' + m + '.py',
            is_copy=True)
