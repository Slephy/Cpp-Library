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
    \ 3 \"lib/grid/rotate_grid.hpp\"\n// \u53CD\u6642\u8A08\u56DE\u308A\u306B\u30B0\
    \u30EA\u30C3\u30C9\u3092\u56DE\u8EE2\u3055\u305B\u308B\ntemplate <class T> [[nodiscard]]\
    \ vector<vector<T>> rotate_grid(const vector<vector<T>> &grid, int rotate_degree\
    \ = 0) {\n    rotate_degree = ((rotate_degree % 360) + 360) % 360;\n    assert(rotate_degree\
    \ % 90 == 0);\n\n    assert(grid.size() > 0);\n    int h = grid.size();\n    assert(grid[0].size()\
    \ > 0);\n    int w = grid[0].size();\n\n    vector<vector<T>> ret;\n    if(rotate_degree\
    \ % 180 == 0) ret = vector<vector<T>>(h, vector<T>(w));\n    else ret = vector<vector<T>>(w,\
    \ vector<T>(h));\n\n    for(int i = 0; i < h; i++) {\n        for(int j = 0; j\
    \ < w; j++) {\n            switch(rotate_degree) {\n                case 0: ret[i][j]\
    \ = grid[i][j]; break;\n                case 90: ret[w - j - 1][i] = grid[i][j];\
    \ break;\n                case 180: ret[h - i - 1][w - j - 1] = grid[i][j]; break;\n\
    \                case 270: ret[j][h - i - 1] = grid[i][j]; break;\n          \
    \  }\n        }\n    }\n    return ret;\n}\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\n// \u53CD\u6642\u8A08\u56DE\u308A\
    \u306B\u30B0\u30EA\u30C3\u30C9\u3092\u56DE\u8EE2\u3055\u305B\u308B\ntemplate <class\
    \ T> [[nodiscard]] vector<vector<T>> rotate_grid(const vector<vector<T>> &grid,\
    \ int rotate_degree = 0) {\n    rotate_degree = ((rotate_degree % 360) + 360)\
    \ % 360;\n    assert(rotate_degree % 90 == 0);\n\n    assert(grid.size() > 0);\n\
    \    int h = grid.size();\n    assert(grid[0].size() > 0);\n    int w = grid[0].size();\n\
    \n    vector<vector<T>> ret;\n    if(rotate_degree % 180 == 0) ret = vector<vector<T>>(h,\
    \ vector<T>(w));\n    else ret = vector<vector<T>>(w, vector<T>(h));\n\n    for(int\
    \ i = 0; i < h; i++) {\n        for(int j = 0; j < w; j++) {\n            switch(rotate_degree)\
    \ {\n                case 0: ret[i][j] = grid[i][j]; break;\n                case\
    \ 90: ret[w - j - 1][i] = grid[i][j]; break;\n                case 180: ret[h\
    \ - i - 1][w - j - 1] = grid[i][j]; break;\n                case 270: ret[j][h\
    \ - i - 1] = grid[i][j]; break;\n            }\n        }\n    }\n    return ret;\n\
    }\n"
  dependsOn:
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/grid/rotate_grid.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/grid/rotate_grid.hpp
layout: document
redirect_from:
- /library/lib/grid/rotate_grid.hpp
- /library/lib/grid/rotate_grid.hpp.html
title: lib/grid/rotate_grid.hpp
---
