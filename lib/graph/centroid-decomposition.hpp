#pragma once
#include "graph-template.hpp"

template <GraphConcept Graph>
class CentroidDecomposition{
    vector<bool> checked;
    vector<size_t> subtree_size;
    const Graph &graph;

public:
    CentroidDecomposition(const Graph &graph) :
        graph(graph), checked(graph.size(), false), subtree_size(graph.size(), 0){}

    // 与えられたグラフ全体の重心と、重心木を返します
    pair<int, vector<vector<int>>> build(){
        vector<vector<int>> tree(graph.size());
        return {build_dfs(0, tree), tree};
    }

private:
    size_t calc_subtree_size(int now, int par = -1){
        subtree_size[now] = 1;
        for(auto nxt : graph[now]){
            if(nxt == par || checked[nxt]) continue;
            subtree_size[now] += calc_subtree_size(nxt, now);
        }
        return subtree_size[now];
    }

    int find_centroid(int now, size_t mid_size, int par){
        for(auto nxt : graph[now]){
            if(nxt == par || checked[nxt]) continue;
            if(subtree_size[nxt] > mid_size) return find_centroid(nxt, mid_size, now);
        }
        return now;
    }

    int build_dfs(int now, Graph &tree){
        int centroid = find_centroid(now, calc_subtree_size(now, -1) / 2, -1);
        checked[centroid] = true;
        for(auto nxt : graph[centroid]){
            if(checked[nxt]) continue;
            tree[centroid].push_back(build_dfs(nxt, tree));
        }
        return centroid;
    }
};
