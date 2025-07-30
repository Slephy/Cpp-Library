#pragma once
#include "../core/core.hpp"
// (path compression) + (union by size)
// 参考 AtCoder Library
// == ACLからの変更点 ==
// group_num() を追加
// size関数をsize_of_group関数に改名
// groups() の返り値が昇順にソート済みであることを保証
class DSU {
    int n;
    int _group_num;
    vector<int> parent_or_size;

public:
    explicit DSU(size_t n) : n(n), _group_num(n), parent_or_size(n, -1) {}

    // 頂点u, vを結合し、それらの新たなリーダーを返す
    // O(α(N))
    int merge(int u, int v) {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        u = leader(u);
        v = leader(v);
        if(u == v) return u;
        if(-parent_or_size[u] < -parent_or_size[v]) swap(u, v);  // make size(u) >= size(v)
        parent_or_size[u] += parent_or_size[v];
        parent_or_size[v] = u;
        _group_num--;
        return u;
    }

    // 頂点u, vが同じ連結成分に属するかを判定する
    // O(α(N))
    bool same(int u, int v) {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        return leader(u) == leader(v);
    }

    // 頂点vが属する連結成分の代表を返す
    // O(α(N))
    int leader(int v) {
        assert(0 <= v && v < n);
        if(parent_or_size[v] < 0) return v;
        else return parent_or_size[v] = leader(parent_or_size[v]);
    }

    // 頂点vが属する連結成分のサイズを返す
    // O(α(N))
    int size_of_group(int v) {
        assert(0 <= v && v < n);
        return -parent_or_size[leader(v)];
    }

    // 連結成分の個数を返す
    // 返り値は groups().size()に等しい
    // O(1)
    int group_num() { return _group_num; }

    // 連結成分ごとの頂点情報を返す
    // 1次元目、2次元目ともに昇順でソート済み
    // O(N)
    vector<vector<int>> groups() {
        vector<vector<int>> result;
        // 頂点iをリーダーとする連結成分がresultに格納されるときのインデックス
        vector<int> resultIndex(n, -1);

        for(int i = 0; i < n; i++) {
            int ld = leader(i);
            if(resultIndex[ld] == -1) {  // resultIndex が未定のとき
                resultIndex[ld] = result.size();
                result.emplace_back();
                result.back().reserve(size_of_group(ld));
            }
            result[resultIndex[ld]].emplace_back(i);
        }
        return result;
    }
};
