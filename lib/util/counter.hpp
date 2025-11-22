#pragma once
#include "../core/core.hpp"
#include "./count_frequency.hpp"

// 配列に登場する要素の頻度を返すクラス
template <class T> class Counter {
    vector<pair<T, ll>> counts;

public:
    Counter() = default;
    Counter(vector<T> vals) { counts = move(count_frequency(vals)); }

    ll get_count(T val) {
        auto lb = ranges::lower_bound(counts, pair<T, ll>{val, -1});
        if(lb != counts.end() && lb->first == val) return lb->second;
        else return 0;
    }
};
