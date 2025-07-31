#pragma once
#include "../core/core.hpp"
#include "./lis.hpp"
// 順列（より一般には重複する要素を含まない配列）のLCSを計算する
// O(NlogN)
template <class T> ll calculate_perm_LCS(const vector<T> &a, const vector<T> &b) {
    map<T, ll> idx_in_a;
    for(int i = 0; i < a.size(); i++) idx_in_a[a[i]] = i;

    vector<T> comp_b;
    for(int i = 0; i < b.size(); i++) {
        if(idx_in_a.count(b[i])) comp_b.push_back(idx_in_a[b[i]]);
    }
    return LIS(comp_b).size();
}
