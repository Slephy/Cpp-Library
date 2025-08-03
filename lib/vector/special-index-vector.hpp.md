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
    \ 3 \"lib/vector/special-index-vector.hpp\"\n// \u6DFB\u3048\u5B57\u306B\u95A2\
    \u3057\u3066\u591A\u6A5F\u80FD\u306Avector\n// \u6DFB\u3048\u5B57\u304C\u30EB\u30FC\
    \u30D7\u53EF\u80FD\u3067\u3001mod this->size() \u3067\u7B49\u3057\u3044\u8981\u7D20\
    \u306B\u30A2\u30AF\u30BB\u30B9\u3055\u308C\u308B\n// bias\u3092\u5909\u66F4\u3059\
    \u308B\u3053\u3068\u3067\u6DFB\u3048\u5B57\u306B\u4E0B\u99C4\u3092\u306F\u304B\
    \u305B\u308B\u3053\u3068\u304C\u53EF\u80FD\ntemplate <class T> class Svector :\
    \ public vector<T> {\npublic:\n    using vector<T>::vector;\n    vector<T>::reference\
    \ operator[](int i) { return vector<T>::operator[](calc_index(i)); }\n    vector<T>::const_reference\
    \ operator[](int i) const { return vector<T>::operator[](calc_index(i)); }\n\n\
    \    ll bias = 0;\n\nprivate:\n    size_t calc_index(int i) {\n        ll ret\
    \ = (i - bias) % this->size();\n        if(ret < 0) ret += this->size();\n   \
    \     return (size_t)ret;\n    }\n};\n\ntemplate <class T> inline Svector<Svector<T>>\
    \ SVector2(size_t i, size_t j, const T &init = T()) {\n    return Svector<Svector<T>>(i,\
    \ Svector<T>(j, init));\n}\ntemplate <class T> inline Svector<Svector<Svector<T>>>\
    \ SVector3(size_t i, size_t j, size_t k, const T &init = T()) {\n    return Svector<Svector<Svector<T>>>(i,\
    \ Svector<Svector<T>>(j, Svector<T>(k, init)));\n}\ntemplate <class T>\ninline\
    \ Svector<Svector<Svector<Svector<T>>>> SVector4(size_t i, size_t j, size_t k,\
    \ size_t l, const T &init = T()) {\n    return Svector<Svector<Svector<Svector<T>>>>(\n\
    \        i, Svector<Svector<Svector<T>>>(j, Svector<Svector<T>>(k, Svector<T>(l,\
    \ init))));\n}\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\n// \u6DFB\u3048\u5B57\u306B\u95A2\
    \u3057\u3066\u591A\u6A5F\u80FD\u306Avector\n// \u6DFB\u3048\u5B57\u304C\u30EB\u30FC\
    \u30D7\u53EF\u80FD\u3067\u3001mod this->size() \u3067\u7B49\u3057\u3044\u8981\u7D20\
    \u306B\u30A2\u30AF\u30BB\u30B9\u3055\u308C\u308B\n// bias\u3092\u5909\u66F4\u3059\
    \u308B\u3053\u3068\u3067\u6DFB\u3048\u5B57\u306B\u4E0B\u99C4\u3092\u306F\u304B\
    \u305B\u308B\u3053\u3068\u304C\u53EF\u80FD\ntemplate <class T> class Svector :\
    \ public vector<T> {\npublic:\n    using vector<T>::vector;\n    vector<T>::reference\
    \ operator[](int i) { return vector<T>::operator[](calc_index(i)); }\n    vector<T>::const_reference\
    \ operator[](int i) const { return vector<T>::operator[](calc_index(i)); }\n\n\
    \    ll bias = 0;\n\nprivate:\n    size_t calc_index(int i) {\n        ll ret\
    \ = (i - bias) % this->size();\n        if(ret < 0) ret += this->size();\n   \
    \     return (size_t)ret;\n    }\n};\n\ntemplate <class T> inline Svector<Svector<T>>\
    \ SVector2(size_t i, size_t j, const T &init = T()) {\n    return Svector<Svector<T>>(i,\
    \ Svector<T>(j, init));\n}\ntemplate <class T> inline Svector<Svector<Svector<T>>>\
    \ SVector3(size_t i, size_t j, size_t k, const T &init = T()) {\n    return Svector<Svector<Svector<T>>>(i,\
    \ Svector<Svector<T>>(j, Svector<T>(k, init)));\n}\ntemplate <class T>\ninline\
    \ Svector<Svector<Svector<Svector<T>>>> SVector4(size_t i, size_t j, size_t k,\
    \ size_t l, const T &init = T()) {\n    return Svector<Svector<Svector<Svector<T>>>>(\n\
    \        i, Svector<Svector<Svector<T>>>(j, Svector<Svector<T>>(k, Svector<T>(l,\
    \ init))));\n}\n"
  dependsOn:
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/vector/special-index-vector.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/vector/special-index-vector.hpp
layout: document
redirect_from:
- /library/lib/vector/special-index-vector.hpp
- /library/lib/vector/special-index-vector.hpp.html
title: lib/vector/special-index-vector.hpp
---
