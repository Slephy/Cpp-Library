#pragma once
#include "../core/core.hpp"
template <class T> inline auto vector5(size_t i, size_t j, size_t k, size_t l, size_t m, const T &init = T()) {
    return vector(i, vector(j, vector(k, vector(l, vector<T>(m, init)))));
}
template <class T>
inline auto vector6(size_t i, size_t j, size_t k, size_t l, size_t m, size_t n, const T &init = T()) {
    return vector(i, vector(j, vector(k, vector(l, vector(m, vector<T>(n, init))))));
}
template <class T>
inline auto vector7(size_t i, size_t j, size_t k, size_t l, size_t m, size_t n, size_t o, const T &init = T()) {
    return vector(i, vector(j, vector(k, vector(l, vector(m, vector(n, vector<T>(o, init)))))));
}
template <class T>
inline auto vector8(size_t i, size_t j, size_t k, size_t l, size_t m, size_t n, size_t o, size_t p,
                    const T &init = T()) {
    return vector(i, vector(j, vector(k, vector(l, vector(m, vector(n, vector(o, vector<T>(p, init))))))));
}
