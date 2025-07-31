#pragma once
#include "../core/core.hpp"
enum class graph_direction {
    directed,
    undirected,
};

// 頂点root を通る最短閉路の長さを返す（単純グラフを仮定. 同じ頂点を二度通らない）
// 閉路が存在しない場合はwg.INFを返す
template <class T> T shortest_cycle(const WeightedGraph<T> &wg, graph_direction graph_dirc, int root) {
    // rootを根とする最短路木を作る
    vector<T> distance(wg.size, wg.INF);
    vector<int> label(wg.size);  // label[root] := root, label[i] :=
                                 // （最短路木でiの祖先である頂点（iを含む）のうち、根に最も近いもの）
    {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.emplace(0, root, root);
        while(!pq.empty()) {
            auto [d, now, pre] = pq.top();
            pq.pop();
            if(distance[now] < d) continue;
            distance[now] = d;
            if(pre == root) label[now] = now;
            else label[now] = label[pre];

            for(auto [nxt, cost] : wg[now]) {
                pq.emplace(d + cost, nxt, now);
            }
        }
    }


    // 最短閉路を見つける
    T min_cost = wg.INF;
    for(int from = 0; from < wg.size; from++) {
        if(from == root) continue;
        if(distance[from] == wg.INF) continue;
        for(auto [to, cost] : wg[from]) {
            if(distance[to] == wg.INF) continue;
            if(graph_dirc == graph_direction::undirected) {
                if(label[from] == label[to]) continue;
                if(to == root && label[from] == from) continue;
                else chmin(min_cost, distance[from] + distance[to] + cost);
            }
            if(graph_dirc == graph_direction::directed) {
                if(to != root) continue;
                else chmin(min_cost, distance[from] + cost);
            }
        }
    }

    return min_cost;
}
