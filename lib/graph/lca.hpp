#pragma once
#include "graph-template.hpp"

template <GraphConcept Graph>
class LCA{
    const Graph &graph;
    const int n;
    const int root;
    const int lg = 30;
    vector<vector<int>> parent;
    vector<int> dist;

public:
    LCA(const Graph &graph, size_t root = 0) :
        graph(graph), n(graph.size()), root(root), parent(lg, vector<int>(n, -1)), dist(graph.size(), -1){

        dfs(root, -1, 0);
        // ダブリング
        for(int k = 0; k + 1 < lg; k++){
            for(int v = 0; v < n; v++){
                if(parent[k][v] < 0) parent[k + 1][v] = -1;
                else parent[k + 1][v] = parent[k][parent[k][v]];
            }
        }
    }


private:
    // 根からの距離と1つ先の頂点を求める
    // dist を初期化
    void dfs(int now, int par, int d) {
        parent[0][now] = par;
        dist[now] = d;
        for(auto nxt : graph[now]) {
            if(nxt != par) dfs(nxt, now, d + 1);
        }
    }

public:
    // O(logV)
    int query(int u, int v) {
        if(dist[u] < dist[v]) swap(u, v);  // u の方が深いとする
        // LCA までの距離を同じにする
        int diff = dist[u] - dist[v];
        for(int k = 0; k < lg; k++){
            if((diff >> k) & 1){
                u = parent[k][u];
            }
        }
        // 二分探索で LCA を求める
        if(u == v) return u;
        for(int k = lg - 1; k >= 0; k--){
            if(parent[k][u] != parent[k][v]){
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }

    // O(logV)
    int get_dist(int u, int v){
        return dist[u] + dist[v] - 2 * dist[query(u, v)];
    }

    // O(logV)
    // 頂点a がu-vパス上に存在するかを判定する
    bool is_on_path(int u, int v, int a){
        return get_dist(u, a) + get_dist(a, v) == get_dist(u, v);
    }
};
