from cython.operator cimport dereference as deref, preincrement as inc
from blitz cimport (Array, TinyVector, One, Two, Three)

def __main__():
    cdef TinyVector[unsigned int, Two] *extents = (
        new TinyVector[unsigned int, Two](3, 5))
    cdef int i
    for i in xrange(2):
        print extents.data()[i]
