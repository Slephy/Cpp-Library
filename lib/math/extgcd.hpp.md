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
    \ 3 \"lib/math/extgcd.hpp\"\n\nnamespace slephy_extgcd {\n\n// ax + by = gcd(a,\
    \ b) \u306E\u6574\u6570\u7279\u6B8A\u89E3 x, y \u3092\u5F97\u308B\n// \u5236\u7D04\
    : a >= 0, b >= 0\npair<ll, ll> extgcd_impl(ll a, ll b) {\n    if(b == 0) return\
    \ {1, 0};\n    auto [x, y] = extgcd_impl(b, a % b);\n    ll nx = y, ny = x - a\
    \ / b * y;\n    return {nx, ny};\n}\n\n// ax + by = gcd(a, b) \u306E\u6574\u6570\
    \u7279\u6B8A\u89E3 x, y \u3092\u5F97\u308B\n// \u5236\u7D04: \u306A\u3057\npair<ll,\
    \ ll> extgcd(ll a, ll b) {\n    auto [x, y] = extgcd_impl(abs(a), abs(b));\n \
    \   if(a < 0) x = -x;\n    if(b < 0) y = -y;\n    return {x, y};\n}\n\n// ax +\
    \ by = ans \u306E\u6574\u6570\u7279\u6B8A\u89E3 x, y \u3092\u5F97\u308B\n// \u8FD4\
    \u308A\u5024\u306Efirst\u306F\u89E3\u304C\u5B58\u5728\u3059\u308B\u304B\u3069\u3046\
    \u304B\ntuple<bool, ll, ll> extgcd(ll a, ll b, ll ans) {\n    if(a == 0 && b ==\
    \ 0) return {ans == 0, 0, 0};\n    if(ans % gcd(a, b) != 0) return {false, 0,\
    \ 0};\n\n    bool swapped = false;\n    if(abs(a) < abs(b)) swap(a, b), swapped\
    \ = true;  // |a| >= |b|\n    auto [x, y] = extgcd(a, b);\n\n    // ans <- ans\
    \ % a\n    const ll ANS = ans;\n    ll addx = 0;\n    if(abs(ans) > abs(a)) {\n\
    \        addx = ans / a;\n        ans -= a * addx;\n    }\n\n    // ax + by =\
    \ gcd(a, b) \u306E\u7279\u6B8A\u89E3\u304B\u3089 ax + by = ans \u306E\u7279\u6B8A\
    \u89E3\u3092\u5F97\u308B\n    ll p = ans / gcd(a, b);\n    x *= p, y *= p;\n \
    \   x += addx;\n\n    // swap \u3092\u3082\u3068\u306B\u623B\u3059\n    if(swapped)\
    \ swap(a, b), swap(x, y);\n    return {true, x, y};\n}\n}  // namespace slephy_extgcd\n\
    using::slephy_extgcd::extgcd;\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\n\nnamespace slephy_extgcd {\n\
    \n// ax + by = gcd(a, b) \u306E\u6574\u6570\u7279\u6B8A\u89E3 x, y \u3092\u5F97\
    \u308B\n// \u5236\u7D04: a >= 0, b >= 0\npair<ll, ll> extgcd_impl(ll a, ll b)\
    \ {\n    if(b == 0) return {1, 0};\n    auto [x, y] = extgcd_impl(b, a % b);\n\
    \    ll nx = y, ny = x - a / b * y;\n    return {nx, ny};\n}\n\n// ax + by = gcd(a,\
    \ b) \u306E\u6574\u6570\u7279\u6B8A\u89E3 x, y \u3092\u5F97\u308B\n// \u5236\u7D04\
    : \u306A\u3057\npair<ll, ll> extgcd(ll a, ll b) {\n    auto [x, y] = extgcd_impl(abs(a),\
    \ abs(b));\n    if(a < 0) x = -x;\n    if(b < 0) y = -y;\n    return {x, y};\n\
    }\n\n// ax + by = ans \u306E\u6574\u6570\u7279\u6B8A\u89E3 x, y \u3092\u5F97\u308B\
    \n// \u8FD4\u308A\u5024\u306Efirst\u306F\u89E3\u304C\u5B58\u5728\u3059\u308B\u304B\
    \u3069\u3046\u304B\ntuple<bool, ll, ll> extgcd(ll a, ll b, ll ans) {\n    if(a\
    \ == 0 && b == 0) return {ans == 0, 0, 0};\n    if(ans % gcd(a, b) != 0) return\
    \ {false, 0, 0};\n\n    bool swapped = false;\n    if(abs(a) < abs(b)) swap(a,\
    \ b), swapped = true;  // |a| >= |b|\n    auto [x, y] = extgcd(a, b);\n\n    //\
    \ ans <- ans % a\n    const ll ANS = ans;\n    ll addx = 0;\n    if(abs(ans) >\
    \ abs(a)) {\n        addx = ans / a;\n        ans -= a * addx;\n    }\n\n    //\
    \ ax + by = gcd(a, b) \u306E\u7279\u6B8A\u89E3\u304B\u3089 ax + by = ans \u306E\
    \u7279\u6B8A\u89E3\u3092\u5F97\u308B\n    ll p = ans / gcd(a, b);\n    x *= p,\
    \ y *= p;\n    x += addx;\n\n    // swap \u3092\u3082\u3068\u306B\u623B\u3059\n\
    \    if(swapped) swap(a, b), swap(x, y);\n    return {true, x, y};\n}\n}  // namespace\
    \ slephy_extgcd\nusing::slephy_extgcd::extgcd;\n"
  dependsOn:
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/math/extgcd.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/extgcd.hpp
layout: document
redirect_from:
- /library/lib/math/extgcd.hpp
- /library/lib/math/extgcd.hpp.html
title: lib/math/extgcd.hpp
---
