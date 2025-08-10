#pragma once
#include "../core/core.hpp"

// return sorted frequency map
template <class T> [[nodiscard]] vector<pair<T, ll>> count_frequency(vector<T> v) {
    ranges::sort(v);
    vector<pair<T, ll>> ret;
    for(int i = 0, cnt = 0; i < v.size(); i++) {
        cnt++;
        if(i == (int)v.size() - 1 || v[i] != v[i + 1]) {
            ret.emplace_back(v[i], cnt);
            cnt = 0;
        }
    }
    return ret;
}
