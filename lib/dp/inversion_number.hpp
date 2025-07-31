#pragma once
#include "../binary_indexed_tree/bit.hpp"
#include "../core/core.hpp"
// 予め配列を圧縮する、もしくは要素の最大値を入力する必要あり
template <class T> ll inversion_number(const vector<T> &v, ll val_MAX = -1) {
    ll ret = 0;
    assert(val_MAX >= -1);
    val_MAX = (val_MAX == -1) ? v.size() : val_MAX + 1;
    BIT<ll> bit(val_MAX);
    for(int i = 0; i < v.size(); i++) {
        ret += bit.sum(v[i] + 1, val_MAX);
        bit.add(v[i], 1);
    }
    return ret;
}
