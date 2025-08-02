#pragma once
#include "../concepts/modint_concept.hpp"
#include "../core/core.hpp"
#include "./int_power.hpp"
#include "./mod_power.hpp"

// modint
template <IsModint T, integral U> T power(T val, U exp) { return val.pow(exp); }
template <IsModint T, IsModint U> T power(T val, U exp) { return val.pow(exp.val()); }

// floating point
template <class T, class U>
    requires(!IsModint<T> && floating_point<T>)
T power(T val, U exp) {
    return pow(val, exp);
}
