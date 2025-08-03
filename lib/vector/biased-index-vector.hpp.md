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
    \ 3 \"lib/vector/biased-index-vector.hpp\"\n// \u6DFB\u3048\u5B57\u306B\u4E0B\u99C4\
    \u3092\u306F\u304B\u305B\u305Fvector\n// 'a'\u3084'A'\u306A\u3069\u3092\u30BC\u30ED\
    \u3068\u3057\u3066\u6271\u3046\u3053\u3068\u3092\u60F3\u5B9A\u3057\u3066\u3044\
    \u308B\ntemplate <class T, long long BIAS = 0> class Bvector : public vector<T>\
    \ {\npublic:\n    using vector<T>::vector;\n    vector<T>::reference operator[](int\
    \ i) { return vector<T>::operator[](i - BIAS); }\n    vector<T>::const_reference\
    \ operator[](int i) const { return vector<T>::operator[](i - BIAS); }\n};\n\n\
    template <class T, long long BIAS = 0> using Bvector2_t = Bvector<Bvector<T, BIAS>,\
    \ BIAS>;\ntemplate <class T, long long BIAS = 0> using Bvector3_t = Bvector<Bvector<Bvector<T,\
    \ BIAS>, BIAS>, BIAS>;\ntemplate <class T, long long BIAS = 0> using Bvector4_t\
    \ = Bvector<Bvector<Bvector<Bvector<T, BIAS>, BIAS>, BIAS>, BIAS>;\n\ntemplate\
    \ <class T, long long BIAS = 0> inline Bvector2_t<T, BIAS> Bvector2(size_t i,\
    \ size_t j, const T &init = T()) {\n    return Bvector2_t<T, BIAS>(i, Bvector<T,\
    \ BIAS>(j, init));\n}\ntemplate <class T, long long BIAS = 0>\ninline Bvector3_t<T,\
    \ BIAS> Bvector3(size_t i, size_t j, size_t k, const T &init = T()) {\n    return\
    \ Bvector3_t<T, BIAS>(i, Bvector<Bvector<T, BIAS>, BIAS>(j, Bvector<T, BIAS>(k,\
    \ init)));\n}\ntemplate <class T, long long BIAS = 0>\ninline Bvector4_t<T, BIAS>\
    \ Bvector4(size_t i, size_t j, size_t k, size_t l, const T &init = T()) {\n  \
    \  return Bvector4_t<T, BIAS>(i, Bvector3_t<T, BIAS>(j, Bvector2_t<T, BIAS>(k,\
    \ Bvector<T, BIAS>(l, init))));\n}\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\n// \u6DFB\u3048\u5B57\u306B\u4E0B\
    \u99C4\u3092\u306F\u304B\u305B\u305Fvector\n// 'a'\u3084'A'\u306A\u3069\u3092\u30BC\
    \u30ED\u3068\u3057\u3066\u6271\u3046\u3053\u3068\u3092\u60F3\u5B9A\u3057\u3066\
    \u3044\u308B\ntemplate <class T, long long BIAS = 0> class Bvector : public vector<T>\
    \ {\npublic:\n    using vector<T>::vector;\n    vector<T>::reference operator[](int\
    \ i) { return vector<T>::operator[](i - BIAS); }\n    vector<T>::const_reference\
    \ operator[](int i) const { return vector<T>::operator[](i - BIAS); }\n};\n\n\
    template <class T, long long BIAS = 0> using Bvector2_t = Bvector<Bvector<T, BIAS>,\
    \ BIAS>;\ntemplate <class T, long long BIAS = 0> using Bvector3_t = Bvector<Bvector<Bvector<T,\
    \ BIAS>, BIAS>, BIAS>;\ntemplate <class T, long long BIAS = 0> using Bvector4_t\
    \ = Bvector<Bvector<Bvector<Bvector<T, BIAS>, BIAS>, BIAS>, BIAS>;\n\ntemplate\
    \ <class T, long long BIAS = 0> inline Bvector2_t<T, BIAS> Bvector2(size_t i,\
    \ size_t j, const T &init = T()) {\n    return Bvector2_t<T, BIAS>(i, Bvector<T,\
    \ BIAS>(j, init));\n}\ntemplate <class T, long long BIAS = 0>\ninline Bvector3_t<T,\
    \ BIAS> Bvector3(size_t i, size_t j, size_t k, const T &init = T()) {\n    return\
    \ Bvector3_t<T, BIAS>(i, Bvector<Bvector<T, BIAS>, BIAS>(j, Bvector<T, BIAS>(k,\
    \ init)));\n}\ntemplate <class T, long long BIAS = 0>\ninline Bvector4_t<T, BIAS>\
    \ Bvector4(size_t i, size_t j, size_t k, size_t l, const T &init = T()) {\n  \
    \  return Bvector4_t<T, BIAS>(i, Bvector3_t<T, BIAS>(j, Bvector2_t<T, BIAS>(k,\
    \ Bvector<T, BIAS>(l, init))));\n}\n"
  dependsOn:
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/vector/biased-index-vector.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/vector/biased-index-vector.hpp
layout: document
redirect_from:
- /library/lib/vector/biased-index-vector.hpp
- /library/lib/vector/biased-index-vector.hpp.html
title: lib/vector/biased-index-vector.hpp
---
