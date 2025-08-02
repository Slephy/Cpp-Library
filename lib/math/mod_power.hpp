#pragma once
#include "../core/core.hpp"

// return integer in [0, mod)
template <integral T, integral U, integral S> T power(T val, U exp, S mod) {
    if(exp < 0) throw invalid_argument("Negative exponent not supported.");
    if(mod <= 1) throw invalid_argument("Modulus must be greater than 1.");

    T result = 1;
    val %= mod;
    while(true) {
        if(exp % 2 == 1) result = (result * val) % mod;
        exp /= 2;
        if(exp > 0) val = (val * val) % mod;
        else break;
    }
    if(result < 0) result += mod;
    return result;
}
