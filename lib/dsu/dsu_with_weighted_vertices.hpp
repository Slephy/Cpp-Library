#pragma once
#include "../core/core.hpp"
// (path compression) + (union by size)
// 参考 AtCoder Library
// == DSUからの変更点 ==
// 頂点に重みをもたせて、連結成分ごとの重みの和を weight_sum() で求めることができる
// size関数をsize_of_group関数に改名
// 和を求める際の二項演算opはテンプレート引数で指定する
template <class WeightType, void (*op)(WeightType &, WeightType &)> class DSUWithWeightedVertices {
    int n;
    int _group_num;
    vector<int> parent_or_size;
    vector<WeightType> weight;
    vector<WeightType> weightSum;

public:
    explicit DSUWithWeightedVertices(size_t n)
        : n(n), _group_num(n), parent_or_size(n, -1), weight(n, WeightType()), weightSum(n, WeightType()) {}
    explicit DSUWithWeightedVertices(const vector<WeightType> &weight)
        : n(weight.size()), _group_num(n), parent_or_size(n, -1), weight(weight), weightSum(weight) {}


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
        op(weightSum[u], weightSum[v]);  // weightSum[u] = weightSum[u] + weightSum[v]
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

    // 頂点vが属する連結成分の重みの和を返す
    // O(α(N))
    const WeightType &weight_sum(int v) {
        assert(0 <= v && v < n);
        return weightSum[leader(v)];
    }

    // // 頂点vの重みにwを加える
    // // O(α(N))
    // void add_weight(int v, const WeightType &w){
    //     assert(0 <= v && v < n);
    //     weight[v] += w;
    //     weightSum[leader(v)] += w;
    // }

    // // 頂点vの重みをwに変更する
    // // O(α(N))
    // void set_weight(int v, const WeightType &w){
    //     assert(0 <= v && v < n);
    //     add_weight(v, w - weight[v]);
    // }

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

// merge_weight_to_l は l + r を l に格納する関数
template <class WeightType> struct DSU_add {
    static void merge_weight_to_l(WeightType &l, WeightType &r) { l = l + r; };
    using Type = struct DSUWithWeightedVertices<WeightType, merge_weight_to_l>;
};
template <class WeightType> struct DSU_map_add {
    static void merge_weight_to_l(WeightType &l, WeightType &r) {
        if(l.size() < r.size()) swap(l, r);
        // ✅ l.size() >= r.size()
        for(auto &[key, val] : r) l[key] += val;
    };
    using Type = struct DSUWithWeightedVertices<WeightType, merge_weight_to_l>;
};
