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
    \ 3 \"lib/graph/shortest_cycle.hpp\"\nenum class graph_direction {\n    directed,\n\
    \    undirected,\n};\n\n// \u9802\u70B9root \u3092\u901A\u308B\u6700\u77ED\u9589\
    \u8DEF\u306E\u9577\u3055\u3092\u8FD4\u3059\uFF08\u5358\u7D14\u30B0\u30E9\u30D5\
    \u3092\u4EEE\u5B9A. \u540C\u3058\u9802\u70B9\u3092\u4E8C\u5EA6\u901A\u3089\u306A\
    \u3044\uFF09\n// \u9589\u8DEF\u304C\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F\
    wg.INF\u3092\u8FD4\u3059\ntemplate <class T> T shortest_cycle(const WeightedGraph<T>\
    \ &wg, graph_direction graph_dirc, int root) {\n    // root\u3092\u6839\u3068\u3059\
    \u308B\u6700\u77ED\u8DEF\u6728\u3092\u4F5C\u308B\n    vector<T> distance(wg.size,\
    \ wg.INF);\n    vector<int> label(wg.size);  // label[root] := root, label[i]\
    \ :=\n                                 // \uFF08\u6700\u77ED\u8DEF\u6728\u3067\
    i\u306E\u7956\u5148\u3067\u3042\u308B\u9802\u70B9\uFF08i\u3092\u542B\u3080\uFF09\
    \u306E\u3046\u3061\u3001\u6839\u306B\u6700\u3082\u8FD1\u3044\u3082\u306E\uFF09\
    \n    {\n        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,\
    \ greater<tuple<int, int, int>>> pq;\n        pq.emplace(0, root, root);\n   \
    \     while(!pq.empty()) {\n            auto [d, now, pre] = pq.top();\n     \
    \       pq.pop();\n            if(distance[now] < d) continue;\n            distance[now]\
    \ = d;\n            if(pre == root) label[now] = now;\n            else label[now]\
    \ = label[pre];\n\n            for(auto [nxt, cost] : wg[now]) {\n           \
    \     pq.emplace(d + cost, nxt, now);\n            }\n        }\n    }\n\n\n \
    \   // \u6700\u77ED\u9589\u8DEF\u3092\u898B\u3064\u3051\u308B\n    T min_cost\
    \ = wg.INF;\n    for(int from = 0; from < wg.size; from++) {\n        if(from\
    \ == root) continue;\n        if(distance[from] == wg.INF) continue;\n       \
    \ for(auto [to, cost] : wg[from]) {\n            if(distance[to] == wg.INF) continue;\n\
    \            if(graph_dirc == graph_direction::undirected) {\n               \
    \ if(label[from] == label[to]) continue;\n                if(to == root && label[from]\
    \ == from) continue;\n                else chmin(min_cost, distance[from] + distance[to]\
    \ + cost);\n            }\n            if(graph_dirc == graph_direction::directed)\
    \ {\n                if(to != root) continue;\n                else chmin(min_cost,\
    \ distance[from] + cost);\n            }\n        }\n    }\n\n    return min_cost;\n\
    }\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\nenum class graph_direction {\n\
    \    directed,\n    undirected,\n};\n\n// \u9802\u70B9root \u3092\u901A\u308B\u6700\
    \u77ED\u9589\u8DEF\u306E\u9577\u3055\u3092\u8FD4\u3059\uFF08\u5358\u7D14\u30B0\
    \u30E9\u30D5\u3092\u4EEE\u5B9A. \u540C\u3058\u9802\u70B9\u3092\u4E8C\u5EA6\u901A\
    \u3089\u306A\u3044\uFF09\n// \u9589\u8DEF\u304C\u5B58\u5728\u3057\u306A\u3044\u5834\
    \u5408\u306Fwg.INF\u3092\u8FD4\u3059\ntemplate <class T> T shortest_cycle(const\
    \ WeightedGraph<T> &wg, graph_direction graph_dirc, int root) {\n    // root\u3092\
    \u6839\u3068\u3059\u308B\u6700\u77ED\u8DEF\u6728\u3092\u4F5C\u308B\n    vector<T>\
    \ distance(wg.size, wg.INF);\n    vector<int> label(wg.size);  // label[root]\
    \ := root, label[i] :=\n                                 // \uFF08\u6700\u77ED\
    \u8DEF\u6728\u3067i\u306E\u7956\u5148\u3067\u3042\u308B\u9802\u70B9\uFF08i\u3092\
    \u542B\u3080\uFF09\u306E\u3046\u3061\u3001\u6839\u306B\u6700\u3082\u8FD1\u3044\
    \u3082\u306E\uFF09\n    {\n        priority_queue<tuple<int, int, int>, vector<tuple<int,\
    \ int, int>>, greater<tuple<int, int, int>>> pq;\n        pq.emplace(0, root,\
    \ root);\n        while(!pq.empty()) {\n            auto [d, now, pre] = pq.top();\n\
    \            pq.pop();\n            if(distance[now] < d) continue;\n        \
    \    distance[now] = d;\n            if(pre == root) label[now] = now;\n     \
    \       else label[now] = label[pre];\n\n            for(auto [nxt, cost] : wg[now])\
    \ {\n                pq.emplace(d + cost, nxt, now);\n            }\n        }\n\
    \    }\n\n\n    // \u6700\u77ED\u9589\u8DEF\u3092\u898B\u3064\u3051\u308B\n  \
    \  T min_cost = wg.INF;\n    for(int from = 0; from < wg.size; from++) {\n   \
    \     if(from == root) continue;\n        if(distance[from] == wg.INF) continue;\n\
    \        for(auto [to, cost] : wg[from]) {\n            if(distance[to] == wg.INF)\
    \ continue;\n            if(graph_dirc == graph_direction::undirected) {\n   \
    \             if(label[from] == label[to]) continue;\n                if(to ==\
    \ root && label[from] == from) continue;\n                else chmin(min_cost,\
    \ distance[from] + distance[to] + cost);\n            }\n            if(graph_dirc\
    \ == graph_direction::directed) {\n                if(to != root) continue;\n\
    \                else chmin(min_cost, distance[from] + cost);\n            }\n\
    \        }\n    }\n\n    return min_cost;\n}\n"
  dependsOn:
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/graph/shortest_cycle.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/graph/shortest_cycle.hpp
layout: document
redirect_from:
- /library/lib/graph/shortest_cycle.hpp
- /library/lib/graph/shortest_cycle.hpp.html
title: lib/graph/shortest_cycle.hpp
---
