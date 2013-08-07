import os


def get_include():
    import blitz_reshape
    """
    Return the directory that contains the Blitz++ reshape \\*.hpp header
    files.

    Extension modules that need to compile against Blitz++ reshape should use
    this function to locate the appropriate include directory.

    Notes
    -----
    When using ``distutils``, for example in ``setup.py``.
    ::

        import blitz_reshape
        ...
        Extension('extension_name', ...
                include_dirs=[blitz_reshape.get_include()])
        ...

    """
    d = os.path.join(os.path.dirname(blitz_reshape.__file__), 'include')
    return d
