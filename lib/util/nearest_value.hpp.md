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
    \ 3 \"lib/util/nearest_value.hpp\"\n// abs\u304C\u4F7F\u3048\u308B\u578B\u306B\
    \u9650\u308B\ntemplate <class T> T nearest_value(const vector<T> &v, T key, bool\
    \ prioritizeBig = true) {\n    assert(v.size() > 0);\n    if(v.size() == 1) return\
    \ *v.begin();\n\n    auto lb = lower_bound(v.begin(), v.end(), key);\n    if(lb\
    \ == v.begin()) lb++;\n    else if(lb == v.end()) lb--;\n    T big = *lb;\n  \
    \  T small = *prev(lb);\n\n    if(abs(big - key) < abs(small - key)) return big;\n\
    \    else if(abs(big - key) > abs(small - key)) return small;\n    else {\n  \
    \      if(prioritizeBig) return big;\n        else return small;\n    }\n}\n\n\
    \ntemplate <class T> T nearest_value(const set<T> &v, T key, bool prioritizeBig\
    \ = true) {\n    assert(v.size() > 0);\n    if(v.size() == 1) return *v.begin();\n\
    \n    auto lb = v.lower_bound(key);\n    if(lb == v.begin()) lb++;\n    else if(lb\
    \ == v.end()) lb--;\n    T big = *lb;\n    T small = *prev(lb);\n\n    if(abs(big\
    \ - key) < abs(small - key)) return big;\n    else if(abs(big - key) > abs(small\
    \ - key)) return small;\n    else {\n        if(prioritizeBig) return big;\n \
    \       else return small;\n    }\n}\n\n// \u6700\u3082\u8FD1\u3044key\u306E\u5024\
    \u3092\u8FD4\u3059 value\u306F\u7121\u8996\ntemplate <class T, class U> T nearest_value(const\
    \ map<T, U> &v, T key, bool prioritizeBig = true) {\n    assert(v.size() > 0);\n\
    \    if(v.size() == 1) return v.begin()->first;\n\n    auto lb = v.lower_bound(key);\n\
    \    if(lb == v.begin()) lb++;\n    else if(lb == v.end()) lb--;\n    T big =\
    \ lb->first;\n    T small = prev(lb)->first;\n\n    if(abs(big - key) < abs(small\
    \ - key)) return big;\n    else if(abs(big - key) > abs(small - key)) return small;\n\
    \    else {\n        if(prioritizeBig) return big;\n        else return small;\n\
    \    }\n}\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\n// abs\u304C\u4F7F\u3048\u308B\
    \u578B\u306B\u9650\u308B\ntemplate <class T> T nearest_value(const vector<T> &v,\
    \ T key, bool prioritizeBig = true) {\n    assert(v.size() > 0);\n    if(v.size()\
    \ == 1) return *v.begin();\n\n    auto lb = lower_bound(v.begin(), v.end(), key);\n\
    \    if(lb == v.begin()) lb++;\n    else if(lb == v.end()) lb--;\n    T big =\
    \ *lb;\n    T small = *prev(lb);\n\n    if(abs(big - key) < abs(small - key))\
    \ return big;\n    else if(abs(big - key) > abs(small - key)) return small;\n\
    \    else {\n        if(prioritizeBig) return big;\n        else return small;\n\
    \    }\n}\n\n\ntemplate <class T> T nearest_value(const set<T> &v, T key, bool\
    \ prioritizeBig = true) {\n    assert(v.size() > 0);\n    if(v.size() == 1) return\
    \ *v.begin();\n\n    auto lb = v.lower_bound(key);\n    if(lb == v.begin()) lb++;\n\
    \    else if(lb == v.end()) lb--;\n    T big = *lb;\n    T small = *prev(lb);\n\
    \n    if(abs(big - key) < abs(small - key)) return big;\n    else if(abs(big -\
    \ key) > abs(small - key)) return small;\n    else {\n        if(prioritizeBig)\
    \ return big;\n        else return small;\n    }\n}\n\n// \u6700\u3082\u8FD1\u3044\
    key\u306E\u5024\u3092\u8FD4\u3059 value\u306F\u7121\u8996\ntemplate <class T,\
    \ class U> T nearest_value(const map<T, U> &v, T key, bool prioritizeBig = true)\
    \ {\n    assert(v.size() > 0);\n    if(v.size() == 1) return v.begin()->first;\n\
    \n    auto lb = v.lower_bound(key);\n    if(lb == v.begin()) lb++;\n    else if(lb\
    \ == v.end()) lb--;\n    T big = lb->first;\n    T small = prev(lb)->first;\n\n\
    \    if(abs(big - key) < abs(small - key)) return big;\n    else if(abs(big -\
    \ key) > abs(small - key)) return small;\n    else {\n        if(prioritizeBig)\
    \ return big;\n        else return small;\n    }\n}\n"
  dependsOn:
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/util/nearest_value.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/util/nearest_value.hpp
layout: document
redirect_from:
- /library/lib/util/nearest_value.hpp
- /library/lib/util/nearest_value.hpp.html
title: lib/util/nearest_value.hpp
---
