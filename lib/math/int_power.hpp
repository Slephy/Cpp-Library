#pragma once
#include "../core/core.hpp"

template <typename T> T power(T base, T exponent) {
    assert(exponent >= 0);
    T ret = 1;
    while(exponent > 0) {
        if(exponent & 1) ret = ret * base;
        base = base * base;
        exponent >>= 1;
    }
    return ret;
}
