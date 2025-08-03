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
    \ 3 \"lib/geometry/convex_hull_ll.hpp\"\n// \u51F8\u5305\u3092\u69CB\u6210\u3059\
    \u308B\u9802\u70B9\u3092\u8FD4\u3059\n// \u51F8\u5305\u306E\u8FBA\u4E0A\u306E\u70B9\
    \u3092\u53CD\u6642\u8A08\u56DE\u308A\u306B\u4E26\u3079\u3066\u51FA\u529B\u3059\
    \u308B\u3002\n// \u8FD4\u308A\u5024\u306E\u7B2C\u4E00\u8981\u7D20\u306F\u5F15\u6570\
    \u306E\u7B2C\u4E00\u8981\u7D20\u3068\u5FC5\u305A\u4E00\u81F4\u3059\u308B\u3002\
    \n// \u5F15\u6570\u3068\u3057\u3066\u6E21\u3059\u914D\u5217\u306F\u3001x,y\u8EF8\
    \u306E\u4E21\u65B9\u306B\u3064\u3044\u3066\u6607\u9806\u307E\u305F\u306F\u964D\
    \u9806\u306B\u30BD\u30FC\u30C8\u3055\u308C\u3066\u3044\u308B\u3082\u306E\u3068\
    \u3059\u308B\u3002\n// x\u306E\u6607\u9806\u304B\u3064y\u306E\u964D\u9806\u306A\
    \u3069\u3082\u53EF\u3002\nvector<Point> convex_hull_ll(const vector<Point> &p)\
    \ {\n    assert(p.size() == 0 || typeid(p[0].px) == typeid(ll));\n    vector<Point>\
    \ g1, g2;\n    g1.emplace_back(p[0]);\n    g1.emplace_back(p[1]);\n    g2.emplace_back(p[0]);\n\
    \    g2.emplace_back(p[1]);\n\n    for(int i = 2; i < p.size(); i++) {\n     \
    \   // \u51F8\u5305\u306E\u8FBA\u4E0A\u306E\u70B9\u3092\u3059\u3079\u3066\u51FA\
    \u529B\u3059\u308B\n        // \u51F8\u5305\u3092\u306A\u3059\u9802\u70B9\u306E\
    \u307F\u306B\u3057\u305F\u3044\u306A\u3089\u3070\u3001\u6761\u4EF6\u5F0F\u672B\
    \u5C3E\u306E = \u3092\u524A\u9664\u3059\u308B\n        while(g1.size() >= 2 &&\
    \ crs(g1[g1.size() - 2] - g1[g1.size() - 1], p[i] - g1[g1.size() - 1]) >= 0) {\n\
    \            g1.pop_back();\n        }\n        while(g2.size() >= 2 && crs(g2[g2.size()\
    \ - 2] - g2[g2.size() - 1], p[i] - g2[g2.size() - 1]) <= 0) {\n            g2.pop_back();\n\
    \        }\n\n        g1.emplace_back(p[i]);\n        g2.emplace_back(p[i]);\n\
    \    }\n\n    vector<Point> &ret = g1;\n    ret.insert(ret.end(), g2.rbegin()\
    \ + 1, g2.rend() - 1);\n    return ret;\n}\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\n// \u51F8\u5305\u3092\u69CB\u6210\
    \u3059\u308B\u9802\u70B9\u3092\u8FD4\u3059\n// \u51F8\u5305\u306E\u8FBA\u4E0A\u306E\
    \u70B9\u3092\u53CD\u6642\u8A08\u56DE\u308A\u306B\u4E26\u3079\u3066\u51FA\u529B\
    \u3059\u308B\u3002\n// \u8FD4\u308A\u5024\u306E\u7B2C\u4E00\u8981\u7D20\u306F\u5F15\
    \u6570\u306E\u7B2C\u4E00\u8981\u7D20\u3068\u5FC5\u305A\u4E00\u81F4\u3059\u308B\
    \u3002\n// \u5F15\u6570\u3068\u3057\u3066\u6E21\u3059\u914D\u5217\u306F\u3001\
    x,y\u8EF8\u306E\u4E21\u65B9\u306B\u3064\u3044\u3066\u6607\u9806\u307E\u305F\u306F\
    \u964D\u9806\u306B\u30BD\u30FC\u30C8\u3055\u308C\u3066\u3044\u308B\u3082\u306E\
    \u3068\u3059\u308B\u3002\n// x\u306E\u6607\u9806\u304B\u3064y\u306E\u964D\u9806\
    \u306A\u3069\u3082\u53EF\u3002\nvector<Point> convex_hull_ll(const vector<Point>\
    \ &p) {\n    assert(p.size() == 0 || typeid(p[0].px) == typeid(ll));\n    vector<Point>\
    \ g1, g2;\n    g1.emplace_back(p[0]);\n    g1.emplace_back(p[1]);\n    g2.emplace_back(p[0]);\n\
    \    g2.emplace_back(p[1]);\n\n    for(int i = 2; i < p.size(); i++) {\n     \
    \   // \u51F8\u5305\u306E\u8FBA\u4E0A\u306E\u70B9\u3092\u3059\u3079\u3066\u51FA\
    \u529B\u3059\u308B\n        // \u51F8\u5305\u3092\u306A\u3059\u9802\u70B9\u306E\
    \u307F\u306B\u3057\u305F\u3044\u306A\u3089\u3070\u3001\u6761\u4EF6\u5F0F\u672B\
    \u5C3E\u306E = \u3092\u524A\u9664\u3059\u308B\n        while(g1.size() >= 2 &&\
    \ crs(g1[g1.size() - 2] - g1[g1.size() - 1], p[i] - g1[g1.size() - 1]) >= 0) {\n\
    \            g1.pop_back();\n        }\n        while(g2.size() >= 2 && crs(g2[g2.size()\
    \ - 2] - g2[g2.size() - 1], p[i] - g2[g2.size() - 1]) <= 0) {\n            g2.pop_back();\n\
    \        }\n\n        g1.emplace_back(p[i]);\n        g2.emplace_back(p[i]);\n\
    \    }\n\n    vector<Point> &ret = g1;\n    ret.insert(ret.end(), g2.rbegin()\
    \ + 1, g2.rend() - 1);\n    return ret;\n}\n"
  dependsOn:
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/geometry/convex_hull_ll.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/geometry/convex_hull_ll.hpp
layout: document
redirect_from:
- /library/lib/geometry/convex_hull_ll.hpp
- /library/lib/geometry/convex_hull_ll.hpp.html
title: lib/geometry/convex_hull_ll.hpp
---
