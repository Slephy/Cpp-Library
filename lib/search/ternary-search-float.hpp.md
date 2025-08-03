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
    \ 3 \"lib/search/ternary-search-float.hpp\"\n\n// \u4E09\u5206\u63A2\u7D22\n//\
    \ \u72ED\u7FA9\u5358\u8ABF\u6027\u3092\u6301\u3064\u5358\u5CF0\u95A2\u6570\u306B\
    \u3064\u3044\u3066\u6700\u5C0F\u5024\u3092\u53D6\u308B\u3068\u304D\u306E\u5F15\
    \u6570\u3092\u6C42\u3081\u308B\n// @need left <= right\ntemplate <class Evaluate>\n\
    double ternary_search_float(double left, double right,\n                     \
    \       Evaluate eval,  // param: double, return: any\n                      \
    \      double tolerance,\n                            bool is_downward = true,\
    \  // \u4E0B\u306B\u51F8\u304B\u3069\u3046\u304B\n                           \
    \ bool considerRelativeError = true) {\n    assert(left <= right);\n    auto need_continue\
    \ = [&]() -> bool {\n        if((fabs(left - right) < tolerance)) return false;\
    \  // \u7D76\u5BFE\u8AA4\u5DEE\n        if(considerRelativeError && (fabs(left\
    \ - right) < tolerance * fabs((left + right) * 0.5)))\n            return false;\
    \  // \u76F8\u5BFE\u8AA4\u5DEE\n        return true;\n    };\n\n    while(need_continue())\
    \ {\n        double mid1 = left + (right - left) / 3.0;\n        double mid2 =\
    \ right - (right - left) / 3.0;\n\n        if(is_downward) {\n            if(eval(mid1)\
    \ < eval(mid2)) right = mid2;\n            else left = mid1;\n        }\n    \
    \    else {\n            if(eval(mid1) > eval(mid2)) right = mid2;\n         \
    \   else left = mid1;\n        }\n    }\n\n    if(is_downward) {\n        return\
    \ (eval(left) < eval(right)) ? left : right;\n    }\n    else {\n        return\
    \ (eval(left) > eval(right)) ? left : right;\n    }\n}\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\n\n// \u4E09\u5206\u63A2\u7D22\
    \n// \u72ED\u7FA9\u5358\u8ABF\u6027\u3092\u6301\u3064\u5358\u5CF0\u95A2\u6570\u306B\
    \u3064\u3044\u3066\u6700\u5C0F\u5024\u3092\u53D6\u308B\u3068\u304D\u306E\u5F15\
    \u6570\u3092\u6C42\u3081\u308B\n// @need left <= right\ntemplate <class Evaluate>\n\
    double ternary_search_float(double left, double right,\n                     \
    \       Evaluate eval,  // param: double, return: any\n                      \
    \      double tolerance,\n                            bool is_downward = true,\
    \  // \u4E0B\u306B\u51F8\u304B\u3069\u3046\u304B\n                           \
    \ bool considerRelativeError = true) {\n    assert(left <= right);\n    auto need_continue\
    \ = [&]() -> bool {\n        if((fabs(left - right) < tolerance)) return false;\
    \  // \u7D76\u5BFE\u8AA4\u5DEE\n        if(considerRelativeError && (fabs(left\
    \ - right) < tolerance * fabs((left + right) * 0.5)))\n            return false;\
    \  // \u76F8\u5BFE\u8AA4\u5DEE\n        return true;\n    };\n\n    while(need_continue())\
    \ {\n        double mid1 = left + (right - left) / 3.0;\n        double mid2 =\
    \ right - (right - left) / 3.0;\n\n        if(is_downward) {\n            if(eval(mid1)\
    \ < eval(mid2)) right = mid2;\n            else left = mid1;\n        }\n    \
    \    else {\n            if(eval(mid1) > eval(mid2)) right = mid2;\n         \
    \   else left = mid1;\n        }\n    }\n\n    if(is_downward) {\n        return\
    \ (eval(left) < eval(right)) ? left : right;\n    }\n    else {\n        return\
    \ (eval(left) > eval(right)) ? left : right;\n    }\n}\n"
  dependsOn:
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/search/ternary-search-float.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/search/ternary-search-float.hpp
layout: document
redirect_from:
- /library/lib/search/ternary-search-float.hpp
- /library/lib/search/ternary-search-float.hpp.html
title: lib/search/ternary-search-float.hpp
---
