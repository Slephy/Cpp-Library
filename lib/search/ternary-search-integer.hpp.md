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
    \ 3 \"lib/search/ternary-search-integer.hpp\"\n\nenum class TernalySearchDirection\
    \ {\n    Downward,\n    Upward,\n};\n\n// \u4E09\u5206\u63A2\u7D22\n// \u72ED\u7FA9\
    \u5358\u8ABF\u6027\u3092\u6301\u3064\u5358\u5CF0\u95A2\u6570\u306B\u3064\u3044\
    \u3066\u6700\u5C0F\u5024\u3092\u53D6\u308B\u3068\u304D\u306E\u5F15\u6570\u3092\
    \u6C42\u3081\u308B\n// @need left <= right\ntemplate <class Evaluate>\nll ternary_search_integer(ll\
    \ left, ll right,\n                          Evaluate eval,  // param: ll, return:\
    \ any\n                          TernalySearchDirection direction = TernalySearchDirection::Downward)\
    \ {\n    assert(left <= right);\n\n    // corner case\n    if((__int128_t)right\
    \ - left <= 1) {\n        if(direction == TernalySearchDirection::Downward) {\n\
    \            return ((eval(left) < eval(right)) ? left : right);\n        }\n\
    \        if(direction == TernalySearchDirection::Upward) {\n            return\
    \ ((eval(left) > eval(right)) ? left : right);\n        }\n    }\n\n    // \u2705\
    \ left < right && right - left >= 2\n    auto need_continue = [&]() -> bool {\
    \ return ((__int128_t)right - left > 2); };\n\n    while(need_continue()) {\n\
    \        ll mid1 = left + ((__int128_t)right - (__int128_t)left) / 3;\n      \
    \  ll mid2 = right - ((__int128_t)right - (__int128_t)left) / 3;\n\n        if(direction\
    \ == TernalySearchDirection::Downward) {\n            if(eval(mid1) < eval(mid2))\
    \ right = mid2;\n            else left = mid1;\n        }\n        if(direction\
    \ == TernalySearchDirection::Upward) {\n            if(eval(mid1) > eval(mid2))\
    \ right = mid2;\n            else left = mid1;\n        }\n    }\n\n    assert(right\
    \ - left == 2);  // \u3053\u308C\u304C\u4E09\u5206\u63A2\u7D22\u306E\u7D42\u4E86\
    \u6761\u4EF6\n    ll mid = left + 1;\n    if(direction == TernalySearchDirection::Downward)\
    \ {\n        if(eval(left) < eval(mid)) return left;\n        if(eval(right) <\
    \ eval(mid)) return right;\n        else return mid;\n    }\n    if(direction\
    \ == TernalySearchDirection::Upward) {\n        if(eval(left) > eval(mid)) return\
    \ left;\n        if(eval(right) > eval(mid)) return right;\n        else return\
    \ mid;\n    }\n    else exit(1);\n}\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\n\nenum class TernalySearchDirection\
    \ {\n    Downward,\n    Upward,\n};\n\n// \u4E09\u5206\u63A2\u7D22\n// \u72ED\u7FA9\
    \u5358\u8ABF\u6027\u3092\u6301\u3064\u5358\u5CF0\u95A2\u6570\u306B\u3064\u3044\
    \u3066\u6700\u5C0F\u5024\u3092\u53D6\u308B\u3068\u304D\u306E\u5F15\u6570\u3092\
    \u6C42\u3081\u308B\n// @need left <= right\ntemplate <class Evaluate>\nll ternary_search_integer(ll\
    \ left, ll right,\n                          Evaluate eval,  // param: ll, return:\
    \ any\n                          TernalySearchDirection direction = TernalySearchDirection::Downward)\
    \ {\n    assert(left <= right);\n\n    // corner case\n    if((__int128_t)right\
    \ - left <= 1) {\n        if(direction == TernalySearchDirection::Downward) {\n\
    \            return ((eval(left) < eval(right)) ? left : right);\n        }\n\
    \        if(direction == TernalySearchDirection::Upward) {\n            return\
    \ ((eval(left) > eval(right)) ? left : right);\n        }\n    }\n\n    // \u2705\
    \ left < right && right - left >= 2\n    auto need_continue = [&]() -> bool {\
    \ return ((__int128_t)right - left > 2); };\n\n    while(need_continue()) {\n\
    \        ll mid1 = left + ((__int128_t)right - (__int128_t)left) / 3;\n      \
    \  ll mid2 = right - ((__int128_t)right - (__int128_t)left) / 3;\n\n        if(direction\
    \ == TernalySearchDirection::Downward) {\n            if(eval(mid1) < eval(mid2))\
    \ right = mid2;\n            else left = mid1;\n        }\n        if(direction\
    \ == TernalySearchDirection::Upward) {\n            if(eval(mid1) > eval(mid2))\
    \ right = mid2;\n            else left = mid1;\n        }\n    }\n\n    assert(right\
    \ - left == 2);  // \u3053\u308C\u304C\u4E09\u5206\u63A2\u7D22\u306E\u7D42\u4E86\
    \u6761\u4EF6\n    ll mid = left + 1;\n    if(direction == TernalySearchDirection::Downward)\
    \ {\n        if(eval(left) < eval(mid)) return left;\n        if(eval(right) <\
    \ eval(mid)) return right;\n        else return mid;\n    }\n    if(direction\
    \ == TernalySearchDirection::Upward) {\n        if(eval(left) > eval(mid)) return\
    \ left;\n        if(eval(right) > eval(mid)) return right;\n        else return\
    \ mid;\n    }\n    else exit(1);\n}\n"
  dependsOn:
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/search/ternary-search-integer.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/search/ternary-search-integer.hpp
layout: document
redirect_from:
- /library/lib/search/ternary-search-integer.hpp
- /library/lib/search/ternary-search-integer.hpp.html
title: lib/search/ternary-search-integer.hpp
---
