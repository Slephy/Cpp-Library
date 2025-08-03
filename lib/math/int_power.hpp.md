---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: lib/concepts/modint_concept.hpp
    title: lib/concepts/modint_concept.hpp
  - icon: ':warning:'
    path: lib/core/core.hpp
    title: lib/core/core.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: lib/math/power.hpp
    title: lib/math/power.hpp
  - icon: ':warning:'
    path: lib/radix/get_digit.hpp
    title: lib/radix/get_digit.hpp
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
    \ 3 \"lib/concepts/modint_concept.hpp\"\n\ntemplate <typename T>\nconcept IsModint\
    \ = requires(T a, ll b) {\n    { a.pow(b) } -> same_as<T>;\n    { a.val() } ->\
    \ std::convertible_to<ll>;\n    { T::mod() } -> std::convertible_to<ll>;\n};\n\
    #line 4 \"lib/math/int_power.hpp\"\n\n// integral\ntemplate <class T, integral\
    \ U>\n    requires(!IsModint<T> && integral<T>)\nT power(T val, U exp) {\n   \
    \ if(exp < 0) throw invalid_argument(\"Negative exponent not supported for integral\
    \ types.\");\n\n    T result = 1;\n    while(true) {\n        if(exp % 2 == 1)\
    \ result *= val;\n        exp /= 2;\n        if(exp > 0) val *= val;\n       \
    \ else break;\n    }\n    return result;\n}\n"
  code: "#pragma once\n#include \"../concepts/modint_concept.hpp\"\n#include \"../core/core.hpp\"\
    \n\n// integral\ntemplate <class T, integral U>\n    requires(!IsModint<T> &&\
    \ integral<T>)\nT power(T val, U exp) {\n    if(exp < 0) throw invalid_argument(\"\
    Negative exponent not supported for integral types.\");\n\n    T result = 1;\n\
    \    while(true) {\n        if(exp % 2 == 1) result *= val;\n        exp /= 2;\n\
    \        if(exp > 0) val *= val;\n        else break;\n    }\n    return result;\n\
    }\n"
  dependsOn:
  - lib/concepts/modint_concept.hpp
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/math/int_power.hpp
  requiredBy:
  - lib/radix/get_digit.hpp
  - lib/math/power.hpp
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/int_power.hpp
layout: document
redirect_from:
- /library/lib/math/int_power.hpp
- /library/lib/math/int_power.hpp.html
title: lib/math/int_power.hpp
---
