#pragma once
#include "../core/core.hpp"

template <typename T> class Compressor {
    vector<T> vals;

public:
    // コンストラクタ
    // O(NlogN)
    Compressor(const vector<vector<T>> &data) {
        for(int i = 0; i < data.size(); i++) {
            copy(data[i].begin(), data[i].end(), back_inserter(vals));
        }
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
    }
    Compressor(const vector<T> &data) : vals(data) {
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
    }

    // 圧縮前の値 value に対応する圧縮後の値 index を返す
    // O(logN)
    int get_index(T value) {
        auto lb = lower_bound(vals.begin(), vals.end(), value);
        assert(lb != vals.end() && *lb == value);
        return (int)(lb - vals.begin());
    }

    // 圧縮後の値 index に対応する圧縮前の値 value を返す
    // O(1)
    T get_value(size_t index) { return vals[index]; }

    // 圧縮後の配列のサイズを返す
    // O(1)
    int size() const { return vals.size(); }
};
