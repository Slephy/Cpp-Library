#pragma once
#include "graph-template.hpp"

namespace slephy_scc{
enum class DAGType{
    multiple, // 多重辺を残す
    compress, // 多重辺をひとつにまとめる
};

template<GraphConcept Graph>
class SCC{
    const Graph &graph;
    Graph rgraph;
    int n;
    DAGType dag_type;
    vector<int> ord;
    vector<int> comp;
    vector<vector<int>> scc; // scc[i] := i番目の強連結成分に含まれる頂点の集合
    vector<vector<int>> dag_; // 強連結成分を頂点としたDAG (トポロジカルソート済み)
    vector<int> inner_edges; // 強連結成分内の辺の数

public:
    SCC(const Graph &graph, bool need_builing_dag = true, DAGType dag_type = DAGType::multiple)
        : graph(graph), dag_type(dag_type), n(graph.size()), comp(graph.size(), -1){
        rgraph.resize(n);
        for(int i = 0; i < n; i++){
            for(auto &to : graph[i]){
                rgraph[to].push_back(i);
            }
        }
        build(need_builing_dag);
    }

    // 圧縮後のDAGにおいて頂点vに隣接する頂点を返す
    // @require 0 <= idx && idx < dag_.size()
    vector<int>& dag(int v){
        return dag_[v];
    }

    vector<vector<int>>& dag(){
        return dag_;
    }

    // 頂点vが含まれる強連結成分の番号を返す
    // @require 0 <= idx && idx < n
    int get_comp(int v){
        return comp[v];
    }

    // idx番目の強連結成分に含まれる頂点を返す
    // @require 0 <= idx && idx < dag_.size()
    vector<int>& get_scc(int idx){
        return scc[idx];
    }

    // 強連結成分ごとに頂点をまとめたものを返す
    vector<vector<int>> &get_scc(){
        return scc;
    }

    // idx番目の強連結成分内に含まれる辺の本数を返す
    // @require 0 <= idx && idx < dag_.size()
    int get_edges_num(int idx){
        return inner_edges[idx];
    }

private:
    void build(bool need_builing_dag){
        ord.resize(n, -1);
        vector<bool> visited(n, false);
        vector<int> vs; // 帰りがけ順

        // 帰りがけ順に番号を振る
        int iter = 0;
        auto dfs = [&](auto &&dfs, int now) -> void {
            visited[now] = true;
            for(auto &to : graph[now]){
                if(!visited[to]) dfs(dfs, to);
            }
            ord[now] = iter++;
            vs.push_back(now);
        };
        for(int i = 0; i < n; i++){
            if(!visited[i]) dfs(dfs, i);
        }


        // 逆辺を張ったグラフにおいて、帰りがけ順の大きい順にDFS
        iter = 0;
        visited.assign(n, false);
        auto rdfs = [&](auto &&rdfs, int now, int scc_id) -> void {
            visited[now] = true;
            comp[now] = scc_id;
            scc[scc_id].push_back(now);
            for(auto &to : rgraph[now]){
                if(!visited[to]) rdfs(rdfs, to, scc_id);
            }
        };
        for(int i = n-1; i >= 0; i--){
            if(!visited[vs[i]]){
                scc.push_back(vector<int>());
                rdfs(rdfs, vs[i], iter++);
            }
        }

        // DAGを構築
        if(need_builing_dag) construct_dag();
    }

    // dag_type == multiple then O(E + V)
    // dag_type == compress then O(ElogE + V)
    void construct_dag(){
        dag_.resize(scc.size());
        inner_edges.resize(scc.size(), 0);
        set<pair<int, int>> added_edge;
        for(int i = 0; i < n; i++){
            for(auto &to : graph[i]){
                if(comp[i] == comp[to]){
                    inner_edges[comp[i]]++;
                    continue;
                }
                else{
                    if(dag_type == DAGType::compress){
                        if(added_edge.count({comp[i], comp[to]})) continue;
                        added_edge.emplace(comp[i], comp[to]);
                        dag_[comp[i]].push_back(comp[to]);
                    }
                    else if(dag_type == DAGType::multiple){
                        dag_[comp[i]].push_back(comp[to]);
                    }
                    else{
                        cerr << "Invalid DAGType" << endl;
                        exit(1);
                    }
                }
            }
        }
    }
};
}; // namespace slephy_scc
using slephy_scc::DAGType;
using slephy_scc::SCC;
