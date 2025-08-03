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
    \ 3 \"lib/dsu/potential_dsu.hpp\"\n// (path compression) + (union by size)\n//\
    \ \u53C2\u8003 AtCoder Library\n// == ACL\u304B\u3089\u306E\u5909\u66F4\u70B9\
    \ ==\n// \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u3092\u6271\u3046\u305F\u3081\u306B\
    \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\u5F15\u6570\u3084weight\u95A2\u6570\u3001\
    diff\u95A2\u6570\u3092\u8FFD\u52A0\n// merge\u95A2\u6570\u3068leadear\u95A2\u6570\
    \u306B\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u306E\u66F4\u65B0\u51E6\u7406\u3092\
    \u8FFD\u52A0\n// group_num() \u3092\u8FFD\u52A0\n// size\u95A2\u6570\u3092size_of_group\u95A2\
    \u6570\u306B\u6539\u540D\n// groups() \u306E\u8FD4\u308A\u5024\u304C\u6607\u9806\
    \u306B\u30BD\u30FC\u30C8\u6E08\u307F\u3067\u3042\u308B\u3053\u3068\u3092\u4FDD\
    \u8A3C\ntemplate <class T> class PotentialDSU {\n    int n;\n    int _group_num;\n\
    \    vector<int> parent_or_size;\n    vector<T> potential_diff;\n\npublic:\n \
    \   explicit PotentialDSU(size_t n) : n(n), _group_num(n), parent_or_size(n, -1),\
    \ potential_diff(n, 0) {}\n\n    // \u9802\u70B9 u, v \u3092\u7D50\u5408\u3057\
    \u3001\u305D\u308C\u3089\u306E\u65B0\u305F\u306A\u30EA\u30FC\u30C0\u30FC\u3092\
    \u8FD4\u3059\n    // w_u + w = w_v\u3068\u306A\u308B\u3088\u3046\u306B\u3059\u308B\
    \n    // \u3059\u306A\u308F\u3061\u9802\u70B9 u \u304B\u3089\u9802\u70B9 v \u3078\
    \u3001\u91CD\u307F w \u306E\u8FBA\u3092\u5F35\u308B\u30A4\u30E1\u30FC\u30B8\n\
    \    // O(\u03B1(N))\n    int merge(int u, int v, T w) {\n        assert(0 <=\
    \ u && u < n);\n        assert(0 <= v && v < n);\n        w += potential(u);\n\
    \        w -= potential(v);\n        u = leader(u);\n        v = leader(v);\n\
    \        if(u == v) return u;\n        if(-parent_or_size[u] < -parent_or_size[v])\
    \ {\n            swap(u, v);  // make size(u) >= size(v)\n            w = -w;\n\
    \        }\n        parent_or_size[u] += parent_or_size[v];\n        parent_or_size[v]\
    \ = u;\n        potential_diff[v] = w;\n        _group_num--;\n        return\
    \ u;\n    }\n\n    // \u9802\u70B9u, v\u304C\u540C\u3058\u9023\u7D50\u6210\u5206\
    \u306B\u5C5E\u3059\u308B\u304B\u3092\u5224\u5B9A\u3059\u308B\n    // O(\u03B1\
    (N))\n    bool same(int u, int v) {\n        assert(0 <= u && u < n);\n      \
    \  assert(0 <= v && v < n);\n        return leader(u) == leader(v);\n    }\n\n\
    \    // \u9802\u70B9v\u304C\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306E\u4EE3\
    \u8868\u3092\u8FD4\u3059\n    // O(\u03B1(N))\n    int leader(int v) {\n     \
    \   assert(0 <= v && v < n);\n        if(parent_or_size[v] < 0) return v;\n  \
    \      else {\n            int ld = leader(parent_or_size[v]);\n            potential_diff[v]\
    \ += potential_diff[parent_or_size[v]];\n            return parent_or_size[v]\
    \ = ld;\n        }\n    }\n\n    T potential(int v) {\n        assert(0 <= v &&\
    \ v < n);\n        leader(v);\n        return potential_diff[v];\n    }\n\n  \
    \  // potential(v) - potential(u) \u3092\u8FD4\u3059\n    // \u305F\u3060\u3057\
    u, v\u304C\u540C\u4E00\u306E\u9023\u7D50\u6210\u5206\u306B\u5C5E\u3057\u3066\u3044\
    \u308B\u3053\u3068\u3092\u8981\u6C42\u3059\u308B\n    // O(\u03B1(N))\n    T diff(int\
    \ u, int v) {\n        assert(0 <= u && u < n);\n        assert(0 <= v && v <\
    \ n);\n        assert(this->same(u, v));\n        return potential(v) - potential(u);\n\
    \    }\n\n    // \u9802\u70B9v\u304C\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\
    \u306E\u30B5\u30A4\u30BA\u3092\u8FD4\u3059\n    // O(\u03B1(N))\n    int size_of_group(int\
    \ v) {\n        assert(0 <= v && v < n);\n        return -parent_or_size[leader(v)];\n\
    \    }\n\n    // \u9023\u7D50\u6210\u5206\u306E\u500B\u6570\u3092\u8FD4\u3059\n\
    \    // \u8FD4\u308A\u5024\u306F groups().size()\u306B\u7B49\u3057\u3044\n   \
    \ // O(1)\n    int group_num() { return _group_num; }\n\n    // \u9023\u7D50\u6210\
    \u5206\u3054\u3068\u306E\u9802\u70B9\u60C5\u5831\u3092\u8FD4\u3059\n    // 1\u6B21\
    \u5143\u76EE\u30012\u6B21\u5143\u76EE\u3068\u3082\u306B\u6607\u9806\u3067\u30BD\
    \u30FC\u30C8\u6E08\u307F\n    // O(N)\n    vector<vector<int>> groups() {\n  \
    \      vector<vector<int>> result;\n        // \u9802\u70B9i\u3092\u30EA\u30FC\
    \u30C0\u30FC\u3068\u3059\u308B\u9023\u7D50\u6210\u5206\u304Cresult\u306B\u683C\
    \u7D0D\u3055\u308C\u308B\u3068\u304D\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\
    \n        vector<int> resultIndex(n, -1);\n\n        for(int i = 0; i < n; i++)\
    \ {\n            int ld = leader(i);\n            if(resultIndex[ld] == -1) {\
    \  // resultIndex \u304C\u672A\u5B9A\u306E\u3068\u304D\n                resultIndex[ld]\
    \ = result.size();\n                result.emplace_back();\n                result.back().reserve(size_of_group(ld));\n\
    \            }\n            result[resultIndex[ld]].emplace_back(i);\n       \
    \ }\n        return result;\n    }\n};\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\n// (path compression) + (union\
    \ by size)\n// \u53C2\u8003 AtCoder Library\n// == ACL\u304B\u3089\u306E\u5909\
    \u66F4\u70B9 ==\n// \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u3092\u6271\u3046\u305F\
    \u3081\u306B\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\u5F15\u6570\u3084weight\u95A2\
    \u6570\u3001diff\u95A2\u6570\u3092\u8FFD\u52A0\n// merge\u95A2\u6570\u3068leadear\u95A2\
    \u6570\u306B\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u306E\u66F4\u65B0\u51E6\u7406\
    \u3092\u8FFD\u52A0\n// group_num() \u3092\u8FFD\u52A0\n// size\u95A2\u6570\u3092\
    size_of_group\u95A2\u6570\u306B\u6539\u540D\n// groups() \u306E\u8FD4\u308A\u5024\
    \u304C\u6607\u9806\u306B\u30BD\u30FC\u30C8\u6E08\u307F\u3067\u3042\u308B\u3053\
    \u3068\u3092\u4FDD\u8A3C\ntemplate <class T> class PotentialDSU {\n    int n;\n\
    \    int _group_num;\n    vector<int> parent_or_size;\n    vector<T> potential_diff;\n\
    \npublic:\n    explicit PotentialDSU(size_t n) : n(n), _group_num(n), parent_or_size(n,\
    \ -1), potential_diff(n, 0) {}\n\n    // \u9802\u70B9 u, v \u3092\u7D50\u5408\u3057\
    \u3001\u305D\u308C\u3089\u306E\u65B0\u305F\u306A\u30EA\u30FC\u30C0\u30FC\u3092\
    \u8FD4\u3059\n    // w_u + w = w_v\u3068\u306A\u308B\u3088\u3046\u306B\u3059\u308B\
    \n    // \u3059\u306A\u308F\u3061\u9802\u70B9 u \u304B\u3089\u9802\u70B9 v \u3078\
    \u3001\u91CD\u307F w \u306E\u8FBA\u3092\u5F35\u308B\u30A4\u30E1\u30FC\u30B8\n\
    \    // O(\u03B1(N))\n    int merge(int u, int v, T w) {\n        assert(0 <=\
    \ u && u < n);\n        assert(0 <= v && v < n);\n        w += potential(u);\n\
    \        w -= potential(v);\n        u = leader(u);\n        v = leader(v);\n\
    \        if(u == v) return u;\n        if(-parent_or_size[u] < -parent_or_size[v])\
    \ {\n            swap(u, v);  // make size(u) >= size(v)\n            w = -w;\n\
    \        }\n        parent_or_size[u] += parent_or_size[v];\n        parent_or_size[v]\
    \ = u;\n        potential_diff[v] = w;\n        _group_num--;\n        return\
    \ u;\n    }\n\n    // \u9802\u70B9u, v\u304C\u540C\u3058\u9023\u7D50\u6210\u5206\
    \u306B\u5C5E\u3059\u308B\u304B\u3092\u5224\u5B9A\u3059\u308B\n    // O(\u03B1\
    (N))\n    bool same(int u, int v) {\n        assert(0 <= u && u < n);\n      \
    \  assert(0 <= v && v < n);\n        return leader(u) == leader(v);\n    }\n\n\
    \    // \u9802\u70B9v\u304C\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306E\u4EE3\
    \u8868\u3092\u8FD4\u3059\n    // O(\u03B1(N))\n    int leader(int v) {\n     \
    \   assert(0 <= v && v < n);\n        if(parent_or_size[v] < 0) return v;\n  \
    \      else {\n            int ld = leader(parent_or_size[v]);\n            potential_diff[v]\
    \ += potential_diff[parent_or_size[v]];\n            return parent_or_size[v]\
    \ = ld;\n        }\n    }\n\n    T potential(int v) {\n        assert(0 <= v &&\
    \ v < n);\n        leader(v);\n        return potential_diff[v];\n    }\n\n  \
    \  // potential(v) - potential(u) \u3092\u8FD4\u3059\n    // \u305F\u3060\u3057\
    u, v\u304C\u540C\u4E00\u306E\u9023\u7D50\u6210\u5206\u306B\u5C5E\u3057\u3066\u3044\
    \u308B\u3053\u3068\u3092\u8981\u6C42\u3059\u308B\n    // O(\u03B1(N))\n    T diff(int\
    \ u, int v) {\n        assert(0 <= u && u < n);\n        assert(0 <= v && v <\
    \ n);\n        assert(this->same(u, v));\n        return potential(v) - potential(u);\n\
    \    }\n\n    // \u9802\u70B9v\u304C\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\
    \u306E\u30B5\u30A4\u30BA\u3092\u8FD4\u3059\n    // O(\u03B1(N))\n    int size_of_group(int\
    \ v) {\n        assert(0 <= v && v < n);\n        return -parent_or_size[leader(v)];\n\
    \    }\n\n    // \u9023\u7D50\u6210\u5206\u306E\u500B\u6570\u3092\u8FD4\u3059\n\
    \    // \u8FD4\u308A\u5024\u306F groups().size()\u306B\u7B49\u3057\u3044\n   \
    \ // O(1)\n    int group_num() { return _group_num; }\n\n    // \u9023\u7D50\u6210\
    \u5206\u3054\u3068\u306E\u9802\u70B9\u60C5\u5831\u3092\u8FD4\u3059\n    // 1\u6B21\
    \u5143\u76EE\u30012\u6B21\u5143\u76EE\u3068\u3082\u306B\u6607\u9806\u3067\u30BD\
    \u30FC\u30C8\u6E08\u307F\n    // O(N)\n    vector<vector<int>> groups() {\n  \
    \      vector<vector<int>> result;\n        // \u9802\u70B9i\u3092\u30EA\u30FC\
    \u30C0\u30FC\u3068\u3059\u308B\u9023\u7D50\u6210\u5206\u304Cresult\u306B\u683C\
    \u7D0D\u3055\u308C\u308B\u3068\u304D\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\
    \n        vector<int> resultIndex(n, -1);\n\n        for(int i = 0; i < n; i++)\
    \ {\n            int ld = leader(i);\n            if(resultIndex[ld] == -1) {\
    \  // resultIndex \u304C\u672A\u5B9A\u306E\u3068\u304D\n                resultIndex[ld]\
    \ = result.size();\n                result.emplace_back();\n                result.back().reserve(size_of_group(ld));\n\
    \            }\n            result[resultIndex[ld]].emplace_back(i);\n       \
    \ }\n        return result;\n    }\n};\n"
  dependsOn:
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/dsu/potential_dsu.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/dsu/potential_dsu.hpp
layout: document
redirect_from:
- /library/lib/dsu/potential_dsu.hpp
- /library/lib/dsu/potential_dsu.hpp.html
title: lib/dsu/potential_dsu.hpp
---
