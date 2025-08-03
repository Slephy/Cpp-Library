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
    \    };\n};\n#line 4 \"lib/graph/low-link.hpp\"\n\n// \u7121\u5411\u30B0\u30E9\
    \u30D5 \u305F\u3060\u3057\u9023\u7D50\u30B0\u30E9\u30D5\u3067\u306A\u304F\u3066\
    \u3082\u3088\u3044\ntemplate <AdjListGraph Graph> class LowLink {\n    const Graph\
    \ &G;\n    vector<int> ord, low;\n    vector<int> aps;\n    vector<pair<int, int>>\
    \ bridges;\n\npublic:\n    LowLink(const Graph &G) : G(G), ord(G.size(), -1),\
    \ low(G.size(), -1) {\n        int iter = 0;\n        for(int i = 0; i < G.size();\
    \ i++) {\n            // \u3082\u3057\u9023\u7D50\u30B0\u30E9\u30D5\u306A\u3089\
    \u3001\u3053\u3053\u304B\u3089dfs\u95A2\u6570\u304C\u547C\u3073\u51FA\u3055\u308C\
    \u308B\u306E\u306F1\u5EA6\u3060\u3051\u3002\n            // \u9023\u7D50\u6210\
    \u5206\u306E\u500B\u6570\u3060\u3051\u3001\u3053\u3053\u304B\u3089dfs\u95A2\u6570\
    \u304C\u547C\u3073\u51FA\u3055\u308C\u308B\n            if(ord[i] == -1) dfs(i,\
    \ -1, iter);\n        }\n        sort(aps.begin(), aps.end());\n        sort(bridges.begin(),\
    \ bridges.end());\n    }\n\n    // \u95A2\u7BC0\u70B9\u306E\u914D\u5217\u3092\u8FD4\
    \u3059\n    vector<int> get_aps() { return aps; }\n\n    // \u6A4B\u3092\u7AEF\
    \u70B9\u306E\u7D44\u3067\u8868\u3057\u305F\u914D\u5217\u3092\u8FD4\u3059\n   \
    \ vector<pair<int, int>> get_bridges() { return bridges; }\n\nprivate:\n    void\
    \ dfs(int now, int par, int &iter) {\n        assert(ord[now] == -1);\n      \
    \  ord[now] = iter++;\n        low[now] = ord[now];\n        int child_num = 0;\n\
    \        bool is_aps = false;\n\n        for(auto nxt : G[now]) {\n          \
    \  if(nxt == par) continue;\n            if(ord[nxt] == -1) {  // \u9806\u65B9\
    \u5411\n                child_num++;\n                dfs(nxt, now, iter);\n \
    \               chmin(low[now], low[nxt]);\n                if(low[nxt] > ord[now])\
    \ bridges.emplace_back(min(now, nxt), max(now, nxt));\n                // \u95A2\
    \u7BC0\u70B9\u306E\u5224\u5B9A\u65B9\u6CD5\u306F\u3001\u305D\u308C\u304C\u6839\
    \u306A\u306E\u304B\u3069\u3046\u304B\u3067\u5909\u308F\u308B\n               \
    \ if(par != -1 && low[nxt] >= ord[now]) is_aps = true;\n            }\n      \
    \      else {  // \u5F8C\u9000\u8FBA\uFF08\u305F\u3060\u3057\u7956\u5148 -> \u5B50\
    \u5B6B\u306E\u65B9\u5411\u304B\u3082\u3057\u308C\u306A\u3044\uFF09\n         \
    \       chmin(low[now], ord[nxt]);\n            }\n        }\n\n        if(par\
    \ == -1 && child_num >= 2) is_aps = true;\n        if(is_aps) aps.emplace_back(now);\n\
    \        return;\n    }\n};\n"
  code: "#pragma once\n#include \"../concepts/graph_concept.hpp\"\n#include \"../core/core.hpp\"\
    \n\n// \u7121\u5411\u30B0\u30E9\u30D5 \u305F\u3060\u3057\u9023\u7D50\u30B0\u30E9\
    \u30D5\u3067\u306A\u304F\u3066\u3082\u3088\u3044\ntemplate <AdjListGraph Graph>\
    \ class LowLink {\n    const Graph &G;\n    vector<int> ord, low;\n    vector<int>\
    \ aps;\n    vector<pair<int, int>> bridges;\n\npublic:\n    LowLink(const Graph\
    \ &G) : G(G), ord(G.size(), -1), low(G.size(), -1) {\n        int iter = 0;\n\
    \        for(int i = 0; i < G.size(); i++) {\n            // \u3082\u3057\u9023\
    \u7D50\u30B0\u30E9\u30D5\u306A\u3089\u3001\u3053\u3053\u304B\u3089dfs\u95A2\u6570\
    \u304C\u547C\u3073\u51FA\u3055\u308C\u308B\u306E\u306F1\u5EA6\u3060\u3051\u3002\
    \n            // \u9023\u7D50\u6210\u5206\u306E\u500B\u6570\u3060\u3051\u3001\u3053\
    \u3053\u304B\u3089dfs\u95A2\u6570\u304C\u547C\u3073\u51FA\u3055\u308C\u308B\n\
    \            if(ord[i] == -1) dfs(i, -1, iter);\n        }\n        sort(aps.begin(),\
    \ aps.end());\n        sort(bridges.begin(), bridges.end());\n    }\n\n    //\
    \ \u95A2\u7BC0\u70B9\u306E\u914D\u5217\u3092\u8FD4\u3059\n    vector<int> get_aps()\
    \ { return aps; }\n\n    // \u6A4B\u3092\u7AEF\u70B9\u306E\u7D44\u3067\u8868\u3057\
    \u305F\u914D\u5217\u3092\u8FD4\u3059\n    vector<pair<int, int>> get_bridges()\
    \ { return bridges; }\n\nprivate:\n    void dfs(int now, int par, int &iter) {\n\
    \        assert(ord[now] == -1);\n        ord[now] = iter++;\n        low[now]\
    \ = ord[now];\n        int child_num = 0;\n        bool is_aps = false;\n\n  \
    \      for(auto nxt : G[now]) {\n            if(nxt == par) continue;\n      \
    \      if(ord[nxt] == -1) {  // \u9806\u65B9\u5411\n                child_num++;\n\
    \                dfs(nxt, now, iter);\n                chmin(low[now], low[nxt]);\n\
    \                if(low[nxt] > ord[now]) bridges.emplace_back(min(now, nxt), max(now,\
    \ nxt));\n                // \u95A2\u7BC0\u70B9\u306E\u5224\u5B9A\u65B9\u6CD5\u306F\
    \u3001\u305D\u308C\u304C\u6839\u306A\u306E\u304B\u3069\u3046\u304B\u3067\u5909\
    \u308F\u308B\n                if(par != -1 && low[nxt] >= ord[now]) is_aps = true;\n\
    \            }\n            else {  // \u5F8C\u9000\u8FBA\uFF08\u305F\u3060\u3057\
    \u7956\u5148 -> \u5B50\u5B6B\u306E\u65B9\u5411\u304B\u3082\u3057\u308C\u306A\u3044\
    \uFF09\n                chmin(low[now], ord[nxt]);\n            }\n        }\n\
    \n        if(par == -1 && child_num >= 2) is_aps = true;\n        if(is_aps) aps.emplace_back(now);\n\
    \        return;\n    }\n};\n"
  dependsOn:
  - lib/concepts/graph_concept.hpp
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/graph/low-link.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/graph/low-link.hpp
layout: document
redirect_from:
- /library/lib/graph/low-link.hpp
- /library/lib/graph/low-link.hpp.html
title: lib/graph/low-link.hpp
---
