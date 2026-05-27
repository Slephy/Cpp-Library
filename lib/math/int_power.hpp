#pragma once
#include "../concepts/modint_concept.hpp"
#include "../core/core.hpp"

// integral
template <class T, integral U>
    requires(!IsModint<T> && integral<T>)
ll power(T val, U exp) {
    if(exp < 0) throw invalid_argument("Negative exponent not supported for integral types.");

    ll result = 1, tmp = val;
    while(true) {
        if(exp % 2 == 1) result *= tmp;
        exp /= 2;
        if(exp > 0) tmp *= tmp;
        else break;
    }
    return result;
}
