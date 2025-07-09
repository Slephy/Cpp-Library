#pragma once
#include "../core/core.hpp"
#include "graph-template.hpp"

template<GraphConcept Graph>
class HeavyLightDecomposition{
private:
    Graph graph;
    int n; // 頂点数
    const int root;
    vector<int> subtree_size;   // subtree_size[v] := (頂点vを根とする部分木のサイズ)
    vector<int> preorder;       // 行きがけ順
    vector<int> preorder_index; // preorder_index[v] := （行きがけ順における頂点vのインデックス）
    vector<int> parent;         // parent[v] := （頂点vの親, ただし parent[root] = -1）
    vector<int> head;           // head[v] := （頂点vが属する heavy path のうち、最も根に近い頂点）
    vector<int> depth;          // depth[v] :=（depth[root] = 0 としたときの頂点vの深さ）

public:
    HeavyLightDecomposition(const Graph &graph, int root = 0) :
        graph(graph), n(graph.size()), root(root), subtree_size(graph.size()),
        preorder_index(graph.size()), parent(graph.size()), head(graph.size()), depth(graph.size()) {
        init();
    }

    // u-vパスを構成する頂点を、行きがけ順での区間の配列で返す
    vector<pair<int, int>> query(int u, int v){
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        vector<pair<int, int>> ret;
        while(head[u] != head[v]){
            if(depth[head[u]] >= depth[head[v]]){
                ret.emplace_back(head[u], u);
                u = parent[head[u]];
            }
            else{
                ret.emplace_back(head[v], v);
                v = parent[head[v]];
            }
        }

        if(preorder_index[u] < preorder_index[v]) ret.emplace_back(u, v);
        else ret.emplace_back(v, u);
        for(auto &[v1, v2] : ret) v1 = preorder_index[v1], v2 = preorder_index[v2];
        return ret;
    };

    vector<int> get_preorder() const {
        return preorder;
    }

    int get_preoder_index(int v) const {
        return preorder_index.at(v);
    }

private:
    void init(){
        dfs1(root, -1);
        dfs2(root, -1);
    }

    // graph[now][0] が heavy_child になるように swap
    // depth, subtree_size を構築
    int dfs1(int now, int par){
        subtree_size[now] = 1;
        if(now == root) depth[now] = 0;
        else depth[now] = depth[par] + 1;

        for(auto &nxt : graph[now]){
            if(nxt == par) continue;
            int sz = dfs1(nxt, now);
            subtree_size[now] += sz;
            if(sz > subtree_size[graph[now][0]]) swap(graph[now][0], nxt);
        }
        return subtree_size[now];
    };

    // 行きがけ順を記録
    // parent, head を構築
    void dfs2(int now, int par){
        preorder_index[now] = preorder.size();
        preorder.emplace_back(now);
        parent[now] = par;

        if(now == root) head[now] = now;
        else head[now] = (graph[par][0] == now) ? head[par] : now;

        for(auto nxt : graph[now]){
            if(nxt == par) continue;
            else dfs2(nxt, now);
        }
    };
};
