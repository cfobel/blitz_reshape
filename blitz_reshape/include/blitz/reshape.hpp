#ifndef ___BLITZ_TESTBED__HPP___
#define ___BLITZ_TESTBED__HPP___

#include <stdexcept>
#include <iostream>
#include <blitz/array.h>
#include <Formatter.hpp>


namespace blitz {

template <typename T, int R1, int R2>
Array<T, R2> reshape(Array<T, R1> A, TinyVector<int, R2> new_shape) {
    int total_length = product(A.shape());
    int min_shape_value = min(new_shape);
    if(min_shape_value < -1) {
        throw std::runtime_error(Formatter() << "Invalid extent value: "
                                 << min_shape_value);
    }

    if(count(new_shape == 0)) {
        throw std::runtime_error("Extent values must be greater than zero.  "
                                 "(Perhaps you mean an extent of 1?)");
    }

    int infer_extent_count = count(new_shape == -1);
    if(infer_extent_count > 1) {
        throw std::runtime_error("Only one shape extent may be inferred "
                                 "(i.e., only one shape extent may be equal "
                                 "to -1).");
    }

    int new_total_length = product(new_shape);
    if(infer_extent_count > 0) {
        new_total_length *= -1;
        int remainder = total_length % new_total_length;
        int inferred_extent = total_length / new_total_length;
        if(remainder != 0) {
            throw std::runtime_error(Formatter()
                    << "Could not infer an extent to convert shape from "
                    << A.shape() << " to " << new_shape << "(i.e., the total "
                    "length of " << A.shape() << " does not divide evenly by "
                    "the product of the positive extents in " << new_shape
                    << ".");
        }
        for(int& i : new_shape) {
            if(i == -1) {
                i = inferred_extent;
                new_total_length *= i;
            }
        }
    }

    if(new_total_length != total_length) {
        throw std::runtime_error(Formatter() << "Total size must remain the "
                                 "same. (" << new_total_length << " != " <<
                                 total_length << ")");
    }

    return Array<T, R2>(A.data(), new_shape, neverDeleteData);
}

template <typename T, int R1, int R2>
void reshape_test(Array<T, R1> A, TinyVector<int, R2> new_shape) {
    /*
     * A wrapper around the `reshape` function to allow for testing without
     * handling the return value.  This allows Cython to call the function.
     */
    Array<T, R2> B = reshape(A, new_shape);
    std::cout << std::endl;
    std::cout << "Original shape: " << A.shape() << " (" << product(A.shape())
              << ")" << std::endl;
    std::cout << "New shape:      " << B.shape() << " (" << product(B.shape())
              << ")" << std::endl;
}

} // namespace blitz

#endif
