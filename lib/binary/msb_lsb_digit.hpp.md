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
    \ 3 \"lib/binary/msb_lsb_digit.hpp\"\n// 1\u306E\u6700\u4E0A\u4F4D\u30D3\u30C3\
    \u30C8\u304C\u4F55\u6841\u76EE\u304B\u3092\u8FD4\u3059\n// \u26A0\uFE0F n = 0\
    \ \u306E\u3068\u304D\u306F -1 \u3092\u8FD4\u3059\n// get_msb(0) == -1\n// get_msb(0b1010)\
    \ == 3\nll get_msb(ull n) {\n    if(n == 0) return -1;\n    else return (63 -\
    \ __builtin_clzll(n));\n}\n\n// 1\u306E\u6700\u4E0B\u4F4D\u30D3\u30C3\u30C8\u304C\
    \u4F55\u6841\u76EE\u304B\u3092\u8FD4\u3059\n// \u26A0\uFE0F n = 0 \u306E\u3068\
    \u304D\u306F -1 \u3092\u8FD4\u3059\n// get_lsb(0) == -1\n// get_lsb(0b1010) ==\
    \ 1\nll get_lsb(ull n) {\n    if(n == 0) return -1;\n    else return __builtin_ctzll(n\
    \ & ~(n - 1));\n}\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\n// 1\u306E\u6700\u4E0A\u4F4D\
    \u30D3\u30C3\u30C8\u304C\u4F55\u6841\u76EE\u304B\u3092\u8FD4\u3059\n// \u26A0\uFE0F\
    \ n = 0 \u306E\u3068\u304D\u306F -1 \u3092\u8FD4\u3059\n// get_msb(0) == -1\n\
    // get_msb(0b1010) == 3\nll get_msb(ull n) {\n    if(n == 0) return -1;\n    else\
    \ return (63 - __builtin_clzll(n));\n}\n\n// 1\u306E\u6700\u4E0B\u4F4D\u30D3\u30C3\
    \u30C8\u304C\u4F55\u6841\u76EE\u304B\u3092\u8FD4\u3059\n// \u26A0\uFE0F n = 0\
    \ \u306E\u3068\u304D\u306F -1 \u3092\u8FD4\u3059\n// get_lsb(0) == -1\n// get_lsb(0b1010)\
    \ == 1\nll get_lsb(ull n) {\n    if(n == 0) return -1;\n    else return __builtin_ctzll(n\
    \ & ~(n - 1));\n}\n"
  dependsOn:
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/binary/msb_lsb_digit.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/binary/msb_lsb_digit.hpp
layout: document
redirect_from:
- /library/lib/binary/msb_lsb_digit.hpp
- /library/lib/binary/msb_lsb_digit.hpp.html
title: lib/binary/msb_lsb_digit.hpp
---
