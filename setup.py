#!/usr/bin/env python

from distutils.core import setup

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
                                    'cython_include/*.*']}
)
