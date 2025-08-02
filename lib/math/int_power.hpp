#pragma once
#include "../concepts/modint_concept.hpp"
#include "../core/core.hpp"

// integral
template <class T, integral U>
    requires(!IsModint<T> && integral<T>)
T power(T val, U exp) {
    if(exp < 0) throw invalid_argument("Negative exponent not supported for integral types.");

    T result = 1;
    while(true) {
        if(exp % 2 == 1) result *= val;
        exp /= 2;
        if(exp > 0) val *= val;
        else break;
    }
    return result;
}
