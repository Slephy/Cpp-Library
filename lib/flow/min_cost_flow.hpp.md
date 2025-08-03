---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: lib/core/core.hpp
    title: lib/core/core.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/core/core.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing ull = unsigned long long;\nconst int INF\
    \ = (int)1e9 + 1001010;\nconst ll llINF = (long long)4e18 + 22000020;\nconst string\
    \ endn = \"\\n\";\ntemplate <class T> inline auto vector2(size_t i, size_t j,\
    \ const T &init = T()) {\n    return vector(i, vector<T>(j, init));\n}\nconst\
    \ string ELM_SEP = \" \", VEC_SEP = endn;\ntemplate <class T> istream &operator>>(istream\
    \ &i, vector<T> &A) {\n    for(auto &I : A) i >> I;\n    return i;\n}\ntemplate\
    \ <class T> ostream &operator<<(ostream &o, const vector<T> &A) {\n    int sz\
    \ = A.size();\n    for(const auto &I : A) o << I << (--sz ? ELM_SEP : \"\");\n\
    \    return o;\n}\ntemplate <class T> ostream &operator<<(ostream &o, const vector<vector<T>>\
    \ &A) {\n    int sz = A.size();\n    for(const auto &I : A) o << I << (--sz ?\
    \ VEC_SEP : \"\");\n    return o;\n}\ntemplate <class T> vector<T> &operator++(vector<T>\
    \ &A, int) {\n    for(auto &I : A) I++;\n    return A;\n}\ntemplate <class T>\
    \ vector<T> &operator--(vector<T> &A, int) {\n    for(auto &I : A) I--;\n    return\
    \ A;\n}\ntemplate <class T, class U> bool chmax(T &a, const U &b) { return ((a\
    \ < b) ? (a = b, true) : false); }\ntemplate <class T, class U> bool chmin(T &a,\
    \ const U &b) { return ((a > b) ? (a = b, true) : false); }\nll floor_div(ll a,\
    \ ll b) {\n    if(b < 0) a = -a, b = -b;\n    return (a >= 0) ? a / b : (a + 1)\
    \ / b - 1;\n}\nll ceil_div(ll a, ll b) {\n    if(b < 0) a = -a, b = -b;\n    return\
    \ (a > 0) ? (a - 1) / b + 1 : a / b;\n}\nbool check_bit(ull val, ull digit) {\
    \ return (val >> digit) & 1; }\n#ifdef DEBUG\n#include <cpp-dump/cpp-dump.hpp>\n\
    #define dump(...) cpp_dump(__VA_ARGS__)\nnamespace cp = cpp_dump;\nstruct InitCppDump\
    \ {\n    InitCppDump() {\n        if(!isatty(fileno(stderr))) CPP_DUMP_SET_OPTION(es_style,\
    \ cpp_dump::types::es_style_t::no_es);\n        CPP_DUMP_SET_OPTION(log_label_func,\
    \ cp::log_label::line());\n        CPP_DUMP_SET_OPTION(max_iteration_count, 30);\n\
    \    }\n} init_cpp_dump;\n#else\n#define dump(...)\n#endif\n// ====================\
    \ \u3053\u3053\u307E\u3067\u30C6\u30F3\u30D7\u30EC ====================\n#line\
    \ 3 \"lib/flow/min_cost_flow.hpp\"\n// \u53C2\u8003 AtCoder Library\n// == ACL\u304B\
    \u3089\u306E\u5909\u66F4\u70B9 ==\n// \u521D\u671F\u72B6\u614B\u306B\u8CA0\u306E\
    \u30B3\u30B9\u30C8\u306E\u8FBA\u304C\u3042\u308B\u5834\u5408\u306B\u5BFE\u5FDC\
    \n// Primal-Dual(Dijkstra) + Bellman-Ford\n// \u305D\u306E\u5834\u5408\u306E\u6642\
    \u9593\u8A08\u7B97\u91CF\u306FO(FVlogE + VE)\ntemplate <class Cap, class Cost>\
    \ struct mcf_graph {\npublic:\n    mcf_graph() {}\n    mcf_graph(int n) : _n(n),\
    \ g(n), has_negative_edge_initially(false) {}\n    int add_edge(int from, int\
    \ to, Cap cap, Cost cost) {\n        assert(0 <= from && from < _n);\n       \
    \ assert(0 <= to && to < _n);\n        int m = int(pos.size());\n        pos.push_back({from,\
    \ int(g[from].size())});\n        g[from].push_back(_edge{to, int(g[to].size()),\
    \ cap, cost});\n        g[to].push_back(_edge{from, int(g[from].size()) - 1, 0,\
    \ -cost});\n        if(cost < 0) has_negative_edge_initially = true;\n       \
    \ return m;\n    }\n    struct edge {\n        int from, to;\n        Cap cap,\
    \ flow;\n        Cost cost;\n    };\n    edge get_edge(int i) {\n        int m\
    \ = int(pos.size());\n        assert(0 <= i && i < m);\n        auto _e = g[pos[i].first][pos[i].second];\n\
    \        auto _re = g[_e.to][_e.rev];\n        return edge{\n            pos[i].first,\
    \ _e.to, _e.cap + _re.cap, _re.cap, _e.cost,\n        };\n    }\n    vector<edge>\
    \ edges() {\n        int m = int(pos.size());\n        vector<edge> result(m);\n\
    \        for(int i = 0; i < m; i++) {\n            result[i] = get_edge(i);\n\
    \        }\n        return result;\n    }\n    pair<Cap, Cost> flow(int s, int\
    \ t) { return flow(s, t, numeric_limits<Cap>::max()); }\n    pair<Cap, Cost> flow(int\
    \ s, int t, Cap flow_limit) { return slope(s, t, flow_limit).back(); }\n    vector<pair<Cap,\
    \ Cost>> slope(int s, int t) { return slope(s, t, numeric_limits<Cap>::max());\
    \ }\n    vector<pair<Cap, Cost>> slope(int s, int t, Cap flow_limit) {\n     \
    \   assert(0 <= s && s < _n);\n        assert(0 <= t && t < _n);\n        assert(s\
    \ != t);\n        // variants (C = maxcost):\n        // -(n-1)C <= dual[s] <=\
    \ dual[i] <= dual[t] = 0\n        // reduced cost (= e.cost + dual[e.from] - dual[e.to])\
    \ >= 0 for all edge\n        vector<Cost> dual(_n, 0), dist(_n), ndist(_n);\n\
    \        vector<int> pv(_n), pe(_n);\n        vector<bool> vis(_n);\n\n      \
    \  auto init_dual_ref = [&]() -> void {\n            for(int i = 0; i < _n; i++)\
    \ {\n                bool update = false;\n                for(int v = 0; v <\
    \ _n; v++) {\n                    for(auto e : g[v]) {\n                     \
    \   if(!e.cap) continue;\n                        if(chmin(dual[e.to], dual[v]\
    \ + e.cost)) {\n                            update = true;\n                 \
    \       }\n                    }\n                }\n                if(!update)\
    \ break;\n                if(i == _n - 1) {\n                    cerr << \"This\
    \ Graph may have some negative cycles.\" << endl;\n                    exit(1);\n\
    \                }\n            }\n        };\n\n        auto dual_ref = [&]()\
    \ {\n            fill(dist.begin(), dist.end(), numeric_limits<Cost>::max() /\
    \ 4);\n            fill(pv.begin(), pv.end(), -1);\n            fill(pe.begin(),\
    \ pe.end(), -1);\n            fill(vis.begin(), vis.end(), false);\n         \
    \   struct Q {\n                Cost key;\n                int to;\n         \
    \       bool operator<(Q r) const { return key > r.key; }\n            };\n  \
    \          priority_queue<Q> que;\n            dist[s] = 0;\n            que.push(Q{0,\
    \ s});\n            while(!que.empty()) {\n                int v = que.top().to;\n\
    \                que.pop();\n                if(vis[v]) continue;\n          \
    \      vis[v] = true;\n                if(v == t) break;\n                // dist[v]\
    \ = shortest(s, v) + dual[s] - dual[v]\n                // dist[v] >= 0 (all reduced\
    \ cost are positive)\n                // dist[v] <= (n-1)C\n                for(int\
    \ i = 0; i < int(g[v].size()); i++) {\n                    auto e = g[v][i];\n\
    \                    if(vis[e.to] || !e.cap) continue;\n                    //\
    \ |-dual[e.to] + dual[v]| <= (n-1)C\n                    // cost <= C - -(n-1)C\
    \ + 0 = nC\n                    Cost cost = e.cost - dual[e.to] + dual[v];\n \
    \                   if(dist[e.to] - dist[v] > cost) {\n                      \
    \  dist[e.to] = dist[v] + cost;\n                        pv[e.to] = v;\n     \
    \                   pe[e.to] = i;\n                        que.push(Q{dist[e.to],\
    \ e.to});\n                    }\n                }\n            }\n         \
    \   if(!vis[t]) {\n                return false;\n            }\n            for(int\
    \ v = 0; v < _n; v++) {\n                if(!vis[v]) continue;\n             \
    \   // dual[v] = dual[v] - dist[t] + dist[v]\n                //         = dual[v]\
    \ - (shortest(s, t) + dual[s] - dual[t]) + (shortest(s, v) + dual[s] - dual[v])\n\
    \                //         = - shortest(s, t) + dual[t] + shortest(s, v)\n  \
    \              //         = shortest(s, v) - shortest(s, t) >= 0 - (n-1)C\n  \
    \              // dist[v] = dist[v] + dual[v] - dual[s];\n                ndist[v]\
    \ = dual[v] - dual[s];\n                dual[v] -= dist[t] - dist[v];\n      \
    \      }\n            swap(dist, ndist);\n            return true;\n        };\n\
    \        Cap flow = 0;\n        Cost cost = 0, prev_cost = numeric_limits<Cost>::min();\n\
    \        vector<pair<Cap, Cost>> result;\n        result.push_back({flow, cost});\n\
    \        if(has_negative_edge_initially) init_dual_ref();\n        while(flow\
    \ < flow_limit) {\n            if(!dual_ref()) break;\n            Cap c = flow_limit\
    \ - flow;\n            for(int v = t; v != s; v = pv[v]) {\n                c\
    \ = min(c, g[pv[v]][pe[v]].cap);\n            }\n            for(int v = t; v\
    \ != s; v = pv[v]) {\n                auto& e = g[pv[v]][pe[v]];\n           \
    \     e.cap -= c;\n                g[v][e.rev].cap += c;\n            }\n    \
    \        Cost d = dist[t];\n            flow += c;\n            cost += c * d;\n\
    \            if(prev_cost == d) {\n                result.pop_back();\n      \
    \      }\n            result.push_back({flow, cost});\n            prev_cost =\
    \ cost;\n        }\n        return result;\n    }\n\nprivate:\n    int _n;\n \
    \   struct _edge {\n        int to, rev;\n        Cap cap;\n        Cost cost;\n\
    \    };\n    vector<pair<int, int>> pos;\n    vector<vector<_edge>> g;\n    bool\
    \ has_negative_edge_initially;\n};\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\n// \u53C2\u8003 AtCoder Library\n\
    // == ACL\u304B\u3089\u306E\u5909\u66F4\u70B9 ==\n// \u521D\u671F\u72B6\u614B\u306B\
    \u8CA0\u306E\u30B3\u30B9\u30C8\u306E\u8FBA\u304C\u3042\u308B\u5834\u5408\u306B\
    \u5BFE\u5FDC\n// Primal-Dual(Dijkstra) + Bellman-Ford\n// \u305D\u306E\u5834\u5408\
    \u306E\u6642\u9593\u8A08\u7B97\u91CF\u306FO(FVlogE + VE)\ntemplate <class Cap,\
    \ class Cost> struct mcf_graph {\npublic:\n    mcf_graph() {}\n    mcf_graph(int\
    \ n) : _n(n), g(n), has_negative_edge_initially(false) {}\n    int add_edge(int\
    \ from, int to, Cap cap, Cost cost) {\n        assert(0 <= from && from < _n);\n\
    \        assert(0 <= to && to < _n);\n        int m = int(pos.size());\n     \
    \   pos.push_back({from, int(g[from].size())});\n        g[from].push_back(_edge{to,\
    \ int(g[to].size()), cap, cost});\n        g[to].push_back(_edge{from, int(g[from].size())\
    \ - 1, 0, -cost});\n        if(cost < 0) has_negative_edge_initially = true;\n\
    \        return m;\n    }\n    struct edge {\n        int from, to;\n        Cap\
    \ cap, flow;\n        Cost cost;\n    };\n    edge get_edge(int i) {\n       \
    \ int m = int(pos.size());\n        assert(0 <= i && i < m);\n        auto _e\
    \ = g[pos[i].first][pos[i].second];\n        auto _re = g[_e.to][_e.rev];\n  \
    \      return edge{\n            pos[i].first, _e.to, _e.cap + _re.cap, _re.cap,\
    \ _e.cost,\n        };\n    }\n    vector<edge> edges() {\n        int m = int(pos.size());\n\
    \        vector<edge> result(m);\n        for(int i = 0; i < m; i++) {\n     \
    \       result[i] = get_edge(i);\n        }\n        return result;\n    }\n \
    \   pair<Cap, Cost> flow(int s, int t) { return flow(s, t, numeric_limits<Cap>::max());\
    \ }\n    pair<Cap, Cost> flow(int s, int t, Cap flow_limit) { return slope(s,\
    \ t, flow_limit).back(); }\n    vector<pair<Cap, Cost>> slope(int s, int t) {\
    \ return slope(s, t, numeric_limits<Cap>::max()); }\n    vector<pair<Cap, Cost>>\
    \ slope(int s, int t, Cap flow_limit) {\n        assert(0 <= s && s < _n);\n \
    \       assert(0 <= t && t < _n);\n        assert(s != t);\n        // variants\
    \ (C = maxcost):\n        // -(n-1)C <= dual[s] <= dual[i] <= dual[t] = 0\n  \
    \      // reduced cost (= e.cost + dual[e.from] - dual[e.to]) >= 0 for all edge\n\
    \        vector<Cost> dual(_n, 0), dist(_n), ndist(_n);\n        vector<int> pv(_n),\
    \ pe(_n);\n        vector<bool> vis(_n);\n\n        auto init_dual_ref = [&]()\
    \ -> void {\n            for(int i = 0; i < _n; i++) {\n                bool update\
    \ = false;\n                for(int v = 0; v < _n; v++) {\n                  \
    \  for(auto e : g[v]) {\n                        if(!e.cap) continue;\n      \
    \                  if(chmin(dual[e.to], dual[v] + e.cost)) {\n               \
    \             update = true;\n                        }\n                    }\n\
    \                }\n                if(!update) break;\n                if(i ==\
    \ _n - 1) {\n                    cerr << \"This Graph may have some negative cycles.\"\
    \ << endl;\n                    exit(1);\n                }\n            }\n \
    \       };\n\n        auto dual_ref = [&]() {\n            fill(dist.begin(),\
    \ dist.end(), numeric_limits<Cost>::max() / 4);\n            fill(pv.begin(),\
    \ pv.end(), -1);\n            fill(pe.begin(), pe.end(), -1);\n            fill(vis.begin(),\
    \ vis.end(), false);\n            struct Q {\n                Cost key;\n    \
    \            int to;\n                bool operator<(Q r) const { return key >\
    \ r.key; }\n            };\n            priority_queue<Q> que;\n            dist[s]\
    \ = 0;\n            que.push(Q{0, s});\n            while(!que.empty()) {\n  \
    \              int v = que.top().to;\n                que.pop();\n           \
    \     if(vis[v]) continue;\n                vis[v] = true;\n                if(v\
    \ == t) break;\n                // dist[v] = shortest(s, v) + dual[s] - dual[v]\n\
    \                // dist[v] >= 0 (all reduced cost are positive)\n           \
    \     // dist[v] <= (n-1)C\n                for(int i = 0; i < int(g[v].size());\
    \ i++) {\n                    auto e = g[v][i];\n                    if(vis[e.to]\
    \ || !e.cap) continue;\n                    // |-dual[e.to] + dual[v]| <= (n-1)C\n\
    \                    // cost <= C - -(n-1)C + 0 = nC\n                    Cost\
    \ cost = e.cost - dual[e.to] + dual[v];\n                    if(dist[e.to] - dist[v]\
    \ > cost) {\n                        dist[e.to] = dist[v] + cost;\n          \
    \              pv[e.to] = v;\n                        pe[e.to] = i;\n        \
    \                que.push(Q{dist[e.to], e.to});\n                    }\n     \
    \           }\n            }\n            if(!vis[t]) {\n                return\
    \ false;\n            }\n            for(int v = 0; v < _n; v++) {\n         \
    \       if(!vis[v]) continue;\n                // dual[v] = dual[v] - dist[t]\
    \ + dist[v]\n                //         = dual[v] - (shortest(s, t) + dual[s]\
    \ - dual[t]) + (shortest(s, v) + dual[s] - dual[v])\n                //      \
    \   = - shortest(s, t) + dual[t] + shortest(s, v)\n                //        \
    \ = shortest(s, v) - shortest(s, t) >= 0 - (n-1)C\n                // dist[v]\
    \ = dist[v] + dual[v] - dual[s];\n                ndist[v] = dual[v] - dual[s];\n\
    \                dual[v] -= dist[t] - dist[v];\n            }\n            swap(dist,\
    \ ndist);\n            return true;\n        };\n        Cap flow = 0;\n     \
    \   Cost cost = 0, prev_cost = numeric_limits<Cost>::min();\n        vector<pair<Cap,\
    \ Cost>> result;\n        result.push_back({flow, cost});\n        if(has_negative_edge_initially)\
    \ init_dual_ref();\n        while(flow < flow_limit) {\n            if(!dual_ref())\
    \ break;\n            Cap c = flow_limit - flow;\n            for(int v = t; v\
    \ != s; v = pv[v]) {\n                c = min(c, g[pv[v]][pe[v]].cap);\n     \
    \       }\n            for(int v = t; v != s; v = pv[v]) {\n                auto&\
    \ e = g[pv[v]][pe[v]];\n                e.cap -= c;\n                g[v][e.rev].cap\
    \ += c;\n            }\n            Cost d = dist[t];\n            flow += c;\n\
    \            cost += c * d;\n            if(prev_cost == d) {\n              \
    \  result.pop_back();\n            }\n            result.push_back({flow, cost});\n\
    \            prev_cost = cost;\n        }\n        return result;\n    }\n\nprivate:\n\
    \    int _n;\n    struct _edge {\n        int to, rev;\n        Cap cap;\n   \
    \     Cost cost;\n    };\n    vector<pair<int, int>> pos;\n    vector<vector<_edge>>\
    \ g;\n    bool has_negative_edge_initially;\n};\n"
  dependsOn:
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/flow/min_cost_flow.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/flow/min_cost_flow.hpp
layout: document
redirect_from:
- /library/lib/flow/min_cost_flow.hpp
- /library/lib/flow/min_cost_flow.hpp.html
title: lib/flow/min_cost_flow.hpp
---
