#pragma once
#include "../core/core.hpp"
// N回の頂点追加クエリとQ回の矩形クエリをごちゃまぜに処理する
// PosType: 座標の型(int, double等)
// WeightType: 重みの型
// @need StaticRectangleSum
template <totally_ordered PosType, class WeightType> class PointAddRectangleSum {
    using Point_t = tuple<PosType, PosType, WeightType>;
    using Query_t = tuple<PosType, PosType, PosType, PosType>;

public:
    PointAddRectangleSum() {}
    PointAddRectangleSum(const vector<variant<Point_t, Query_t>> &queries) : queries(queries) {}

    // 点(x, y) に重み w を追加
    void add_point(PosType x, PosType y, WeightType w) { queries.emplace_back(x, y, w); }

    // [l, r) × [d, u) の範囲の総和を求めるクエリを追加
    void add_query(PosType l, PosType d, PosType r, PosType u) { queries.emplace_back(l, d, r, u); }

    // O(N logN logQ)
    vector<WeightType> solve() {
        auto is_sum_query = [&](const auto &tp) -> bool { return holds_alternative<tuple<ll, ll, ll, ll>>(tp); };

        vector<int> rev(queries.size());  // rev[i] = i番目のクエリが何番目のsum_queryか
        vector<ll> ans;
        {
            int iter = 0;
            for(int i = 0; i < queries.size(); i++) {
                if(is_sum_query(queries[i])) {
                    rev[i] = iter++;
                }
            }
            ans.resize(iter);
        }

        // 分割統治
        queue<pair<ll, ll>> que;
        que.emplace(0, queries.size());
        while(!que.empty()) {
            auto [l, r] = que.front();
            que.pop();
            if(r - l <= 1) continue;
            ll m = (l + r) / 2;
            que.emplace(l, m);
            que.emplace(m, r);

            // [l, m) の頂点追加から [m, r) の矩形クエリへの寄与を計算
            vector<tuple<ll, ll, ll>> points;
            vector<tuple<ll, ll, ll, ll>> sum_queries;
            for(int i = l; i < m; i++) {
                if(!is_sum_query(queries[i])) {
                    points.push_back(get<tuple<ll, ll, ll>>(queries[i]));
                }
            }
            for(int i = m; i < r; i++) {
                if(is_sum_query(queries[i])) {
                    sum_queries.push_back(get<tuple<ll, ll, ll, ll>>(queries[i]));
                }
            }

            StaticRectangleSum<ll, ll> srs(points, sum_queries);
            auto res = srs.solve();
            for(int i = m, iter = 0; i < r; i++) {
                if(is_sum_query(queries[i])) {
                    ans[rev[i]] += res[iter];
                    iter++;
                }
            }
        }
        return ans;
    }

private:
    vector<variant<Point_t, Query_t>> queries;
};
