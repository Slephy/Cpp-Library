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
    \ 3 \"lib/binary_indexed_tree/bit_2d.hpp\"\n// \u30A4\u30F3\u30BF\u30FC\u30D5\u30A7\
    \u30A4\u30B9\u306F 0-indexed \u534A\u958B\u533A\u9593\ntemplate <class T> class\
    \ BIT2D {\nprivate:\n    int H, W;\n    vector<vector<T>> bit;\n\npublic:\n  \
    \  // constructor\n    BIT2D(int H, int W) : H(H), W(W), bit(H + 1, vector<T>(W\
    \ + 1, 0)) {}\n\n    // O(logH * logW)\n    void add(int h, int w, T value) {\n\
    \        h++;\n        w++;\n        assert(1 <= h && h <= H);\n        assert(1\
    \ <= w && w <= W);\n        for(int i = h; i <= H; i += (i & (-i))) {\n      \
    \      for(int j = w; j <= W; j += (j & (-j))) {\n                bit[i][j] +=\
    \ value;\n            }\n        }\n        return;\n    }\n\n    // O(logH *\
    \ logW)\n    void set(int h, int w, T value) {\n        add(h, w, value - get(h,\
    \ w));\n        return;\n    }\n\n    // O(logH * logW)\n    // return value of\
    \ val[index]\n    T get(int h, int w) { return sum(h, w, h + 1, w + 1); }\n\n\
    \    // O(logH * logW)\n    // return sum of val[l, r)\n    T sum(int h1, int\
    \ w1, int h2, int w2) { return _sum(h2, w2) - _sum(h2, w1) - _sum(h1, w2) + _sum(h1,\
    \ w1); }\n    T sum(int h1, int w1) { return sum(h1, w1, H, W); }\n\nprivate:\n\
    \    // O(logH * logW)\n    // return sum of val[0, index)\n    T _sum(int h,\
    \ int w) {\n        T res = 0;\n        assert(0 <= h && h <= H);\n        assert(0\
    \ <= w && w <= W);\n        for(int i = h; i > 0; i -= (i & (-i))) {\n       \
    \     for(int j = w; j > 0; j -= (j & (-j))) {\n                res += bit[i][j];\n\
    \            }\n        }\n        return res;\n    }\n};\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\n// \u30A4\u30F3\u30BF\u30FC\u30D5\
    \u30A7\u30A4\u30B9\u306F 0-indexed \u534A\u958B\u533A\u9593\ntemplate <class T>\
    \ class BIT2D {\nprivate:\n    int H, W;\n    vector<vector<T>> bit;\n\npublic:\n\
    \    // constructor\n    BIT2D(int H, int W) : H(H), W(W), bit(H + 1, vector<T>(W\
    \ + 1, 0)) {}\n\n    // O(logH * logW)\n    void add(int h, int w, T value) {\n\
    \        h++;\n        w++;\n        assert(1 <= h && h <= H);\n        assert(1\
    \ <= w && w <= W);\n        for(int i = h; i <= H; i += (i & (-i))) {\n      \
    \      for(int j = w; j <= W; j += (j & (-j))) {\n                bit[i][j] +=\
    \ value;\n            }\n        }\n        return;\n    }\n\n    // O(logH *\
    \ logW)\n    void set(int h, int w, T value) {\n        add(h, w, value - get(h,\
    \ w));\n        return;\n    }\n\n    // O(logH * logW)\n    // return value of\
    \ val[index]\n    T get(int h, int w) { return sum(h, w, h + 1, w + 1); }\n\n\
    \    // O(logH * logW)\n    // return sum of val[l, r)\n    T sum(int h1, int\
    \ w1, int h2, int w2) { return _sum(h2, w2) - _sum(h2, w1) - _sum(h1, w2) + _sum(h1,\
    \ w1); }\n    T sum(int h1, int w1) { return sum(h1, w1, H, W); }\n\nprivate:\n\
    \    // O(logH * logW)\n    // return sum of val[0, index)\n    T _sum(int h,\
    \ int w) {\n        T res = 0;\n        assert(0 <= h && h <= H);\n        assert(0\
    \ <= w && w <= W);\n        for(int i = h; i > 0; i -= (i & (-i))) {\n       \
    \     for(int j = w; j > 0; j -= (j & (-j))) {\n                res += bit[i][j];\n\
    \            }\n        }\n        return res;\n    }\n};\n"
  dependsOn:
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/binary_indexed_tree/bit_2d.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/binary_indexed_tree/bit_2d.hpp
layout: document
redirect_from:
- /library/lib/binary_indexed_tree/bit_2d.hpp
- /library/lib/binary_indexed_tree/bit_2d.hpp.html
title: lib/binary_indexed_tree/bit_2d.hpp
---
