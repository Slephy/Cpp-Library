#pragma once
#include "../core/core.hpp"
// @need p is permutation of [0..n)
// p[i] は返り値配列の i 番目に来る要素が、元の配列の p[i] 番目の要素であることを指す。
template <class T> [[nodiscard]] vector<T> apply_permutation(const vector<T> &v, const vector<int> &p) {
    vector<T> res(v.size());
    for(int i = 0; i < v.size(); i++) res[i] = v[p[i]];
    return res;
}
