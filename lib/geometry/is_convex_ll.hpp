#pragma once
#include "../core/core.hpp"
// 狭義凸性を判定する（任意の内角が180度未満）
bool is_convex_ll(const vector<Point> &p) {
    assert(p.size() == 0 || typeid(p[0].px) == typeid(ll));
    if(p.size() <= 2) return true;
    bool allP = true, allN = true;  // 外積がすべて正か、もしくはすべて負か
    for(int i = 0; i < p.size(); i++) {
        const auto &p1 = p[i];
        const auto &p2 = p[(i + 1) % p.size()];
        const auto &p3 = p[(i + 2) % p.size()];
        auto cross = crs(p1 - p2, p3 - p2);
        if(cross <= 0) allP = false;
        else if(cross >= 0) allN = false;
    }
    return (allP || allN);
}
