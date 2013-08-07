#!/usr/bin/env python

import sys
import os
from distutils.core import setup, Extension

from Cython.Build import cythonize
import blitz
import blitz_reshape

include_dirs = [blitz.get_include(), blitz.get_cython_include(),
                blitz_reshape.get_include()]
sys.path += include_dirs

blitz_testbed = Extension('blitz_reshape.tests.BlitzTestbed',
                          ['blitz_reshape/tests/BlitzTestbed.pyx'],
                          extra_objects=[os.path.join(blitz.get_lib(),
                                                      'libblitz.a')],
                          include_dirs=include_dirs, language='c++',
                          extra_compile_args=['-O3', '-std=c++0x'])

setup(name = "blitz_reshape",
    version = "0.0.1",
    description = "Blitz++ reshape",
    keywords = "Blitz++ blitz reshape",
    author = "Christian Fobel",
    url = "https://github.com/cfobel/blitz_reshape",
    license = "GPL",
    long_description = """""",
    packages = ['blitz_reshape'],
    package_data={'blitz_reshape': ['include/*.*', 'include/blitz/*.*',
                                    'cython_include/*.*']},
    ext_modules=cythonize([blitz_testbed])
)
