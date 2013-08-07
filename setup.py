#!/usr/bin/env python

import sys
import os
from distutils.core import setup, Extension

from Cython.Build import cythonize
import blitz as b

include_dirs = [b.get_include(), b.get_cython_include()]
sys.path += include_dirs

blitz_testbed = Extension('blitz_reshape.tests.BlitzTestbed',
                          ['blitz_reshape/tests/BlitzTestbed.pyx'],
                          extra_objects=[os.path.join(b.get_lib(),
                                                      'libblitz.a')],
                          include_dirs=include_dirs, language='c++')

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
