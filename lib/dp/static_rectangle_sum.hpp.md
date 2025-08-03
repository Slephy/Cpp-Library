---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: lib/binary_indexed_tree/bit.hpp
    title: lib/binary_indexed_tree/bit.hpp
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
    \ 3 \"lib/binary_indexed_tree/bit.hpp\"\n// \u30A4\u30F3\u30BF\u30FC\u30D5\u30A7\
    \u30FC\u30B9\u306F 0-indexed \u534A\u958B\u533A\u9593\ntemplate <class T> class\
    \ BIT {\nprivate:\n    int n;\n    vector<T> bit;\n\npublic:\n    // constructor\n\
    \    BIT(int n) : n(n), bit(n + 1, 0) {}\n\n    // O(logN)\n    void add(int index,\
    \ T value) {\n        index++;\n        assert(1 <= index && index <= n);\n  \
    \      for(int i = index; i <= n; i += (i & (-i))) {\n            bit[i] += value;\n\
    \        }\n        return;\n    }\n\n    // O(logN)\n    void set(int index,\
    \ T value) {\n        add(index, value - get(index));\n        return;\n    }\n\
    \n    // O(logN)\n    // return value of val[index]\n    T get(int index) const\
    \ { return sum(index, index + 1); }\n\n    // O(logN)\n    // return sum of val[l,\
    \ r)\n    T sum(int l, int r) const { return _sum(r) - _sum(l); }\n    T sum(int\
    \ l) const { return sum(l, n); }\n\n    size_t size() const { return n; }\n\n\
    \    friend ostream &operator<<(ostream &o, const BIT<T> &bit) {\n        for(int\
    \ i = 0; i < bit.n; i++) {\n            o << bit.sum(i, i + 1) << (i + 1 == bit.n\
    \ ? ELM_SEP : \" \");\n        }\n        return o;\n    }\n\nprivate:\n    //\
    \ O(logN)\n    // return sum of val[0, index)\n    T _sum(int index) const {\n\
    \        T res = 0;\n        assert(0 <= index && index <= n);\n        for(int\
    \ i = index; i > 0; i -= (i & (-i))) {\n            res += bit[i];\n        }\n\
    \        return res;\n    }\n};\n#line 4 \"lib/dp/static_rectangle_sum.hpp\"\n\
    // N\u56DE\u306E\u70B9\u8FFD\u52A0\u30AF\u30A8\u30EA\u306E\u5F8C\u3067\u3001Q\u56DE\
    \u306E\u77E9\u5F62\u30AF\u30A8\u30EA\u3092\u51E6\u7406\u3059\u308B\n// PosType:\
    \ \u5EA7\u6A19\u306E\u578B(int, double\u7B49)\n// WeightType: \u91CD\u307F\u306E\
    \u578B\n// @need BIT\ntemplate <totally_ordered PosType, class WeightType> class\
    \ StaticRectangleSum {\npublic:\n    StaticRectangleSum() {}\n    StaticRectangleSum(const\
    \ vector<tuple<PosType, PosType, WeightType>> &points,\n                     \
    \  const vector<tuple<PosType, PosType, PosType, PosType>> &queries)\n       \
    \ : points(points), queries(queries) {}\n\n    // \u70B9(x, y) \u306B\u91CD\u307F\
    \ w \u3092\u8FFD\u52A0\n    void add_point(PosType x, PosType y, WeightType w)\
    \ { points.emplace_back(x, y, w); }\n\n    // [l, r) \xD7 [d, u) \u306E\u7BC4\u56F2\
    \u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B\u30AF\u30A8\u30EA\u3092\u8FFD\u52A0\
    \n    void add_query(PosType l, PosType d, PosType r, PosType u) { queries.emplace_back(l,\
    \ d, r, u); }\n\n    // \u30AF\u30A8\u30EA\u3092\u89E3\u304F\n    // \u8FD4\u308A\
    \u5024: \u5404\u30AF\u30A8\u30EA\u306E\u7B54\u3048\uFF08\u30AF\u30A8\u30EA\u306E\
    \u633F\u5165\u9806\uFF09\n    // O(NlogN + QlogQ)\n    vector<WeightType> solve()\
    \ {\n        const int n = points.size();\n        const int q = queries.size();\n\
    \n        // Y\u8EF8\u3092\u5EA7\u6A19\u5727\u7E2E\n        vector<PosType> ys;\n\
    \        ys.reserve(n + 2 * q);\n        for(const auto &[x, y, w] : points) {\n\
    \            ys.emplace_back(y);\n        }\n        for(const auto &[l, d, r,\
    \ u] : queries) {\n            ys.emplace_back(d);\n            ys.emplace_back(u);\n\
    \        }\n        ranges::sort(ys);\n        ys.erase(unique(ys.begin(), ys.end()),\
    \ ys.end());\n\n        // \u30BD\u30FC\u30C8\n        ranges::sort(points, [&](const\
    \ auto &a, const auto &b) { return get<0>(a) < get<0>(b); });\n        vector<pair<PosType,\
    \ int>> qs;\n        for(int i = 0; i < q; i++) {\n            const auto &[l,\
    \ d, r, u] = queries[i];\n            qs.emplace_back(l, i);\n            qs.emplace_back(r,\
    \ i + q);\n        }\n        ranges::sort(qs);\n\n        // \u30AF\u30A8\u30EA\
    \u51E6\u7406\n        vector<WeightType> ans(q, WeightType(0));\n        BIT<WeightType>\
    \ bit(ys.size());\n        auto get_y = [&](ll y) -> ll { return ranges::lower_bound(ys,\
    \ y) - ys.begin(); };\n        for(int iter = 0; auto [x, qid] : qs) {\n     \
    \       while(iter < points.size() && get<0>(points[iter]) < x) {\n          \
    \      auto [_, y, w] = points[iter];\n                bit.add(get_y(y), w);\n\
    \                iter++;\n            }\n\n            bool is_left = qid < q;\n\
    \            if(qid >= q) qid -= q;\n            auto [l, d, r, u] = queries[qid];\n\
    \            auto sum = bit.sum(get_y(d), get_y(u));\n            ans[qid] +=\
    \ is_left ? -sum : sum;\n        }\n        return ans;\n    }\n\nprivate:\n \
    \   vector<tuple<PosType, PosType, WeightType>> points;\n    vector<tuple<PosType,\
    \ PosType, PosType, PosType>> queries;\n};\n"
  code: "#pragma once\n#include \"../binary_indexed_tree/bit.hpp\"\n#include \"../core/core.hpp\"\
    \n// N\u56DE\u306E\u70B9\u8FFD\u52A0\u30AF\u30A8\u30EA\u306E\u5F8C\u3067\u3001\
    Q\u56DE\u306E\u77E9\u5F62\u30AF\u30A8\u30EA\u3092\u51E6\u7406\u3059\u308B\n//\
    \ PosType: \u5EA7\u6A19\u306E\u578B(int, double\u7B49)\n// WeightType: \u91CD\u307F\
    \u306E\u578B\n// @need BIT\ntemplate <totally_ordered PosType, class WeightType>\
    \ class StaticRectangleSum {\npublic:\n    StaticRectangleSum() {}\n    StaticRectangleSum(const\
    \ vector<tuple<PosType, PosType, WeightType>> &points,\n                     \
    \  const vector<tuple<PosType, PosType, PosType, PosType>> &queries)\n       \
    \ : points(points), queries(queries) {}\n\n    // \u70B9(x, y) \u306B\u91CD\u307F\
    \ w \u3092\u8FFD\u52A0\n    void add_point(PosType x, PosType y, WeightType w)\
    \ { points.emplace_back(x, y, w); }\n\n    // [l, r) \xD7 [d, u) \u306E\u7BC4\u56F2\
    \u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B\u30AF\u30A8\u30EA\u3092\u8FFD\u52A0\
    \n    void add_query(PosType l, PosType d, PosType r, PosType u) { queries.emplace_back(l,\
    \ d, r, u); }\n\n    // \u30AF\u30A8\u30EA\u3092\u89E3\u304F\n    // \u8FD4\u308A\
    \u5024: \u5404\u30AF\u30A8\u30EA\u306E\u7B54\u3048\uFF08\u30AF\u30A8\u30EA\u306E\
    \u633F\u5165\u9806\uFF09\n    // O(NlogN + QlogQ)\n    vector<WeightType> solve()\
    \ {\n        const int n = points.size();\n        const int q = queries.size();\n\
    \n        // Y\u8EF8\u3092\u5EA7\u6A19\u5727\u7E2E\n        vector<PosType> ys;\n\
    \        ys.reserve(n + 2 * q);\n        for(const auto &[x, y, w] : points) {\n\
    \            ys.emplace_back(y);\n        }\n        for(const auto &[l, d, r,\
    \ u] : queries) {\n            ys.emplace_back(d);\n            ys.emplace_back(u);\n\
    \        }\n        ranges::sort(ys);\n        ys.erase(unique(ys.begin(), ys.end()),\
    \ ys.end());\n\n        // \u30BD\u30FC\u30C8\n        ranges::sort(points, [&](const\
    \ auto &a, const auto &b) { return get<0>(a) < get<0>(b); });\n        vector<pair<PosType,\
    \ int>> qs;\n        for(int i = 0; i < q; i++) {\n            const auto &[l,\
    \ d, r, u] = queries[i];\n            qs.emplace_back(l, i);\n            qs.emplace_back(r,\
    \ i + q);\n        }\n        ranges::sort(qs);\n\n        // \u30AF\u30A8\u30EA\
    \u51E6\u7406\n        vector<WeightType> ans(q, WeightType(0));\n        BIT<WeightType>\
    \ bit(ys.size());\n        auto get_y = [&](ll y) -> ll { return ranges::lower_bound(ys,\
    \ y) - ys.begin(); };\n        for(int iter = 0; auto [x, qid] : qs) {\n     \
    \       while(iter < points.size() && get<0>(points[iter]) < x) {\n          \
    \      auto [_, y, w] = points[iter];\n                bit.add(get_y(y), w);\n\
    \                iter++;\n            }\n\n            bool is_left = qid < q;\n\
    \            if(qid >= q) qid -= q;\n            auto [l, d, r, u] = queries[qid];\n\
    \            auto sum = bit.sum(get_y(d), get_y(u));\n            ans[qid] +=\
    \ is_left ? -sum : sum;\n        }\n        return ans;\n    }\n\nprivate:\n \
    \   vector<tuple<PosType, PosType, WeightType>> points;\n    vector<tuple<PosType,\
    \ PosType, PosType, PosType>> queries;\n};\n"
  dependsOn:
  - lib/binary_indexed_tree/bit.hpp
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/dp/static_rectangle_sum.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/dp/static_rectangle_sum.hpp
layout: document
redirect_from:
- /library/lib/dp/static_rectangle_sum.hpp
- /library/lib/dp/static_rectangle_sum.hpp.html
title: lib/dp/static_rectangle_sum.hpp
---
