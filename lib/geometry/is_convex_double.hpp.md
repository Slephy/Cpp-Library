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
    \ 3 \"lib/geometry/is_convex_double.hpp\"\n// \u72ED\u7FA9\u51F8\u6027\u3092\u5224\
    \u5B9A\u3059\u308B\uFF08\u4EFB\u610F\u306E\u5185\u89D2\u304C180\u5EA6\u672A\u6E80\
    \uFF09\nbool is_convex_double(const vector<Point> &p){\n    assert(p.size() ==\
    \ 0 || typeid(p[0].px) == typeid(double));\n    if(p.size() <= 2) return true;\n\
    \    bool allP = true, allN = true; // \u5916\u7A4D\u304C\u3059\u3079\u3066\u6B63\
    \u304B\u3001\u3082\u3057\u304F\u306F\u3059\u3079\u3066\u8CA0\u304B\n    for(int\
    \ i = 0; i < p.size(); i++){\n        const auto &p1 = p[i];\n        const auto\
    \ &p2 = p[(i+1)%p.size()];\n        const auto &p3 = p[(i+2)%p.size()];\n    \
    \    auto cross = crs(p1-p2, p3-p2);\n        // EPS \u306E\u5927\u304D\u3055\u304C\
    \u9069\u5207\u3067\u306A\u3044\u53EF\u80FD\u6027\u30A2\u30EA\n        if(cross\
    \ <= EPS) allP = false;\n        else if(cross >= -EPS) allN = false;\n    }\n\
    \    return (allP || allN);\n}\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\n// \u72ED\u7FA9\u51F8\u6027\u3092\
    \u5224\u5B9A\u3059\u308B\uFF08\u4EFB\u610F\u306E\u5185\u89D2\u304C180\u5EA6\u672A\
    \u6E80\uFF09\nbool is_convex_double(const vector<Point> &p){\n    assert(p.size()\
    \ == 0 || typeid(p[0].px) == typeid(double));\n    if(p.size() <= 2) return true;\n\
    \    bool allP = true, allN = true; // \u5916\u7A4D\u304C\u3059\u3079\u3066\u6B63\
    \u304B\u3001\u3082\u3057\u304F\u306F\u3059\u3079\u3066\u8CA0\u304B\n    for(int\
    \ i = 0; i < p.size(); i++){\n        const auto &p1 = p[i];\n        const auto\
    \ &p2 = p[(i+1)%p.size()];\n        const auto &p3 = p[(i+2)%p.size()];\n    \
    \    auto cross = crs(p1-p2, p3-p2);\n        // EPS \u306E\u5927\u304D\u3055\u304C\
    \u9069\u5207\u3067\u306A\u3044\u53EF\u80FD\u6027\u30A2\u30EA\n        if(cross\
    \ <= EPS) allP = false;\n        else if(cross >= -EPS) allN = false;\n    }\n\
    \    return (allP || allN);\n}\n"
  dependsOn:
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/geometry/is_convex_double.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/geometry/is_convex_double.hpp
layout: document
redirect_from:
- /library/lib/geometry/is_convex_double.hpp
- /library/lib/geometry/is_convex_double.hpp.html
title: lib/geometry/is_convex_double.hpp
---
