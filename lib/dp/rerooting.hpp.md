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
    links:
    - https://trap.jp/post/1702/
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
    \ 3 \"lib/dp/rerooting.hpp\"\n// \u53C2\u8003 : https://trap.jp/post/1702/\n//\
    \ E : \u90E8\u5206\u6728\u3082\u3069\u304D\u306E\u8A08\u7B97\u7D50\u679C\u306E\
    \u578B\n// V : \u90E8\u5206\u6728\u306E\u8A08\u7B97\u7D50\u679C\u306E\u578B\n\
    template <class E, class V, E (*merge)(E, E), E (*e)(), E (*put_edge)(V, int),\
    \ V (*put_vertex)(E, int)>\nclass RerootingDP {\n    struct edge {\n        int\
    \ from, to, idx, rev_idx;\n        edge(int from, int to, int idx, int rev_idx)\
    \ : from(from), to(to), idx(idx), rev_idx(rev_idx) {}\n    };\n\npublic:\n   \
    \ RerootingDP(size_t n) : n(n), edges(n), results(n) {}\n\n    // u -> v (idx1),\
    \ v -> u (idx2) \u306E2\u8FBA\u3092\u8FFD\u52A0\u3059\u308B\n    void add_bidirectional_edge(size_t\
    \ u, size_t v, int idx1, int idx2) {\n        edges[u].emplace_back(u, v, idx1,\
    \ idx2);\n        edges[v].emplace_back(v, u, idx2, idx1);\n    }\n\n    // root\
    \ \u3092\u6839\u3068\u3057\u3066\u6728DP\u3092\u884C\u3046\n    V build(size_t\
    \ root = 0) {\n        assert(!is_built);\n        this->root = root;\n      \
    \  vector<int> vis(n, 0);\n\n        auto dfs = [&](auto &&dfs, int v) -> V {\n\
    \            vis[v]++;\n            E val = e();\n            for(auto &p : edges[v])\
    \ {\n                if(vis[p.to] > 0 && p.to != edges[v].back().to)\n       \
    \             swap(p, edges[v].back());  // edges[v].back().to\u3092\u9802\u70B9\
    v\u306E\u89AA\u306B\u3057\u3066\u3044\u308B\n                if(vis[p.to] > 0)\
    \ continue;    // \u5230\u9054\u6E08\u307F\u306A\u3089\u30B9\u30AD\u30C3\u30D7\
    \n                E nval = put_edge(dfs(dfs, p.to), p.idx);\n                results[v].emplace_back(nval);\n\
    \                val = merge(val, nval);\n            }\n            return put_vertex(val,\
    \ v);\n        };\n\n        is_built = true;\n        return dfs(dfs, root);\n\
    \    }\n\n    // \u5168\u65B9\u4F4D\u6728DP\u3092\u884C\u3046\n    vector<V> reroot()\
    \ {\n        if(!is_built) build();\n        vector<E> parent_result(n);\n   \
    \     vector<V> ans(n);\n        parent_result[root] = e();\n\n        auto bfs\
    \ = [&](auto &&bfs, int now) -> void {\n            int child_num = results[now].size();\n\
    \            vector<E> lui(child_num + 1), rui(child_num + 1);\n            lui[0]\
    \ = e(), rui[child_num] = e();\n            for(int i = 0; i < child_num; i++)\
    \ lui[i + 1] = merge(lui[i], results[now][i]);\n            for(int i = child_num\
    \ - 1; i >= 0; i--) rui[i] = merge(results[now][i], rui[i + 1]);\n\n         \
    \   for(int i = 0; i < child_num; i++) {\n                const auto &edge = edges[now][i];\n\
    \                parent_result[edge.to] =\n                    put_edge(put_vertex(merge(merge(lui[i],\
    \ rui[i + 1]), parent_result[now]), now), edge.rev_idx);\n                bfs(bfs,\
    \ edge.to);\n            }\n\n            ans[now] = put_vertex(merge(lui.back(),\
    \ parent_result[now]), now);\n        };\n\n        bfs(bfs, root);\n        return\
    \ ans;\n    }\n\nprivate:\n    size_t n, root;\n    bool is_built = false;\n \
    \   vector<vector<edge>> edges;\n    vector<vector<E>> results;  // results[v][i]\
    \ := \uFF08\"\u9802\u70B9v\u304B\u3089\u51FA\u308Bi\u756A\u76EE\u306E\u8FBA\"\u304C\
    \u98DB\u3073\u51FA\u3057\u305F\u90E8\u5206\u6728\u3082\u3069\u304D\u306E\u8A08\
    \u7B97\u7D50\u679C\uFF09\n};\n\n\ntemplate <class E, class V> struct RDP {\n \
    \   static E merge(E a, E b) { return max(a, b); }\n    static E e() { return\
    \ 0; }\n    static E put_edge(V v, int e_index) { return v + 1; }\n    static\
    \ V put_vertex(E e, int v_index) { return e; }\n    using Type = class RerootingDP<E,\
    \ V, merge, e, put_edge, put_vertex>;\n};\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\n// \u53C2\u8003 : https://trap.jp/post/1702/\n\
    // E : \u90E8\u5206\u6728\u3082\u3069\u304D\u306E\u8A08\u7B97\u7D50\u679C\u306E\
    \u578B\n// V : \u90E8\u5206\u6728\u306E\u8A08\u7B97\u7D50\u679C\u306E\u578B\n\
    template <class E, class V, E (*merge)(E, E), E (*e)(), E (*put_edge)(V, int),\
    \ V (*put_vertex)(E, int)>\nclass RerootingDP {\n    struct edge {\n        int\
    \ from, to, idx, rev_idx;\n        edge(int from, int to, int idx, int rev_idx)\
    \ : from(from), to(to), idx(idx), rev_idx(rev_idx) {}\n    };\n\npublic:\n   \
    \ RerootingDP(size_t n) : n(n), edges(n), results(n) {}\n\n    // u -> v (idx1),\
    \ v -> u (idx2) \u306E2\u8FBA\u3092\u8FFD\u52A0\u3059\u308B\n    void add_bidirectional_edge(size_t\
    \ u, size_t v, int idx1, int idx2) {\n        edges[u].emplace_back(u, v, idx1,\
    \ idx2);\n        edges[v].emplace_back(v, u, idx2, idx1);\n    }\n\n    // root\
    \ \u3092\u6839\u3068\u3057\u3066\u6728DP\u3092\u884C\u3046\n    V build(size_t\
    \ root = 0) {\n        assert(!is_built);\n        this->root = root;\n      \
    \  vector<int> vis(n, 0);\n\n        auto dfs = [&](auto &&dfs, int v) -> V {\n\
    \            vis[v]++;\n            E val = e();\n            for(auto &p : edges[v])\
    \ {\n                if(vis[p.to] > 0 && p.to != edges[v].back().to)\n       \
    \             swap(p, edges[v].back());  // edges[v].back().to\u3092\u9802\u70B9\
    v\u306E\u89AA\u306B\u3057\u3066\u3044\u308B\n                if(vis[p.to] > 0)\
    \ continue;    // \u5230\u9054\u6E08\u307F\u306A\u3089\u30B9\u30AD\u30C3\u30D7\
    \n                E nval = put_edge(dfs(dfs, p.to), p.idx);\n                results[v].emplace_back(nval);\n\
    \                val = merge(val, nval);\n            }\n            return put_vertex(val,\
    \ v);\n        };\n\n        is_built = true;\n        return dfs(dfs, root);\n\
    \    }\n\n    // \u5168\u65B9\u4F4D\u6728DP\u3092\u884C\u3046\n    vector<V> reroot()\
    \ {\n        if(!is_built) build();\n        vector<E> parent_result(n);\n   \
    \     vector<V> ans(n);\n        parent_result[root] = e();\n\n        auto bfs\
    \ = [&](auto &&bfs, int now) -> void {\n            int child_num = results[now].size();\n\
    \            vector<E> lui(child_num + 1), rui(child_num + 1);\n            lui[0]\
    \ = e(), rui[child_num] = e();\n            for(int i = 0; i < child_num; i++)\
    \ lui[i + 1] = merge(lui[i], results[now][i]);\n            for(int i = child_num\
    \ - 1; i >= 0; i--) rui[i] = merge(results[now][i], rui[i + 1]);\n\n         \
    \   for(int i = 0; i < child_num; i++) {\n                const auto &edge = edges[now][i];\n\
    \                parent_result[edge.to] =\n                    put_edge(put_vertex(merge(merge(lui[i],\
    \ rui[i + 1]), parent_result[now]), now), edge.rev_idx);\n                bfs(bfs,\
    \ edge.to);\n            }\n\n            ans[now] = put_vertex(merge(lui.back(),\
    \ parent_result[now]), now);\n        };\n\n        bfs(bfs, root);\n        return\
    \ ans;\n    }\n\nprivate:\n    size_t n, root;\n    bool is_built = false;\n \
    \   vector<vector<edge>> edges;\n    vector<vector<E>> results;  // results[v][i]\
    \ := \uFF08\"\u9802\u70B9v\u304B\u3089\u51FA\u308Bi\u756A\u76EE\u306E\u8FBA\"\u304C\
    \u98DB\u3073\u51FA\u3057\u305F\u90E8\u5206\u6728\u3082\u3069\u304D\u306E\u8A08\
    \u7B97\u7D50\u679C\uFF09\n};\n\n\ntemplate <class E, class V> struct RDP {\n \
    \   static E merge(E a, E b) { return max(a, b); }\n    static E e() { return\
    \ 0; }\n    static E put_edge(V v, int e_index) { return v + 1; }\n    static\
    \ V put_vertex(E e, int v_index) { return e; }\n    using Type = class RerootingDP<E,\
    \ V, merge, e, put_edge, put_vertex>;\n};\n"
  dependsOn:
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/dp/rerooting.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/dp/rerooting.hpp
layout: document
redirect_from:
- /library/lib/dp/rerooting.hpp
- /library/lib/dp/rerooting.hpp.html
title: lib/dp/rerooting.hpp
---
