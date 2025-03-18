#pragma once
#include "graph-template.hpp"

// 無向グラフ ただし連結グラフでなくてもよい
template <GraphConcept Graph>
class LowLink{
    const Graph &G;
    vector<int> ord, low;
    vector<int> aps;
    vector<pair<int, int>> bridges;

public:
    LowLink(const Graph &G) :
        G(G), ord(G.size(), -1), low(G.size(), -1){
        int iter = 0;
        for(int i = 0; i < G.size(); i++){
            // もし連結グラフなら、ここからdfs関数が呼び出されるのは1度だけ。
            // 連結成分の個数だけ、ここからdfs関数が呼び出される
            if(ord[i] == -1) dfs(i, -1, iter);
        }
        sort(aps.begin(), aps.end());
        sort(bridges.begin(), bridges.end());
    }

    // 関節点の配列を返す
    vector<int> get_aps(){
        return aps;
    }

    // 橋を端点の組で表した配列を返す
    vector<pair<int, int>> get_bridges(){
        return bridges;
    }

private:
    void dfs(int now, int par, int &iter){
        assert(ord[now] == -1);
        ord[now] = iter++;
        low[now] = ord[now];
        int child_num = 0;
        bool is_aps = false;

        for(auto nxt : G[now]){
            if(nxt == par) continue;
            if(ord[nxt] == -1){ // 順方向
                child_num++;
                dfs(nxt, now, iter);
                chmin(low[now], low[nxt]);
                if(low[nxt] > ord[now]) bridges.emplace_back(min(now, nxt), max(now, nxt));
                // 関節点の判定方法は、それが根なのかどうかで変わる
                if(par != -1 && low[nxt] >= ord[now]) is_aps = true;
            }
            else{ // 後退辺（ただし祖先 -> 子孫の方向かもしれない）
                chmin(low[now], ord[nxt]);
            }
        }

        if(par == -1 && child_num >= 2) is_aps = true;
        if(is_aps) aps.emplace_back(now);
        return;
    }
};
