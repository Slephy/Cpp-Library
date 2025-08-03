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
    \    };\n};\n#line 4 \"lib/graph/centroid-decomposition.hpp\"\n\ntemplate <AdjListGraph\
    \ Graph> class CentroidDecomposition {\n    vector<bool> checked;\n    vector<size_t>\
    \ subtree_size;\n    const Graph &graph;\n\npublic:\n    CentroidDecomposition(const\
    \ Graph &graph)\n        : graph(graph), checked(graph.size(), false), subtree_size(graph.size(),\
    \ 0) {}\n\n    // \u4E0E\u3048\u3089\u308C\u305F\u30B0\u30E9\u30D5\u5168\u4F53\
    \u306E\u91CD\u5FC3\u3068\u3001\u91CD\u5FC3\u6728\u3092\u8FD4\u3057\u307E\u3059\
    \n    pair<int, vector<vector<int>>> build() {\n        vector<vector<int>> tree(graph.size());\n\
    \        return {build_dfs(0, tree), tree};\n    }\n\nprivate:\n    size_t calc_subtree_size(int\
    \ now, int par = -1) {\n        subtree_size[now] = 1;\n        for(auto nxt :\
    \ graph[now]) {\n            if(nxt == par || checked[nxt]) continue;\n      \
    \      subtree_size[now] += calc_subtree_size(nxt, now);\n        }\n        return\
    \ subtree_size[now];\n    }\n\n    int find_centroid(int now, size_t mid_size,\
    \ int par) {\n        for(auto nxt : graph[now]) {\n            if(nxt == par\
    \ || checked[nxt]) continue;\n            if(subtree_size[nxt] > mid_size) return\
    \ find_centroid(nxt, mid_size, now);\n        }\n        return now;\n    }\n\n\
    \    int build_dfs(int now, Graph &tree) {\n        int centroid = find_centroid(now,\
    \ calc_subtree_size(now, -1) / 2, -1);\n        checked[centroid] = true;\n  \
    \      for(auto nxt : graph[centroid]) {\n            if(checked[nxt]) continue;\n\
    \            tree[centroid].push_back(build_dfs(nxt, tree));\n        }\n    \
    \    return centroid;\n    }\n};\n"
  code: "#pragma once\n#include \"../concepts/graph_concept.hpp\"\n#include \"../core/core.hpp\"\
    \n\ntemplate <AdjListGraph Graph> class CentroidDecomposition {\n    vector<bool>\
    \ checked;\n    vector<size_t> subtree_size;\n    const Graph &graph;\n\npublic:\n\
    \    CentroidDecomposition(const Graph &graph)\n        : graph(graph), checked(graph.size(),\
    \ false), subtree_size(graph.size(), 0) {}\n\n    // \u4E0E\u3048\u3089\u308C\u305F\
    \u30B0\u30E9\u30D5\u5168\u4F53\u306E\u91CD\u5FC3\u3068\u3001\u91CD\u5FC3\u6728\
    \u3092\u8FD4\u3057\u307E\u3059\n    pair<int, vector<vector<int>>> build() {\n\
    \        vector<vector<int>> tree(graph.size());\n        return {build_dfs(0,\
    \ tree), tree};\n    }\n\nprivate:\n    size_t calc_subtree_size(int now, int\
    \ par = -1) {\n        subtree_size[now] = 1;\n        for(auto nxt : graph[now])\
    \ {\n            if(nxt == par || checked[nxt]) continue;\n            subtree_size[now]\
    \ += calc_subtree_size(nxt, now);\n        }\n        return subtree_size[now];\n\
    \    }\n\n    int find_centroid(int now, size_t mid_size, int par) {\n       \
    \ for(auto nxt : graph[now]) {\n            if(nxt == par || checked[nxt]) continue;\n\
    \            if(subtree_size[nxt] > mid_size) return find_centroid(nxt, mid_size,\
    \ now);\n        }\n        return now;\n    }\n\n    int build_dfs(int now, Graph\
    \ &tree) {\n        int centroid = find_centroid(now, calc_subtree_size(now, -1)\
    \ / 2, -1);\n        checked[centroid] = true;\n        for(auto nxt : graph[centroid])\
    \ {\n            if(checked[nxt]) continue;\n            tree[centroid].push_back(build_dfs(nxt,\
    \ tree));\n        }\n        return centroid;\n    }\n};\n"
  dependsOn:
  - lib/concepts/graph_concept.hpp
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/graph/centroid-decomposition.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/graph/centroid-decomposition.hpp
layout: document
redirect_from:
- /library/lib/graph/centroid-decomposition.hpp
- /library/lib/graph/centroid-decomposition.hpp.html
title: lib/graph/centroid-decomposition.hpp
---
