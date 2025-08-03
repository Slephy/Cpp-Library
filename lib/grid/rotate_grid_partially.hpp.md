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
    \ 3 \"lib/grid/rotate_grid_partially.hpp\"\n// (si, sj) \u3092\u5DE6\u4E0A\u7AEF\
    \u3068\u3059\u308B rh x rw \u306E\u77E9\u5F62\u3092\u53CD\u6642\u8A08\u56DE\u308A\
    \u306B deg \u5EA6\u56DE\u8EE2\u3059\u308B\n// deg \u306F 90 \u306E\u500D\u6570\
    \u306B\u9650\u308B\ntemplate <class T> void rotate_grid_partially(vector<vector<T>>\
    \ &vec, int si, int sj, int rh, int rw, int deg) {\n    const int H = vec.size();\n\
    \    const int W = vec[0].size();\n    assert(0 <= si && si < H);\n    assert(0\
    \ <= sj && sj < W);\n    assert(0 <= si + rh - 1 && si + rh - 1 < H);\n    assert(0\
    \ <= sj + rw - 1 && sj + rw - 1 < W);\n\n    if(deg < 0 || 360 <= deg) deg %=\
    \ 360;\n    if(deg < 0) deg += 360;\n    assert(deg == 0 || deg == 90 || deg ==\
    \ 180 || deg == 270);\n\n    // 90\u5EA6\u56DE\u8EE2\u3001270\u5EA6\u56DE\u8EE2\
    \u306E\u5834\u5408\u306F\u6B63\u65B9\u5F62\u3067\u306A\u3051\u308C\u3070\u306A\
    \u3089\u306A\u3044\n    if(deg == 90 || deg == 270) assert(rh == rw);\n\n    if(deg\
    \ == 0) return;\n\n    vector<vector<T>> tmp(rh, vector<T>(rw));\n    for(int\
    \ i = 0; i < rh; i++) {\n        for(int j = 0; j < rw; j++) {\n            switch(deg)\
    \ {\n                case 90: tmp[i][j] = vec[si + j][sj + rh - i - 1]; break;\n\
    \                case 180: tmp[i][j] = vec[si + rh - i - 1][sj + rw - j - 1];\
    \ break;\n                case 270: tmp[i][j] = vec[si + rw - j - 1][sj + i];\
    \ break;\n                default: exit(1);\n            }\n        }\n    }\n\
    \n    for(int i = 0; i < rh; i++) {\n        for(int j = 0; j < rw; j++) {\n \
    \           vec[si + i][sj + j] = tmp[i][j];\n        }\n    }\n    return;\n\
    }\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\n// (si, sj) \u3092\u5DE6\u4E0A\
    \u7AEF\u3068\u3059\u308B rh x rw \u306E\u77E9\u5F62\u3092\u53CD\u6642\u8A08\u56DE\
    \u308A\u306B deg \u5EA6\u56DE\u8EE2\u3059\u308B\n// deg \u306F 90 \u306E\u500D\
    \u6570\u306B\u9650\u308B\ntemplate <class T> void rotate_grid_partially(vector<vector<T>>\
    \ &vec, int si, int sj, int rh, int rw, int deg) {\n    const int H = vec.size();\n\
    \    const int W = vec[0].size();\n    assert(0 <= si && si < H);\n    assert(0\
    \ <= sj && sj < W);\n    assert(0 <= si + rh - 1 && si + rh - 1 < H);\n    assert(0\
    \ <= sj + rw - 1 && sj + rw - 1 < W);\n\n    if(deg < 0 || 360 <= deg) deg %=\
    \ 360;\n    if(deg < 0) deg += 360;\n    assert(deg == 0 || deg == 90 || deg ==\
    \ 180 || deg == 270);\n\n    // 90\u5EA6\u56DE\u8EE2\u3001270\u5EA6\u56DE\u8EE2\
    \u306E\u5834\u5408\u306F\u6B63\u65B9\u5F62\u3067\u306A\u3051\u308C\u3070\u306A\
    \u3089\u306A\u3044\n    if(deg == 90 || deg == 270) assert(rh == rw);\n\n    if(deg\
    \ == 0) return;\n\n    vector<vector<T>> tmp(rh, vector<T>(rw));\n    for(int\
    \ i = 0; i < rh; i++) {\n        for(int j = 0; j < rw; j++) {\n            switch(deg)\
    \ {\n                case 90: tmp[i][j] = vec[si + j][sj + rh - i - 1]; break;\n\
    \                case 180: tmp[i][j] = vec[si + rh - i - 1][sj + rw - j - 1];\
    \ break;\n                case 270: tmp[i][j] = vec[si + rw - j - 1][sj + i];\
    \ break;\n                default: exit(1);\n            }\n        }\n    }\n\
    \n    for(int i = 0; i < rh; i++) {\n        for(int j = 0; j < rw; j++) {\n \
    \           vec[si + i][sj + j] = tmp[i][j];\n        }\n    }\n    return;\n\
    }\n"
  dependsOn:
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/grid/rotate_grid_partially.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/grid/rotate_grid_partially.hpp
layout: document
redirect_from:
- /library/lib/grid/rotate_grid_partially.hpp
- /library/lib/grid/rotate_grid_partially.hpp.html
title: lib/grid/rotate_grid_partially.hpp
---
