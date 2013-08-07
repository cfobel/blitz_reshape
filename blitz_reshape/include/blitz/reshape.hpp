#ifndef ___BLITZ_TESTBED__HPP___
#define ___BLITZ_TESTBED__HPP___

#include <stdexcept>
#include <iostream>
#include <blitz/array.h>
#include <blitz/tinyvec-et.h>
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
            }
        }
    }
    return Array<T, R2>(A.data(), new_shape, neverDeleteData);
}

} // namespace blitz

#endif
