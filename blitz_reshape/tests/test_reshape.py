from .BlitzTestbed import test_reshape


def test_too_many_inferred_extents():
    try:
        # This test should throw an exception, since there is more than one
        # new-shape extent set to -1.
        test_reshape(a_extents=(4, 3), b_extents=(-1, -1))
        raise AssertionError
    except RuntimeError:
        # The exception was thrown, as expected.
        pass


def test_size_mismatch():
    try:
        # This test should throw an exception, since the new shape is too
        # small.
        test_reshape(a_extents=(4, 3), b_extents=(1, 1))
        raise AssertionError
    except RuntimeError:
        # The exception was thrown, as expected.
        pass


def test_same_rank():
    test_reshape(a_extents=(4, 3), b_extents=(2, 6))


def test_inferred_extent():
    test_reshape(a_extents=(8, 3), b_extents=(2, -1))
    test_reshape(a_extents=(8, 3), b_extents=(-1, 4))
