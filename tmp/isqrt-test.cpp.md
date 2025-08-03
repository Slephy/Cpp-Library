---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tmp/isqrt-test.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing ull = unsigned long long;\nconst int INF\
    \ = (int)1e9 + 1001010;\nconst ll llINF = (long long)4e18 + 22000020;\nconst string\
    \ endn = \"\\n\";\ntemplate <class T> inline auto vector2(size_t i, size_t j,\
    \ const T &init = T()) {\n    return vector(i, vector<T>(j, init));\n}\nconst\
    \ string ELM_SEP = \" \", VEC_SEP = endn;\ntemplate <class T> istream &operator>>(istream\
    \ &i, vector<T> &A) {\n    for(auto &I : A) i >> I;\n    return i;\n}\ntemplate\
    \ <class T> ostream &operator<<(ostream &o, const vector<T> &A) {\n    int i =\
    \ A.size();\n    for(const auto &I : A) o << I << (--i ? ELM_SEP : \"\");\n  \
    \  return o;\n}\ntemplate <class T> ostream &operator<<(ostream &o, const vector<vector<T>>\
    \ &A) {\n    int i = A.size();\n    for(const auto &I : A) o << I << (--i ? VEC_SEP\
    \ : \"\");\n    return o;\n}\ntemplate <class T> vector<T> &operator++(vector<T>\
    \ &A, int) {\n    for(auto &I : A) I++;\n    return A;\n}\ntemplate <class T>\
    \ vector<T> &operator--(vector<T> &A, int) {\n    for(auto &I : A) I--;\n    return\
    \ A;\n}\ntemplate <class T, class U> bool chmax(T &a, const U &b) { return ((a\
    \ < b) ? (a = b, true) : false); }\ntemplate <class T, class U> bool chmin(T &a,\
    \ const U &b) { return ((a > b) ? (a = b, true) : false); }\nll floor(ll a, ll\
    \ b) {\n    if(b < 0) a = -a, b = -b;\n    return (a >= 0) ? a / b : (a + 1) /\
    \ b - 1;\n}\nll ceil(ll a, ll b) {\n    if(b < 0) a = -a, b = -b;\n    return\
    \ (a > 0) ? (a - 1) / b + 1 : a / b;\n}\nll check_bit(unsigned long long val,\
    \ unsigned long long digit) { return (val >> digit) & 1; }\n#ifdef DEBUG\n#include\
    \ <cpp-dump/cpp-dump.hpp>\n#define dump(...) cpp_dump(__VA_ARGS__)\nnamespace\
    \ cp = cpp_dump;\nstruct InitCppDump {\n    InitCppDump() {\n        if(!isatty(fileno(stderr)))\
    \ CPP_DUMP_SET_OPTION(es_style, cpp_dump::types::es_style_t::no_es);\n       \
    \ CPP_DUMP_SET_OPTION(log_label_func, cp::log_label::line());\n        CPP_DUMP_SET_OPTION(max_iteration_count,\
    \ 30);\n    }\n} init_cpp_dump;\n#else\n#define dump(...)\n#endif\n// ====================\
    \ \u3053\u3053\u307E\u3067\u30C6\u30F3\u30D7\u30EC ====================\n\n#include\
    \ <slephy-cpp-lib/math/isqrt.hpp>\nint main(int argc, char *argv[]){\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    \n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nusing\
    \ ull = unsigned long long;\nconst int INF = (int)1e9 + 1001010;\nconst ll llINF\
    \ = (long long)4e18 + 22000020;\nconst string endn = \"\\n\";\ntemplate <class\
    \ T> inline auto vector2(size_t i, size_t j, const T &init = T()) {\n    return\
    \ vector(i, vector<T>(j, init));\n}\nconst string ELM_SEP = \" \", VEC_SEP = endn;\n\
    template <class T> istream &operator>>(istream &i, vector<T> &A) {\n    for(auto\
    \ &I : A) i >> I;\n    return i;\n}\ntemplate <class T> ostream &operator<<(ostream\
    \ &o, const vector<T> &A) {\n    int i = A.size();\n    for(const auto &I : A)\
    \ o << I << (--i ? ELM_SEP : \"\");\n    return o;\n}\ntemplate <class T> ostream\
    \ &operator<<(ostream &o, const vector<vector<T>> &A) {\n    int i = A.size();\n\
    \    for(const auto &I : A) o << I << (--i ? VEC_SEP : \"\");\n    return o;\n\
    }\ntemplate <class T> vector<T> &operator++(vector<T> &A, int) {\n    for(auto\
    \ &I : A) I++;\n    return A;\n}\ntemplate <class T> vector<T> &operator--(vector<T>\
    \ &A, int) {\n    for(auto &I : A) I--;\n    return A;\n}\ntemplate <class T,\
    \ class U> bool chmax(T &a, const U &b) { return ((a < b) ? (a = b, true) : false);\
    \ }\ntemplate <class T, class U> bool chmin(T &a, const U &b) { return ((a > b)\
    \ ? (a = b, true) : false); }\nll floor(ll a, ll b) {\n    if(b < 0) a = -a, b\
    \ = -b;\n    return (a >= 0) ? a / b : (a + 1) / b - 1;\n}\nll ceil(ll a, ll b)\
    \ {\n    if(b < 0) a = -a, b = -b;\n    return (a > 0) ? (a - 1) / b + 1 : a /\
    \ b;\n}\nll check_bit(unsigned long long val, unsigned long long digit) { return\
    \ (val >> digit) & 1; }\n#ifdef DEBUG\n#include <cpp-dump/cpp-dump.hpp>\n#define\
    \ dump(...) cpp_dump(__VA_ARGS__)\nnamespace cp = cpp_dump;\nstruct InitCppDump\
    \ {\n    InitCppDump() {\n        if(!isatty(fileno(stderr))) CPP_DUMP_SET_OPTION(es_style,\
    \ cpp_dump::types::es_style_t::no_es);\n        CPP_DUMP_SET_OPTION(log_label_func,\
    \ cp::log_label::line());\n        CPP_DUMP_SET_OPTION(max_iteration_count, 30);\n\
    \    }\n} init_cpp_dump;\n#else\n#define dump(...)\n#endif\n// ====================\
    \ \u3053\u3053\u307E\u3067\u30C6\u30F3\u30D7\u30EC ====================\n\n#include\
    \ <slephy-cpp-lib/math/isqrt.hpp>\nint main(int argc, char *argv[]){\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    \n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: tmp/isqrt-test.cpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tmp/isqrt-test.cpp
layout: document
redirect_from:
- /library/tmp/isqrt-test.cpp
- /library/tmp/isqrt-test.cpp.html
title: tmp/isqrt-test.cpp
---
