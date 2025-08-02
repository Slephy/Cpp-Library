#pragma once
#include "../concepts/modint_concept.hpp"
#include "../core/core.hpp"

// modint
template <IsModint T, integral U> T power(T val, U exp) { return val.pow(exp); }
template <IsModint T, IsModint U> T power(T val, U exp) { return val.pow(exp.val()); }

// integral
template <class T, integral U>
    requires(!IsModint<T> && integral<T>)
T power(T val, U exp) {
    if(exp < 0) {
        throw invalid_argument("Negative exponent not supported for integral types.");
    }
    T result = 1;
    while(true) {
        if(exp % 2 == 1) result *= val;
        exp /= 2;
        if(exp > 0) val *= val;
        else break;
    }
    return result;
}

// floating point
template <class T, class U>
    requires(!IsModint<T> && floating_point<T>)
T power(T val, U exp) {
    return pow(val, exp);
}
