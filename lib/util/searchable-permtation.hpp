#pragma once
#include "../core/core.hpp"

// 逆引き可能な順列
// 0 から n-1 までの順列を格納する
class SearchablePermutation{
private:
    vector<int> val;
    vector<int> idx; // idx[v] := (val内でのvのインデックス)
    size_t n; // 順列の要素数


public:
    SearchablePermutation(const vector<int> &val) : val(val), idx(val.size(), -1), n(val.size()){
        vector<bool> emplaced(n, false);
        for(int i = 0; i < val.size(); i++){
            assert(0 <= val[i] && val[i] < n);
            assert(!emplaced[val[i]]); // 要素が重複してはいけない
            idx[val[i]] = i;
            emplaced[val[i]] = true;
        }
    }
    // {0, 1, 2, ... , n-1} で初期化
    SearchablePermutation(size_t n) : val(n), idx(n), n(n) {
        iota(val.begin(), val.end(), 0);
        iota(idx.begin(), idx.end(), 0);
    }

    // O(1)
    int size() const {
        return n;
    }

    // O(1)
    int get_idx(int val) const {
        return idx[val];
    }

    // O(1)
    int operator[](size_t idx) const {
        return val[idx];
    }

    // O(1)
    void swap_by_value(int val1, int val2){
        int idx1 = get_idx(val1);
        int idx2 = get_idx(val2);
        std::swap(val[idx1], val[idx2]);
        std::swap(idx[val1], idx[val2]);
    }

    // O(1)
    void swap_by_index(int idx1, int idx2){
        int val1 = val[idx1];
        int val2 = val[idx2];
        std::swap(val[idx1], val[idx2]);
        std::swap(idx[val1], idx[val2]);
    }

    friend ostream& operator <<(ostream &o, const SearchablePermutation &sv){o << sv.val; return o;}
};
