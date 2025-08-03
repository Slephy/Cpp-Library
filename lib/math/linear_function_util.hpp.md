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
    \ 3 \"lib/math/linear_function_util.hpp\"\n\n// ax + b >= min_value \u3092\u6E80\
    \u305F\u3059\u30AE\u30EA\u30AE\u30EA\u306E x \u3092\u8FD4\u3059\n// \u26A0\uFE0F\
    \ \u5236\u7D04: a != 0\n// min_value - b \u304C\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\
    \u30FC\u3057\u306A\u3044\u306A\u3089\u3070\u3001\u30AA\u30FC\u30D0\u30FC\u30D5\
    \u30ED\u30FC\u3057\u306A\u3044\nll min_linear_x(ll a, ll b, ll min_value) {\n\
    \    assert(a != 0);\n    ll x;\n    if(a > 0) x = ceil_div(min_value - b, a);\n\
    \    else x = floor_div(min_value - b, a);\n    return x;\n}\n\n// ax + b <= max_value\
    \ \u3092\u6E80\u305F\u3059\u30AE\u30EA\u30AE\u30EA\u306E x \u3092\u8FD4\u3059\n\
    // \u26A0\uFE0F \u5236\u7D04: a != 0\n// max_value - b \u304C\u30AA\u30FC\u30D0\
    \u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\u306A\u3089\u3070\u3001\u30AA\u30FC\
    \u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\nll max_linear_x(ll a, ll b,\
    \ ll max_value) {\n    assert(a != 0);\n    ll x;\n    if(a > 0) x = floor_div(max_value\
    \ - b, a);\n    else x = ceil_div(max_value - b, a);\n    return x;\n}\n\n// ax\
    \ + b >= min_value \u3092\u6E80\u305F\u3059\u6700\u5C0F\u306E ax + b \u3092\u8FD4\
    \u3059\n// \u26A0\uFE0F \u5236\u7D04: a != 0\n// min_value - b \u304C\u30AA\u30FC\
    \u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\u306A\u3089\u3070\u3001\u30AA\
    \u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\nll min_linear_value(ll\
    \ a, ll b, ll min_value) { return a * min_linear_x(a, b, min_value) + b; }\n\n\
    // ax + b <= max_value \u3092\u6E80\u305F\u3059\u6700\u5927\u306E ax + b \u3092\
    \u8FD4\u3059\n// \u26A0\uFE0F \u5236\u7D04: a != 0\n// max_value - b \u304C\u30AA\
    \u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\u306A\u3089\u3070\u3001\
    \u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\nll max_linear_value(ll\
    \ a, ll b, ll max_value) { return a * max_linear_x(a, b, max_value) + b; }\n\n\
    // ax + b \u3068\u8868\u3055\u308C\u308B\u6574\u6570\u306E\u3046\u3061\u3001target\
    \ \u306B\u6700\u3082\u8FD1\u3044\u3082\u306E\u3092\u8FD4\u3059\n// \u26A0\uFE0F\
    \ \u5236\u7D04: a != 0\n// prioritize_big \u304C true \u306E\u3068\u304D\u3001\
    target \u306B\u6700\u3082\u8FD1\u3044\u3082\u306E\u304C\u8907\u6570\u3042\u308B\
    \u3068\u304D\u306F\u5927\u304D\u3044\u65B9\u3092\u8FD4\u3059\n// target - b \u304C\
    \u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\u306A\u3089\u3070\
    \u3001\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\nll nearest_linear_value(ll\
    \ a, ll b, ll target, bool prioritize_big = true) {\n    assert(a != 0);\n   \
    \ ll big = min_linear_value(a, b, target);    // >= target\n    ll small = max_linear_value(a,\
    \ b, target);  // <= target\n    assert(small <= big);\n    if(abs(big - target)\
    \ == abs(small - target)) {\n        if(prioritize_big) return big;\n        else\
    \ return small;\n    }\n    else {\n        if(abs(big - target) < abs(small -\
    \ target)) return big;\n        else return small;\n    }\n}\n\n// min_value <=\
    \ ax + b <= max_value \u3092\u6E80\u305F\u3059 x \u306E\u7BC4\u56F2\u3092\u8FD4\
    \u3059\n// \u305D\u306E\u3088\u3046\u306A x \u304C\u5B58\u5728\u3057\u306A\u3044\
    \u5834\u5408\u306F false \u3092\u8FD4\u3059\n// \u26A0\uFE0F \u5236\u7D04: a !=\
    \ 0\ntuple<bool, ll, ll> linear_range_x(ll a, ll b, ll min_value, ll max_value)\
    \ {\n    assert(a != 0);\n    assert(min_value <= max_value);\n    ll min_x =\
    \ min_linear_x(a, b, min_value);\n    ll max_x = max_linear_x(a, b, max_value);\n\
    \    if(a < 0) swap(min_x, max_x);\n    if(min_x > max_x) return {false, 0, 0};\n\
    \    else return {true, min_x, max_x};\n}\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\n\n// ax + b >= min_value \u3092\
    \u6E80\u305F\u3059\u30AE\u30EA\u30AE\u30EA\u306E x \u3092\u8FD4\u3059\n// \u26A0\
    \uFE0F \u5236\u7D04: a != 0\n// min_value - b \u304C\u30AA\u30FC\u30D0\u30FC\u30D5\
    \u30ED\u30FC\u3057\u306A\u3044\u306A\u3089\u3070\u3001\u30AA\u30FC\u30D0\u30FC\
    \u30D5\u30ED\u30FC\u3057\u306A\u3044\nll min_linear_x(ll a, ll b, ll min_value)\
    \ {\n    assert(a != 0);\n    ll x;\n    if(a > 0) x = ceil_div(min_value - b,\
    \ a);\n    else x = floor_div(min_value - b, a);\n    return x;\n}\n\n// ax +\
    \ b <= max_value \u3092\u6E80\u305F\u3059\u30AE\u30EA\u30AE\u30EA\u306E x \u3092\
    \u8FD4\u3059\n// \u26A0\uFE0F \u5236\u7D04: a != 0\n// max_value - b \u304C\u30AA\
    \u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\u306A\u3089\u3070\u3001\
    \u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\nll max_linear_x(ll\
    \ a, ll b, ll max_value) {\n    assert(a != 0);\n    ll x;\n    if(a > 0) x =\
    \ floor_div(max_value - b, a);\n    else x = ceil_div(max_value - b, a);\n   \
    \ return x;\n}\n\n// ax + b >= min_value \u3092\u6E80\u305F\u3059\u6700\u5C0F\u306E\
    \ ax + b \u3092\u8FD4\u3059\n// \u26A0\uFE0F \u5236\u7D04: a != 0\n// min_value\
    \ - b \u304C\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\u306A\
    \u3089\u3070\u3001\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\
    \nll min_linear_value(ll a, ll b, ll min_value) { return a * min_linear_x(a, b,\
    \ min_value) + b; }\n\n// ax + b <= max_value \u3092\u6E80\u305F\u3059\u6700\u5927\
    \u306E ax + b \u3092\u8FD4\u3059\n// \u26A0\uFE0F \u5236\u7D04: a != 0\n// max_value\
    \ - b \u304C\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\u306A\
    \u3089\u3070\u3001\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\
    \nll max_linear_value(ll a, ll b, ll max_value) { return a * max_linear_x(a, b,\
    \ max_value) + b; }\n\n// ax + b \u3068\u8868\u3055\u308C\u308B\u6574\u6570\u306E\
    \u3046\u3061\u3001target \u306B\u6700\u3082\u8FD1\u3044\u3082\u306E\u3092\u8FD4\
    \u3059\n// \u26A0\uFE0F \u5236\u7D04: a != 0\n// prioritize_big \u304C true \u306E\
    \u3068\u304D\u3001target \u306B\u6700\u3082\u8FD1\u3044\u3082\u306E\u304C\u8907\
    \u6570\u3042\u308B\u3068\u304D\u306F\u5927\u304D\u3044\u65B9\u3092\u8FD4\u3059\
    \n// target - b \u304C\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\
    \u306A\u3089\u3070\u3001\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\
    \u3044\nll nearest_linear_value(ll a, ll b, ll target, bool prioritize_big = true)\
    \ {\n    assert(a != 0);\n    ll big = min_linear_value(a, b, target);    // >=\
    \ target\n    ll small = max_linear_value(a, b, target);  // <= target\n    assert(small\
    \ <= big);\n    if(abs(big - target) == abs(small - target)) {\n        if(prioritize_big)\
    \ return big;\n        else return small;\n    }\n    else {\n        if(abs(big\
    \ - target) < abs(small - target)) return big;\n        else return small;\n \
    \   }\n}\n\n// min_value <= ax + b <= max_value \u3092\u6E80\u305F\u3059 x \u306E\
    \u7BC4\u56F2\u3092\u8FD4\u3059\n// \u305D\u306E\u3088\u3046\u306A x \u304C\u5B58\
    \u5728\u3057\u306A\u3044\u5834\u5408\u306F false \u3092\u8FD4\u3059\n// \u26A0\
    \uFE0F \u5236\u7D04: a != 0\ntuple<bool, ll, ll> linear_range_x(ll a, ll b, ll\
    \ min_value, ll max_value) {\n    assert(a != 0);\n    assert(min_value <= max_value);\n\
    \    ll min_x = min_linear_x(a, b, min_value);\n    ll max_x = max_linear_x(a,\
    \ b, max_value);\n    if(a < 0) swap(min_x, max_x);\n    if(min_x > max_x) return\
    \ {false, 0, 0};\n    else return {true, min_x, max_x};\n}\n"
  dependsOn:
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/math/linear_function_util.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/linear_function_util.hpp
layout: document
redirect_from:
- /library/lib/math/linear_function_util.hpp
- /library/lib/math/linear_function_util.hpp.html
title: lib/math/linear_function_util.hpp
---
