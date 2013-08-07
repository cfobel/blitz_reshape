blitz_reshape
=============

This package wraps a header implementing a `reshape` function for Blitz++[1]
C++ `Array` classes in a Python package to make it easy to install.

# Usage #

From the command-line, the `include` or `lib` paths for the installed package
can be obtained by running:

    python -c "import blitz; print blitz_reshape.get_include()"

[1] https://github.com/syntheticpp/blitz
