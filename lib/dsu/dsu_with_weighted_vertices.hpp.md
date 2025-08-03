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
    \ 3 \"lib/dsu/dsu_with_weighted_vertices.hpp\"\n// (path compression) + (union\
    \ by size)\n// \u53C2\u8003 AtCoder Library\n// == DSU\u304B\u3089\u306E\u5909\
    \u66F4\u70B9 ==\n// \u9802\u70B9\u306B\u91CD\u307F\u3092\u3082\u305F\u305B\u3066\
    \u3001\u9023\u7D50\u6210\u5206\u3054\u3068\u306E\u91CD\u307F\u306E\u548C\u3092\
    \ weight_sum() \u3067\u6C42\u3081\u308B\u3053\u3068\u304C\u3067\u304D\u308B\n\
    // size\u95A2\u6570\u3092size_of_group\u95A2\u6570\u306B\u6539\u540D\n// \u548C\
    \u3092\u6C42\u3081\u308B\u969B\u306E\u4E8C\u9805\u6F14\u7B97op\u306F\u30C6\u30F3\
    \u30D7\u30EC\u30FC\u30C8\u5F15\u6570\u3067\u6307\u5B9A\u3059\u308B\ntemplate <class\
    \ WeightType, void (*op)(WeightType &, WeightType &)> class DSUWithWeightedVertices\
    \ {\n    int n;\n    int _group_num;\n    vector<int> parent_or_size;\n    vector<WeightType>\
    \ weight;\n    vector<WeightType> weightSum;\n\npublic:\n    explicit DSUWithWeightedVertices(size_t\
    \ n)\n        : n(n), _group_num(n), parent_or_size(n, -1), weight(n, WeightType()),\
    \ weightSum(n, WeightType()) {}\n    explicit DSUWithWeightedVertices(const vector<WeightType>\
    \ &weight)\n        : n(weight.size()), _group_num(n), parent_or_size(n, -1),\
    \ weight(weight), weightSum(weight) {}\n\n\n    // \u9802\u70B9u, v\u3092\u7D50\
    \u5408\u3057\u3001\u305D\u308C\u3089\u306E\u65B0\u305F\u306A\u30EA\u30FC\u30C0\
    \u30FC\u3092\u8FD4\u3059\n    // O(\u03B1(N))\n    int merge(int u, int v) {\n\
    \        assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n        u\
    \ = leader(u);\n        v = leader(v);\n        if(u == v) return u;\n       \
    \ if(-parent_or_size[u] < -parent_or_size[v]) swap(u, v);  // make size(u) >=\
    \ size(v)\n        parent_or_size[u] += parent_or_size[v];\n        parent_or_size[v]\
    \ = u;\n        _group_num--;\n        op(weightSum[u], weightSum[v]);  // weightSum[u]\
    \ = weightSum[u] + weightSum[v]\n        return u;\n    }\n\n    // \u9802\u70B9\
    u, v\u304C\u540C\u3058\u9023\u7D50\u6210\u5206\u306B\u5C5E\u3059\u308B\u304B\u3092\
    \u5224\u5B9A\u3059\u308B\n    // O(\u03B1(N))\n    bool same(int u, int v) {\n\
    \        assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n        return\
    \ leader(u) == leader(v);\n    }\n\n    // \u9802\u70B9v\u304C\u5C5E\u3059\u308B\
    \u9023\u7D50\u6210\u5206\u306E\u4EE3\u8868\u3092\u8FD4\u3059\n    // O(\u03B1\
    (N))\n    int leader(int v) {\n        assert(0 <= v && v < n);\n        if(parent_or_size[v]\
    \ < 0) return v;\n        else return parent_or_size[v] = leader(parent_or_size[v]);\n\
    \    }\n\n    // \u9802\u70B9v\u304C\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\
    \u306E\u30B5\u30A4\u30BA\u3092\u8FD4\u3059\n    // O(\u03B1(N))\n    int size_of_group(int\
    \ v) {\n        assert(0 <= v && v < n);\n        return -parent_or_size[leader(v)];\n\
    \    }\n\n    // \u9023\u7D50\u6210\u5206\u306E\u500B\u6570\u3092\u8FD4\u3059\n\
    \    // \u8FD4\u308A\u5024\u306F groups().size()\u306B\u7B49\u3057\u3044\n   \
    \ // O(1)\n    int group_num() { return _group_num; }\n\n    // \u9802\u70B9v\u304C\
    \u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306E\u91CD\u307F\u306E\u548C\u3092\
    \u8FD4\u3059\n    // O(\u03B1(N))\n    const WeightType &weight_sum(int v) {\n\
    \        assert(0 <= v && v < n);\n        return weightSum[leader(v)];\n    }\n\
    \n    // // \u9802\u70B9v\u306E\u91CD\u307F\u306Bw\u3092\u52A0\u3048\u308B\n \
    \   // // O(\u03B1(N))\n    // void add_weight(int v, const WeightType &w){\n\
    \    //     assert(0 <= v && v < n);\n    //     weight[v] += w;\n    //     weightSum[leader(v)]\
    \ += w;\n    // }\n\n    // // \u9802\u70B9v\u306E\u91CD\u307F\u3092w\u306B\u5909\
    \u66F4\u3059\u308B\n    // // O(\u03B1(N))\n    // void set_weight(int v, const\
    \ WeightType &w){\n    //     assert(0 <= v && v < n);\n    //     add_weight(v,\
    \ w - weight[v]);\n    // }\n\n    // \u9023\u7D50\u6210\u5206\u3054\u3068\u306E\
    \u9802\u70B9\u60C5\u5831\u3092\u8FD4\u3059\n    // 1\u6B21\u5143\u76EE\u30012\u6B21\
    \u5143\u76EE\u3068\u3082\u306B\u6607\u9806\u3067\u30BD\u30FC\u30C8\u6E08\u307F\
    \n    // O(N)\n    vector<vector<int>> groups() {\n        vector<vector<int>>\
    \ result;\n        // \u9802\u70B9i\u3092\u30EA\u30FC\u30C0\u30FC\u3068\u3059\u308B\
    \u9023\u7D50\u6210\u5206\u304Cresult\u306B\u683C\u7D0D\u3055\u308C\u308B\u3068\
    \u304D\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n        vector<int> resultIndex(n,\
    \ -1);\n\n        for(int i = 0; i < n; i++) {\n            int ld = leader(i);\n\
    \            if(resultIndex[ld] == -1) {  // resultIndex \u304C\u672A\u5B9A\u306E\
    \u3068\u304D\n                resultIndex[ld] = result.size();\n             \
    \   result.emplace_back();\n                result.back().reserve(size_of_group(ld));\n\
    \            }\n            result[resultIndex[ld]].emplace_back(i);\n       \
    \ }\n        return result;\n    }\n};\n\n// merge_weight_to_l \u306F l + r \u3092\
    \ l \u306B\u683C\u7D0D\u3059\u308B\u95A2\u6570\ntemplate <class WeightType> struct\
    \ DSU_add {\n    static void merge_weight_to_l(WeightType &l, WeightType &r) {\
    \ l = l + r; };\n    using Type = struct DSUWithWeightedVertices<WeightType, merge_weight_to_l>;\n\
    };\ntemplate <class WeightType> struct DSU_map_add {\n    static void merge_weight_to_l(WeightType\
    \ &l, WeightType &r) {\n        if(l.size() < r.size()) swap(l, r);\n        //\
    \ \u2705 l.size() >= r.size()\n        for(auto &[key, val] : r) l[key] += val;\n\
    \    };\n    using Type = struct DSUWithWeightedVertices<WeightType, merge_weight_to_l>;\n\
    };\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\n// (path compression) + (union\
    \ by size)\n// \u53C2\u8003 AtCoder Library\n// == DSU\u304B\u3089\u306E\u5909\
    \u66F4\u70B9 ==\n// \u9802\u70B9\u306B\u91CD\u307F\u3092\u3082\u305F\u305B\u3066\
    \u3001\u9023\u7D50\u6210\u5206\u3054\u3068\u306E\u91CD\u307F\u306E\u548C\u3092\
    \ weight_sum() \u3067\u6C42\u3081\u308B\u3053\u3068\u304C\u3067\u304D\u308B\n\
    // size\u95A2\u6570\u3092size_of_group\u95A2\u6570\u306B\u6539\u540D\n// \u548C\
    \u3092\u6C42\u3081\u308B\u969B\u306E\u4E8C\u9805\u6F14\u7B97op\u306F\u30C6\u30F3\
    \u30D7\u30EC\u30FC\u30C8\u5F15\u6570\u3067\u6307\u5B9A\u3059\u308B\ntemplate <class\
    \ WeightType, void (*op)(WeightType &, WeightType &)> class DSUWithWeightedVertices\
    \ {\n    int n;\n    int _group_num;\n    vector<int> parent_or_size;\n    vector<WeightType>\
    \ weight;\n    vector<WeightType> weightSum;\n\npublic:\n    explicit DSUWithWeightedVertices(size_t\
    \ n)\n        : n(n), _group_num(n), parent_or_size(n, -1), weight(n, WeightType()),\
    \ weightSum(n, WeightType()) {}\n    explicit DSUWithWeightedVertices(const vector<WeightType>\
    \ &weight)\n        : n(weight.size()), _group_num(n), parent_or_size(n, -1),\
    \ weight(weight), weightSum(weight) {}\n\n\n    // \u9802\u70B9u, v\u3092\u7D50\
    \u5408\u3057\u3001\u305D\u308C\u3089\u306E\u65B0\u305F\u306A\u30EA\u30FC\u30C0\
    \u30FC\u3092\u8FD4\u3059\n    // O(\u03B1(N))\n    int merge(int u, int v) {\n\
    \        assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n        u\
    \ = leader(u);\n        v = leader(v);\n        if(u == v) return u;\n       \
    \ if(-parent_or_size[u] < -parent_or_size[v]) swap(u, v);  // make size(u) >=\
    \ size(v)\n        parent_or_size[u] += parent_or_size[v];\n        parent_or_size[v]\
    \ = u;\n        _group_num--;\n        op(weightSum[u], weightSum[v]);  // weightSum[u]\
    \ = weightSum[u] + weightSum[v]\n        return u;\n    }\n\n    // \u9802\u70B9\
    u, v\u304C\u540C\u3058\u9023\u7D50\u6210\u5206\u306B\u5C5E\u3059\u308B\u304B\u3092\
    \u5224\u5B9A\u3059\u308B\n    // O(\u03B1(N))\n    bool same(int u, int v) {\n\
    \        assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n        return\
    \ leader(u) == leader(v);\n    }\n\n    // \u9802\u70B9v\u304C\u5C5E\u3059\u308B\
    \u9023\u7D50\u6210\u5206\u306E\u4EE3\u8868\u3092\u8FD4\u3059\n    // O(\u03B1\
    (N))\n    int leader(int v) {\n        assert(0 <= v && v < n);\n        if(parent_or_size[v]\
    \ < 0) return v;\n        else return parent_or_size[v] = leader(parent_or_size[v]);\n\
    \    }\n\n    // \u9802\u70B9v\u304C\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\
    \u306E\u30B5\u30A4\u30BA\u3092\u8FD4\u3059\n    // O(\u03B1(N))\n    int size_of_group(int\
    \ v) {\n        assert(0 <= v && v < n);\n        return -parent_or_size[leader(v)];\n\
    \    }\n\n    // \u9023\u7D50\u6210\u5206\u306E\u500B\u6570\u3092\u8FD4\u3059\n\
    \    // \u8FD4\u308A\u5024\u306F groups().size()\u306B\u7B49\u3057\u3044\n   \
    \ // O(1)\n    int group_num() { return _group_num; }\n\n    // \u9802\u70B9v\u304C\
    \u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306E\u91CD\u307F\u306E\u548C\u3092\
    \u8FD4\u3059\n    // O(\u03B1(N))\n    const WeightType &weight_sum(int v) {\n\
    \        assert(0 <= v && v < n);\n        return weightSum[leader(v)];\n    }\n\
    \n    // // \u9802\u70B9v\u306E\u91CD\u307F\u306Bw\u3092\u52A0\u3048\u308B\n \
    \   // // O(\u03B1(N))\n    // void add_weight(int v, const WeightType &w){\n\
    \    //     assert(0 <= v && v < n);\n    //     weight[v] += w;\n    //     weightSum[leader(v)]\
    \ += w;\n    // }\n\n    // // \u9802\u70B9v\u306E\u91CD\u307F\u3092w\u306B\u5909\
    \u66F4\u3059\u308B\n    // // O(\u03B1(N))\n    // void set_weight(int v, const\
    \ WeightType &w){\n    //     assert(0 <= v && v < n);\n    //     add_weight(v,\
    \ w - weight[v]);\n    // }\n\n    // \u9023\u7D50\u6210\u5206\u3054\u3068\u306E\
    \u9802\u70B9\u60C5\u5831\u3092\u8FD4\u3059\n    // 1\u6B21\u5143\u76EE\u30012\u6B21\
    \u5143\u76EE\u3068\u3082\u306B\u6607\u9806\u3067\u30BD\u30FC\u30C8\u6E08\u307F\
    \n    // O(N)\n    vector<vector<int>> groups() {\n        vector<vector<int>>\
    \ result;\n        // \u9802\u70B9i\u3092\u30EA\u30FC\u30C0\u30FC\u3068\u3059\u308B\
    \u9023\u7D50\u6210\u5206\u304Cresult\u306B\u683C\u7D0D\u3055\u308C\u308B\u3068\
    \u304D\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n        vector<int> resultIndex(n,\
    \ -1);\n\n        for(int i = 0; i < n; i++) {\n            int ld = leader(i);\n\
    \            if(resultIndex[ld] == -1) {  // resultIndex \u304C\u672A\u5B9A\u306E\
    \u3068\u304D\n                resultIndex[ld] = result.size();\n             \
    \   result.emplace_back();\n                result.back().reserve(size_of_group(ld));\n\
    \            }\n            result[resultIndex[ld]].emplace_back(i);\n       \
    \ }\n        return result;\n    }\n};\n\n// merge_weight_to_l \u306F l + r \u3092\
    \ l \u306B\u683C\u7D0D\u3059\u308B\u95A2\u6570\ntemplate <class WeightType> struct\
    \ DSU_add {\n    static void merge_weight_to_l(WeightType &l, WeightType &r) {\
    \ l = l + r; };\n    using Type = struct DSUWithWeightedVertices<WeightType, merge_weight_to_l>;\n\
    };\ntemplate <class WeightType> struct DSU_map_add {\n    static void merge_weight_to_l(WeightType\
    \ &l, WeightType &r) {\n        if(l.size() < r.size()) swap(l, r);\n        //\
    \ \u2705 l.size() >= r.size()\n        for(auto &[key, val] : r) l[key] += val;\n\
    \    };\n    using Type = struct DSUWithWeightedVertices<WeightType, merge_weight_to_l>;\n\
    };\n"
  dependsOn:
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/dsu/dsu_with_weighted_vertices.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/dsu/dsu_with_weighted_vertices.hpp
layout: document
redirect_from:
- /library/lib/dsu/dsu_with_weighted_vertices.hpp
- /library/lib/dsu/dsu_with_weighted_vertices.hpp.html
title: lib/dsu/dsu_with_weighted_vertices.hpp
---
