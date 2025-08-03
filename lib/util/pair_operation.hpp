#pragma once
#include "../core/core.hpp"
template <class T, class S> pair<T, S> operator+(const pair<T, S> &x, const pair<T, S> &y) {
    return pair<T, S>(x.first + y.first, x.second + y.second);
}
template <class T, class S> pair<T, S> operator-(const pair<T, S> &x, const pair<T, S> &y) {
    return pair<T, S>(x.first - y.first, x.second - y.second);
}
template <class T, class S> pair<T, S> operator+=(pair<T, S> &l, const pair<T, S> &r) { return l = l + r; }
template <class T, class S> pair<T, S> operator-=(pair<T, S> &l, const pair<T, S> &r) { return l = l - r; }
