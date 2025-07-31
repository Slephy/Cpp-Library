#pragma once
#include "../core/core.hpp"
// 参考 : https://trap.jp/post/1702/
// E : 部分木もどきの計算結果の型
// V : 部分木の計算結果の型
template <class E, class V, E (*merge)(E, E), E (*e)(), E (*put_edge)(V, int), V (*put_vertex)(E, int)>
class RerootingDP {
    struct edge {
        int from, to, idx, rev_idx;
        edge(int from, int to, int idx, int rev_idx) : from(from), to(to), idx(idx), rev_idx(rev_idx) {}
    };

public:
    RerootingDP(size_t n) : n(n), edges(n), results(n) {}

    // u -> v (idx1), v -> u (idx2) の2辺を追加する
    void add_bidirectional_edge(size_t u, size_t v, int idx1, int idx2) {
        edges[u].emplace_back(u, v, idx1, idx2);
        edges[v].emplace_back(v, u, idx2, idx1);
    }

    // root を根として木DPを行う
    V build(size_t root = 0) {
        assert(!is_built);
        this->root = root;
        vector<int> vis(n, 0);

        auto dfs = [&](auto &&dfs, int v) -> V {
            vis[v]++;
            E val = e();
            for(auto &p : edges[v]) {
                if(vis[p.to] > 0 && p.to != edges[v].back().to)
                    swap(p, edges[v].back());  // edges[v].back().toを頂点vの親にしている
                if(vis[p.to] > 0) continue;    // 到達済みならスキップ
                E nval = put_edge(dfs(dfs, p.to), p.idx);
                results[v].emplace_back(nval);
                val = merge(val, nval);
            }
            return put_vertex(val, v);
        };

        is_built = true;
        return dfs(dfs, root);
    }

    // 全方位木DPを行う
    vector<V> reroot() {
        if(!is_built) build();
        vector<E> parent_result(n);
        vector<V> ans(n);
        parent_result[root] = e();

        auto bfs = [&](auto &&bfs, int now) -> void {
            int child_num = results[now].size();
            vector<E> lui(child_num + 1), rui(child_num + 1);
            lui[0] = e(), rui[child_num] = e();
            for(int i = 0; i < child_num; i++) lui[i + 1] = merge(lui[i], results[now][i]);
            for(int i = child_num - 1; i >= 0; i--) rui[i] = merge(results[now][i], rui[i + 1]);

            for(int i = 0; i < child_num; i++) {
                const auto &edge = edges[now][i];
                parent_result[edge.to] =
                    put_edge(put_vertex(merge(merge(lui[i], rui[i + 1]), parent_result[now]), now), edge.rev_idx);
                bfs(bfs, edge.to);
            }

            ans[now] = put_vertex(merge(lui.back(), parent_result[now]), now);
        };

        bfs(bfs, root);
        return ans;
    }

private:
    size_t n, root;
    bool is_built = false;
    vector<vector<edge>> edges;
    vector<vector<E>> results;  // results[v][i] := （"頂点vから出るi番目の辺"が飛び出した部分木もどきの計算結果）
};


template <class E, class V> struct RDP {
    static E merge(E a, E b) { return max(a, b); }
    static E e() { return 0; }
    static E put_edge(V v, int e_index) { return v + 1; }
    static V put_vertex(E e, int v_index) { return e; }
    using Type = class RerootingDP<E, V, merge, e, put_edge, put_vertex>;
};
