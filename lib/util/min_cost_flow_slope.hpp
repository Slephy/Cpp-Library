#pragma once
#include "../core/core.hpp"
// slope関数の返り値を扱う関数
// flow だけ流すためのコストの最小値を返す
// slope は slope関数の返り値
// O(log(|slope|))
template <class Cap, class Cost> Cost get_cost(const vector<pair<Cap, Cost>> &slope, Cap flow) {
    Cap flow_max = slope.back().first;
    assert(0 <= flow && flow <= flow_max);

    // flow が slope のどの区間に入るかを二分探索で求める
    // slope[ub-1].first <= flow < slope[ub].first
    int ub =
        upper_bound(slope.begin(), slope.end(), pair<Cap, Cost>(flow, numeric_limits<Cost>::max())) - slope.begin();

    if(ub == slope.size()) {  // flow == flow_maxのとき
        return slope.back().second;
    }

    // 線形補間
    const auto &[cap1, cost1] = slope[ub - 1];
    const auto &[cap2, cost2] = slope[ub];
    Cost d = (cost2 - cost1) / (cap2 - cap1);
    Cost cost = cost1 + d * (flow - cap1);
    return cost;
}


// slope関数の返り値（折線）を展開する関数
// slope は slope関数の返り値
// O(flow_max)
// ⚠️ Cap は整数型とすること
template <class Cap, class Cost> [[nodiscard]] vector<Cost> expand_slope(const vector<pair<Cap, Cost>> &slope) {
    assert(!slope.empty());
    ll flow_max = slope.back().first;
    assert(flow_max < (ll)1e8);

    vector<Cost> res;
    res.reserve(flow_max + 1);
    int index = 0;
    ll d;
    for(int i = 0; i <= flow_max; i++) {
        if(i == slope[index].first) {  // slopeの区間の端点のとき
            res.emplace_back(slope[index].second);

            if(index + 1 < slope.size()) {
                const auto &[cap1, cost1] = slope[index];
                const auto &[cap2, cost2] = slope[index + 1];
                d = (cost2 - cost1) / (cap2 - cap1);
                index++;
            }
        }
        else {  // slopeの区間内のとき
            res.emplace_back(res.back() + d);
        }
    }

    return res;
}
