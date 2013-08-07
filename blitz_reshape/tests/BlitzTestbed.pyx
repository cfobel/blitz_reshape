from cython.operator cimport dereference as deref, preincrement as inc
import numpy as np
from blitz cimport (Array, TinyVector, One, Two, Three)


ctypedef Array[int, One] array_1d_t
ctypedef Array[int, Two] array_2d_t
ctypedef Array[int, Three] array_3d_t
ctypedef TinyVector[int, One] tiny_vector_1_t
ctypedef TinyVector[int, Two] tiny_vector_2_t
ctypedef TinyVector[int, Three] tiny_vector_3_t


cdef extern from "blitz/reshape.hpp" namespace "blitz":
    void reshape_test(array_2d_t A, tiny_vector_2_t new_shape) except +


def test_reshape(a_extents, b_extents):
    cdef tiny_vector_2_t *new_shape = (
        new tiny_vector_2_t(b_extents[0], b_extents[1]))

    cdef array_2d_t *A = new array_2d_t(a_extents[0], a_extents[1])
    cdef int [:] A_view = <int [:np.prod(a_extents)]> (<int *>A.data())

    cdef int i
    for i in xrange(A_view.shape[0]):
        A_view[i] = i
    reshape_test(deref(A), deref(new_shape))
