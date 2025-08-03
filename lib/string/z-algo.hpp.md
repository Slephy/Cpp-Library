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
    \ 3 \"lib/string/z-algo.hpp\"\n\ntemplate <typename Iterator> vector<int> z_algorithm(const\
    \ Iterator begin, const Iterator end) {\n    int n = end - begin;\n    assert(n\
    \ >= 0);\n    vector<int> ret(n, 0);\n    ret[0] = n;\n\n    for(int i = 1, j\
    \ = 0; i < n;) {\n        while(i + j < n && begin[i + j] == begin[j]) j++;\n\
    \        ret[i] = j;\n        if(j == 0) {\n            i++;\n            continue;\n\
    \        }\n\n        int k = 1;\n        while(i + k < n && k + ret[k] < ret[i])\
    \ ret[i + k] = ret[k], k++;\n        i += k;\n        j -= k;\n    }\n    return\
    \ ret;\n}\n\nvector<int> z_algorithm(const string &s) { return z_algorithm(s.begin(),\
    \ s.end()); }\n\ntemplate <class T> vector<int> z_algorithm(const vector<T> &v)\
    \ { return z_algorithm(v.begin(), v.end()); }\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\n\ntemplate <typename Iterator>\
    \ vector<int> z_algorithm(const Iterator begin, const Iterator end) {\n    int\
    \ n = end - begin;\n    assert(n >= 0);\n    vector<int> ret(n, 0);\n    ret[0]\
    \ = n;\n\n    for(int i = 1, j = 0; i < n;) {\n        while(i + j < n && begin[i\
    \ + j] == begin[j]) j++;\n        ret[i] = j;\n        if(j == 0) {\n        \
    \    i++;\n            continue;\n        }\n\n        int k = 1;\n        while(i\
    \ + k < n && k + ret[k] < ret[i]) ret[i + k] = ret[k], k++;\n        i += k;\n\
    \        j -= k;\n    }\n    return ret;\n}\n\nvector<int> z_algorithm(const string\
    \ &s) { return z_algorithm(s.begin(), s.end()); }\n\ntemplate <class T> vector<int>\
    \ z_algorithm(const vector<T> &v) { return z_algorithm(v.begin(), v.end()); }\n"
  dependsOn:
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/string/z-algo.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/string/z-algo.hpp
layout: document
redirect_from:
- /library/lib/string/z-algo.hpp
- /library/lib/string/z-algo.hpp.html
title: lib/string/z-algo.hpp
---
