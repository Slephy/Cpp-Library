#pragma once
#include "../core/core.hpp"
// 凸包を構成する頂点を返す
// 凸包の辺上の点を反時計回りに並べて出力する。
// 返り値の第一要素は引数の第一要素と必ず一致する。
// 引数として渡す配列は、x,y軸の両方について昇順または降順にソートされているものとする。
// xの昇順かつyの降順なども可。
vector<Point> convex_hull_ll(const vector<Point> &p) {
    assert(p.size() == 0 || typeid(p[0].px) == typeid(ll));
    vector<Point> g1, g2;
    g1.emplace_back(p[0]);
    g1.emplace_back(p[1]);
    g2.emplace_back(p[0]);
    g2.emplace_back(p[1]);

    for(int i = 2; i < p.size(); i++) {
        // 凸包の辺上の点をすべて出力する
        // 凸包をなす頂点のみにしたいならば、条件式末尾の = を削除する
        while(g1.size() >= 2 && crs(g1[g1.size() - 2] - g1[g1.size() - 1], p[i] - g1[g1.size() - 1]) >= 0) {
            g1.pop_back();
        }
        while(g2.size() >= 2 && crs(g2[g2.size() - 2] - g2[g2.size() - 1], p[i] - g2[g2.size() - 1]) <= 0) {
            g2.pop_back();
        }

        g1.emplace_back(p[i]);
        g2.emplace_back(p[i]);
    }

    vector<Point> &ret = g1;
    ret.insert(ret.end(), g2.rbegin() + 1, g2.rend() - 1);
    return ret;
}
