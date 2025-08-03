---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: lib/concepts/graph_concept.hpp
    title: lib/concepts/graph_concept.hpp
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
    \ 3 \"lib/concepts/graph_concept.hpp\"\ntemplate <typename T>\nconcept AdjListGraph\
    \ = std::convertible_to<typename T::value_type::value_type, int>;\n\ntemplate\
    \ <typename T>\nconcept AdjListWeightedGraph = requires(T graph) {\n    requires\
    \ AdjListGraph<T>;\n    requires requires(typename T::value_type::value_type edge)\
    \ {\n        { edge.to } -> std::convertible_to<int>;\n        edge.weight;\n\
    \    };\n};\n#line 4 \"lib/graph/lca.hpp\"\n\ntemplate <AdjListGraph Graph> class\
    \ LCA {\n    const Graph &graph;\n    const int n;\n    const int root;\n    const\
    \ int lg = 30;\n    vector<vector<int>> parent;\n    vector<int> dist;\n\npublic:\n\
    \    LCA(const Graph &graph, size_t root = 0)\n        : graph(graph), n(graph.size()),\
    \ root(root), parent(lg, vector<int>(n, -1)), dist(graph.size(), -1) {\n     \
    \   dfs(root, -1, 0);\n        // \u30C0\u30D6\u30EA\u30F3\u30B0\n        for(int\
    \ k = 0; k + 1 < lg; k++) {\n            for(int v = 0; v < n; v++) {\n      \
    \          if(parent[k][v] < 0) parent[k + 1][v] = -1;\n                else parent[k\
    \ + 1][v] = parent[k][parent[k][v]];\n            }\n        }\n    }\n\n\nprivate:\n\
    \    // \u6839\u304B\u3089\u306E\u8DDD\u96E2\u30681\u3064\u5148\u306E\u9802\u70B9\
    \u3092\u6C42\u3081\u308B\n    // dist \u3092\u521D\u671F\u5316\n    void dfs(int\
    \ now, int par, int d) {\n        parent[0][now] = par;\n        dist[now] = d;\n\
    \        for(auto nxt : graph[now]) {\n            if(nxt != par) dfs(nxt, now,\
    \ d + 1);\n        }\n    }\n\npublic:\n    // O(logV)\n    int query(int u, int\
    \ v) {\n        if(dist[u] < dist[v]) swap(u, v);  // u \u306E\u65B9\u304C\u6DF1\
    \u3044\u3068\u3059\u308B\n        // LCA \u307E\u3067\u306E\u8DDD\u96E2\u3092\u540C\
    \u3058\u306B\u3059\u308B\n        int diff = dist[u] - dist[v];\n        for(int\
    \ k = 0; k < lg; k++) {\n            if((diff >> k) & 1) {\n                u\
    \ = parent[k][u];\n            }\n        }\n        // \u4E8C\u5206\u63A2\u7D22\
    \u3067 LCA \u3092\u6C42\u3081\u308B\n        if(u == v) return u;\n        for(int\
    \ k = lg - 1; k >= 0; k--) {\n            if(parent[k][u] != parent[k][v]) {\n\
    \                u = parent[k][u];\n                v = parent[k][v];\n      \
    \      }\n        }\n        return parent[0][u];\n    }\n\n    // O(logV)\n \
    \   int get_dist(int u, int v) { return dist[u] + dist[v] - 2 * dist[query(u,\
    \ v)]; }\n\n    // O(logV)\n    // \u9802\u70B9a \u304Cu-v\u30D1\u30B9\u4E0A\u306B\
    \u5B58\u5728\u3059\u308B\u304B\u3092\u5224\u5B9A\u3059\u308B\n    bool is_on_path(int\
    \ u, int v, int a) { return get_dist(u, a) + get_dist(a, v) == get_dist(u, v);\
    \ }\n};\n"
  code: "#pragma once\n#include \"../concepts/graph_concept.hpp\"\n#include \"../core/core.hpp\"\
    \n\ntemplate <AdjListGraph Graph> class LCA {\n    const Graph &graph;\n    const\
    \ int n;\n    const int root;\n    const int lg = 30;\n    vector<vector<int>>\
    \ parent;\n    vector<int> dist;\n\npublic:\n    LCA(const Graph &graph, size_t\
    \ root = 0)\n        : graph(graph), n(graph.size()), root(root), parent(lg, vector<int>(n,\
    \ -1)), dist(graph.size(), -1) {\n        dfs(root, -1, 0);\n        // \u30C0\
    \u30D6\u30EA\u30F3\u30B0\n        for(int k = 0; k + 1 < lg; k++) {\n        \
    \    for(int v = 0; v < n; v++) {\n                if(parent[k][v] < 0) parent[k\
    \ + 1][v] = -1;\n                else parent[k + 1][v] = parent[k][parent[k][v]];\n\
    \            }\n        }\n    }\n\n\nprivate:\n    // \u6839\u304B\u3089\u306E\
    \u8DDD\u96E2\u30681\u3064\u5148\u306E\u9802\u70B9\u3092\u6C42\u3081\u308B\n  \
    \  // dist \u3092\u521D\u671F\u5316\n    void dfs(int now, int par, int d) {\n\
    \        parent[0][now] = par;\n        dist[now] = d;\n        for(auto nxt :\
    \ graph[now]) {\n            if(nxt != par) dfs(nxt, now, d + 1);\n        }\n\
    \    }\n\npublic:\n    // O(logV)\n    int query(int u, int v) {\n        if(dist[u]\
    \ < dist[v]) swap(u, v);  // u \u306E\u65B9\u304C\u6DF1\u3044\u3068\u3059\u308B\
    \n        // LCA \u307E\u3067\u306E\u8DDD\u96E2\u3092\u540C\u3058\u306B\u3059\u308B\
    \n        int diff = dist[u] - dist[v];\n        for(int k = 0; k < lg; k++) {\n\
    \            if((diff >> k) & 1) {\n                u = parent[k][u];\n      \
    \      }\n        }\n        // \u4E8C\u5206\u63A2\u7D22\u3067 LCA \u3092\u6C42\
    \u3081\u308B\n        if(u == v) return u;\n        for(int k = lg - 1; k >= 0;\
    \ k--) {\n            if(parent[k][u] != parent[k][v]) {\n                u =\
    \ parent[k][u];\n                v = parent[k][v];\n            }\n        }\n\
    \        return parent[0][u];\n    }\n\n    // O(logV)\n    int get_dist(int u,\
    \ int v) { return dist[u] + dist[v] - 2 * dist[query(u, v)]; }\n\n    // O(logV)\n\
    \    // \u9802\u70B9a \u304Cu-v\u30D1\u30B9\u4E0A\u306B\u5B58\u5728\u3059\u308B\
    \u304B\u3092\u5224\u5B9A\u3059\u308B\n    bool is_on_path(int u, int v, int a)\
    \ { return get_dist(u, a) + get_dist(a, v) == get_dist(u, v); }\n};\n"
  dependsOn:
  - lib/concepts/graph_concept.hpp
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/graph/lca.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/graph/lca.hpp
layout: document
redirect_from:
- /library/lib/graph/lca.hpp
- /library/lib/graph/lca.hpp.html
title: lib/graph/lca.hpp
---
