#pragma once
#include "../binary_indexed_tree/bit.hpp"
#include "../core/core.hpp"
// N回の点追加クエリの後で、Q回の矩形クエリを処理する
// PosType: 座標の型(int, double等)
// WeightType: 重みの型
// @need BIT
template <totally_ordered PosType, class WeightType> class StaticRectangleSum {
public:
    StaticRectangleSum() {}
    StaticRectangleSum(const vector<tuple<PosType, PosType, WeightType>> &points,
                       const vector<tuple<PosType, PosType, PosType, PosType>> &queries)
        : points(points), queries(queries) {}

    // 点(x, y) に重み w を追加
    void add_point(PosType x, PosType y, WeightType w) { points.emplace_back(x, y, w); }

    // [l, r) × [d, u) の範囲の総和を求めるクエリを追加
    void add_query(PosType l, PosType d, PosType r, PosType u) { queries.emplace_back(l, d, r, u); }

    // クエリを解く
    // 返り値: 各クエリの答え（クエリの挿入順）
    // O(NlogN + QlogQ)
    vector<WeightType> solve() {
        const int n = points.size();
        const int q = queries.size();

        // Y軸を座標圧縮
        vector<PosType> ys;
        ys.reserve(n + 2 * q);
        for(const auto &[x, y, w] : points) {
            ys.emplace_back(y);
        }
        for(const auto &[l, d, r, u] : queries) {
            ys.emplace_back(d);
            ys.emplace_back(u);
        }
        ranges::sort(ys);
        ys.erase(unique(ys.begin(), ys.end()), ys.end());

        // ソート
        ranges::sort(points, [&](const auto &a, const auto &b) { return get<0>(a) < get<0>(b); });
        vector<pair<PosType, int>> qs;
        for(int i = 0; i < q; i++) {
            const auto &[l, d, r, u] = queries[i];
            qs.emplace_back(l, i);
            qs.emplace_back(r, i + q);
        }
        ranges::sort(qs);

        // クエリ処理
        vector<WeightType> ans(q, WeightType(0));
        BIT<WeightType> bit(ys.size());
        auto get_y = [&](ll y) -> ll { return ranges::lower_bound(ys, y) - ys.begin(); };
        for(int iter = 0; auto [x, qid] : qs) {
            while(iter < points.size() && get<0>(points[iter]) < x) {
                auto [_, y, w] = points[iter];
                bit.add(get_y(y), w);
                iter++;
            }

            bool is_left = qid < q;
            if(qid >= q) qid -= q;
            auto [l, d, r, u] = queries[qid];
            auto sum = bit.sum(get_y(d), get_y(u));
            ans[qid] += is_left ? -sum : sum;
        }
        return ans;
    }

private:
    vector<tuple<PosType, PosType, WeightType>> points;
    vector<tuple<PosType, PosType, PosType, PosType>> queries;
};
