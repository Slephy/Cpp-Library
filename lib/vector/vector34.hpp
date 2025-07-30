#pragma once
#include "../core/core.hpp"
template <class T> inline auto vector3(size_t i, size_t j, size_t k, const T &init = T()) {
    return vector(i, vector(j, vector<T>(k, init)));
}
template <class T> inline auto vector4(size_t i, size_t j, size_t k, size_t l, const T &init = T()) {
    return vector(i, vector(j, vector(k, vector<T>(l, init))));
}
