---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: lib/core/core.hpp
    title: lib/core/core.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: lib/misc/choosable_set.hpp
    title: lib/misc/choosable_set.hpp
  - icon: ':warning:'
    path: lib/misc/limited_choosable_set.hpp
    title: lib/misc/limited_choosable_set.hpp
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
    \ 3 \"lib/random/random.hpp\"\nnamespace my_random {\nrandom_device random_dvc;\n\
    mt19937 mt(random_dvc());\n\n// l\u4EE5\u4E0Ar\u4EE5\u4E0B\u306E\u6574\u6570\u4E71\
    \u6570\u3092\u8FD4\u3059\nint rand_int(int l, int r) {\n    uniform_int_distribution<int>\
    \ dist(l, r);\n    return dist(mt);\n}\n// l\u4EE5\u4E0Ar\u4EE5\u4E0B\u306E\u6574\
    \u6570\u4E71\u6570\u3092\u8FD4\u3059\nll rand_ll(ll l, ll r) {\n    uniform_int_distribution<ll>\
    \ dist(l, r);\n    return dist(mt);\n}\n__int128_t rand_i128(__int128_t l, __int128_t\
    \ r) {\n    uniform_int_distribution<long long> dist(0, numeric_limits<long long>::max());\n\
    \    __int128_t res = dist(mt);\n    res <<= 64;\n    res += dist(mt);\n    return\
    \ res % (r - l + 1) + l;\n}\n__uint128_t rand_u128(__uint128_t l, __uint128_t\
    \ r) {\n    uniform_int_distribution<unsigned long long> dist(0, numeric_limits<unsigned\
    \ long long>::max());\n    __uint128_t res = dist(mt);\n    res <<= 64;\n    res\
    \ += dist(mt);\n    return res % (r - l + 1) + l;\n}\ndouble rand_double(double\
    \ l, double r) {\n    uniform_real_distribution<double> dist(l, r);\n    return\
    \ dist(mt);\n}\ndouble rand_double01() { return rand_double(0, 1); }\nbool rand_bool(double\
    \ probability) { return rand_double01() < probability; }\n}  // namespace my_random\n\
    using namespace my_random;\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\nnamespace my_random {\nrandom_device\
    \ random_dvc;\nmt19937 mt(random_dvc());\n\n// l\u4EE5\u4E0Ar\u4EE5\u4E0B\u306E\
    \u6574\u6570\u4E71\u6570\u3092\u8FD4\u3059\nint rand_int(int l, int r) {\n   \
    \ uniform_int_distribution<int> dist(l, r);\n    return dist(mt);\n}\n// l\u4EE5\
    \u4E0Ar\u4EE5\u4E0B\u306E\u6574\u6570\u4E71\u6570\u3092\u8FD4\u3059\nll rand_ll(ll\
    \ l, ll r) {\n    uniform_int_distribution<ll> dist(l, r);\n    return dist(mt);\n\
    }\n__int128_t rand_i128(__int128_t l, __int128_t r) {\n    uniform_int_distribution<long\
    \ long> dist(0, numeric_limits<long long>::max());\n    __int128_t res = dist(mt);\n\
    \    res <<= 64;\n    res += dist(mt);\n    return res % (r - l + 1) + l;\n}\n\
    __uint128_t rand_u128(__uint128_t l, __uint128_t r) {\n    uniform_int_distribution<unsigned\
    \ long long> dist(0, numeric_limits<unsigned long long>::max());\n    __uint128_t\
    \ res = dist(mt);\n    res <<= 64;\n    res += dist(mt);\n    return res % (r\
    \ - l + 1) + l;\n}\ndouble rand_double(double l, double r) {\n    uniform_real_distribution<double>\
    \ dist(l, r);\n    return dist(mt);\n}\ndouble rand_double01() { return rand_double(0,\
    \ 1); }\nbool rand_bool(double probability) { return rand_double01() < probability;\
    \ }\n}  // namespace my_random\nusing namespace my_random;\n"
  dependsOn:
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/random/random.hpp
  requiredBy:
  - lib/misc/limited_choosable_set.hpp
  - lib/misc/choosable_set.hpp
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/random/random.hpp
layout: document
redirect_from:
- /library/lib/random/random.hpp
- /library/lib/random/random.hpp.html
title: lib/random/random.hpp
---
