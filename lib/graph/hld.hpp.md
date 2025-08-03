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
    \    };\n};\n#line 4 \"lib/graph/hld.hpp\"\n\ntemplate <AdjListGraph Graph> class\
    \ HeavyLightDecomposition {\nprivate:\n    Graph graph;\n    int n;  // \u9802\
    \u70B9\u6570\n    const int root;\n    vector<int> subtree_size;    // subtree_size[v]\
    \ := (\u9802\u70B9v\u3092\u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306E\u30B5\
    \u30A4\u30BA)\n    vector<int> preorder;        // \u884C\u304D\u304C\u3051\u9806\
    \n    vector<int> preorder_index;  // preorder_index[v] := \uFF08\u884C\u304D\u304C\
    \u3051\u9806\u306B\u304A\u3051\u308B\u9802\u70B9v\u306E\u30A4\u30F3\u30C7\u30C3\
    \u30AF\u30B9\uFF09\n    vector<int> parent;          // parent[v] := \uFF08\u9802\
    \u70B9v\u306E\u89AA, \u305F\u3060\u3057 parent[root] = -1\uFF09\n    vector<int>\
    \ head;            // head[v] := \uFF08\u9802\u70B9v\u304C\u5C5E\u3059\u308B heavy\
    \ path \u306E\u3046\u3061\u3001\u6700\u3082\u6839\u306B\u8FD1\u3044\u9802\u70B9\
    \uFF09\n    vector<int> depth;           // depth[v] :=\uFF08depth[root] = 0 \u3068\
    \u3057\u305F\u3068\u304D\u306E\u9802\u70B9v\u306E\u6DF1\u3055\uFF09\n\npublic:\n\
    \    HeavyLightDecomposition(const Graph &graph, int root = 0)\n        : graph(graph),\n\
    \          n(graph.size()),\n          root(root),\n          subtree_size(graph.size()),\n\
    \          preorder_index(graph.size()),\n          parent(graph.size()),\n  \
    \        head(graph.size()),\n          depth(graph.size()) {\n        init();\n\
    \    }\n\n    // u-v\u30D1\u30B9\u3092\u69CB\u6210\u3059\u308B\u9802\u70B9\u3092\
    \u3001\u884C\u304D\u304C\u3051\u9806\u3067\u306E\u533A\u9593\u306E\u914D\u5217\
    \u3067\u8FD4\u3059\n    vector<pair<int, int>> query(int u, int v) {\n       \
    \ assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n        vector<pair<int,\
    \ int>> ret;\n        while(head[u] != head[v]) {\n            if(depth[head[u]]\
    \ >= depth[head[v]]) {\n                ret.emplace_back(head[u], u);\n      \
    \          u = parent[head[u]];\n            }\n            else {\n         \
    \       ret.emplace_back(head[v], v);\n                v = parent[head[v]];\n\
    \            }\n        }\n\n        if(preorder_index[u] < preorder_index[v])\
    \ ret.emplace_back(u, v);\n        else ret.emplace_back(v, u);\n        for(auto\
    \ &[v1, v2] : ret) v1 = preorder_index[v1], v2 = preorder_index[v2];\n       \
    \ return ret;\n    };\n\n    vector<int> get_preorder() const { return preorder;\
    \ }\n\n    int get_preoder_index(int v) const { return preorder_index.at(v); }\n\
    \nprivate:\n    void init() {\n        dfs1(root, -1);\n        dfs2(root, -1);\n\
    \    }\n\n    // graph[now][0] \u304C heavy_child \u306B\u306A\u308B\u3088\u3046\
    \u306B swap\n    // depth, subtree_size \u3092\u69CB\u7BC9\n    int dfs1(int now,\
    \ int par) {\n        subtree_size[now] = 1;\n        if(now == root) depth[now]\
    \ = 0;\n        else depth[now] = depth[par] + 1;\n\n        for(auto &nxt : graph[now])\
    \ {\n            if(nxt == par) continue;\n            int sz = dfs1(nxt, now);\n\
    \            subtree_size[now] += sz;\n            if(sz > subtree_size[graph[now][0]])\
    \ swap(graph[now][0], nxt);\n        }\n        return subtree_size[now];\n  \
    \  };\n\n    // \u884C\u304D\u304C\u3051\u9806\u3092\u8A18\u9332\n    // parent,\
    \ head \u3092\u69CB\u7BC9\n    void dfs2(int now, int par) {\n        preorder_index[now]\
    \ = preorder.size();\n        preorder.emplace_back(now);\n        parent[now]\
    \ = par;\n\n        if(now == root) head[now] = now;\n        else head[now] =\
    \ (graph[par][0] == now) ? head[par] : now;\n\n        for(auto nxt : graph[now])\
    \ {\n            if(nxt == par) continue;\n            else dfs2(nxt, now);\n\
    \        }\n    };\n};\n"
  code: "#pragma once\n#include \"../concepts/graph_concept.hpp\"\n#include \"../core/core.hpp\"\
    \n\ntemplate <AdjListGraph Graph> class HeavyLightDecomposition {\nprivate:\n\
    \    Graph graph;\n    int n;  // \u9802\u70B9\u6570\n    const int root;\n  \
    \  vector<int> subtree_size;    // subtree_size[v] := (\u9802\u70B9v\u3092\u6839\
    \u3068\u3059\u308B\u90E8\u5206\u6728\u306E\u30B5\u30A4\u30BA)\n    vector<int>\
    \ preorder;        // \u884C\u304D\u304C\u3051\u9806\n    vector<int> preorder_index;\
    \  // preorder_index[v] := \uFF08\u884C\u304D\u304C\u3051\u9806\u306B\u304A\u3051\
    \u308B\u9802\u70B9v\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\uFF09\n    vector<int>\
    \ parent;          // parent[v] := \uFF08\u9802\u70B9v\u306E\u89AA, \u305F\u3060\
    \u3057 parent[root] = -1\uFF09\n    vector<int> head;            // head[v] :=\
    \ \uFF08\u9802\u70B9v\u304C\u5C5E\u3059\u308B heavy path \u306E\u3046\u3061\u3001\
    \u6700\u3082\u6839\u306B\u8FD1\u3044\u9802\u70B9\uFF09\n    vector<int> depth;\
    \           // depth[v] :=\uFF08depth[root] = 0 \u3068\u3057\u305F\u3068\u304D\
    \u306E\u9802\u70B9v\u306E\u6DF1\u3055\uFF09\n\npublic:\n    HeavyLightDecomposition(const\
    \ Graph &graph, int root = 0)\n        : graph(graph),\n          n(graph.size()),\n\
    \          root(root),\n          subtree_size(graph.size()),\n          preorder_index(graph.size()),\n\
    \          parent(graph.size()),\n          head(graph.size()),\n          depth(graph.size())\
    \ {\n        init();\n    }\n\n    // u-v\u30D1\u30B9\u3092\u69CB\u6210\u3059\u308B\
    \u9802\u70B9\u3092\u3001\u884C\u304D\u304C\u3051\u9806\u3067\u306E\u533A\u9593\
    \u306E\u914D\u5217\u3067\u8FD4\u3059\n    vector<pair<int, int>> query(int u,\
    \ int v) {\n        assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n\
    \        vector<pair<int, int>> ret;\n        while(head[u] != head[v]) {\n  \
    \          if(depth[head[u]] >= depth[head[v]]) {\n                ret.emplace_back(head[u],\
    \ u);\n                u = parent[head[u]];\n            }\n            else {\n\
    \                ret.emplace_back(head[v], v);\n                v = parent[head[v]];\n\
    \            }\n        }\n\n        if(preorder_index[u] < preorder_index[v])\
    \ ret.emplace_back(u, v);\n        else ret.emplace_back(v, u);\n        for(auto\
    \ &[v1, v2] : ret) v1 = preorder_index[v1], v2 = preorder_index[v2];\n       \
    \ return ret;\n    };\n\n    vector<int> get_preorder() const { return preorder;\
    \ }\n\n    int get_preoder_index(int v) const { return preorder_index.at(v); }\n\
    \nprivate:\n    void init() {\n        dfs1(root, -1);\n        dfs2(root, -1);\n\
    \    }\n\n    // graph[now][0] \u304C heavy_child \u306B\u306A\u308B\u3088\u3046\
    \u306B swap\n    // depth, subtree_size \u3092\u69CB\u7BC9\n    int dfs1(int now,\
    \ int par) {\n        subtree_size[now] = 1;\n        if(now == root) depth[now]\
    \ = 0;\n        else depth[now] = depth[par] + 1;\n\n        for(auto &nxt : graph[now])\
    \ {\n            if(nxt == par) continue;\n            int sz = dfs1(nxt, now);\n\
    \            subtree_size[now] += sz;\n            if(sz > subtree_size[graph[now][0]])\
    \ swap(graph[now][0], nxt);\n        }\n        return subtree_size[now];\n  \
    \  };\n\n    // \u884C\u304D\u304C\u3051\u9806\u3092\u8A18\u9332\n    // parent,\
    \ head \u3092\u69CB\u7BC9\n    void dfs2(int now, int par) {\n        preorder_index[now]\
    \ = preorder.size();\n        preorder.emplace_back(now);\n        parent[now]\
    \ = par;\n\n        if(now == root) head[now] = now;\n        else head[now] =\
    \ (graph[par][0] == now) ? head[par] : now;\n\n        for(auto nxt : graph[now])\
    \ {\n            if(nxt == par) continue;\n            else dfs2(nxt, now);\n\
    \        }\n    };\n};\n"
  dependsOn:
  - lib/concepts/graph_concept.hpp
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/graph/hld.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/graph/hld.hpp
layout: document
redirect_from:
- /library/lib/graph/hld.hpp
- /library/lib/graph/hld.hpp.html
title: lib/graph/hld.hpp
---
