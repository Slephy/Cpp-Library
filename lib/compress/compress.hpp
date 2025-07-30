#pragma once
#include "../core/core.hpp"

// O(NlogN)
// 引数で与えられた配列を in-place に座標圧縮する
// 返り値の vals は、vals[i] = (i に圧縮された値の元の値) を表す配列
template <class T> vector<T> compress(vector<T> &vec) {
    auto vals = vec;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    for(int i = 0; i < vec.size(); i++) {
        vec[i] = lower_bound(vals.begin(), vals.end(), vec[i]) - vals.begin();
    }
    return vals;
}
