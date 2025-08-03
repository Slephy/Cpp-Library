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
    \ 3 \"lib/dp/max_rectangle.hpp\"\n// \u30D2\u30B9\u30C8\u30B0\u30E9\u30E0\u306E\
    \u6700\u5927\u9577\u65B9\u5F62\u3092\u8FD4\u3059\n// h \u306E\u8981\u7D20\u304C\
    \u3059\u3079\u30660\u4EE5\u4E0A\u3067\u3042\u308B\u3053\u3068\u304C\u5FC5\u8981\
    \nll calc_max_rectangle(const vector<ll> &h) {\n#ifdef DEBUG\n    for(int i =\
    \ 0; i < h.size(); i++) assert(h[i] >= 0);\n#endif\n    if(h.empty()) return 0;\n\
    \n    const int n = h.size();\n    vector<ll> l(n), r(n);  // \u9AD8\u3055 h[i]\
    \ \u3092\u5E83\u3052\u3089\u308C\u308B\u306E\u306F\u6700\u5927\u3067 [l[i], r[i])\
    \ \u3067\u3042\u308B\n    vector<ll> st;\n    // l \u3092\u6C42\u3081\u308B\n\
    \    for(int i = 0; i < n; i++) {\n        while(!st.empty() && h[st.back()] >=\
    \ h[i]) st.pop_back();\n        if(st.empty()) l[i] = 0;\n        else l[i] =\
    \ st.back() + 1;\n        st.emplace_back(i);\n    }\n\n    st.clear();\n    //\
    \ r \u3092\u6C42\u3081\u308B\n    for(int i = n - 1; i >= 0; i--) {\n        while(!st.empty()\
    \ && h[st.back()] >= h[i]) st.pop_back();\n        if(st.empty()) r[i] = n;\n\
    \        else r[i] = st.back();\n        st.emplace_back(i);\n    }\n\n    //\
    \ \u7B54\u3048\u3092\u6C42\u3081\u308B\n    ll ret = 0;\n    for(int i = 0; i\
    \ < n; i++) {\n        ll area = h[i] * (r[i] - l[i]);\n        chmax(ret, area);\n\
    \    }\n    return ret;\n}\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\n// \u30D2\u30B9\u30C8\u30B0\u30E9\
    \u30E0\u306E\u6700\u5927\u9577\u65B9\u5F62\u3092\u8FD4\u3059\n// h \u306E\u8981\
    \u7D20\u304C\u3059\u3079\u30660\u4EE5\u4E0A\u3067\u3042\u308B\u3053\u3068\u304C\
    \u5FC5\u8981\nll calc_max_rectangle(const vector<ll> &h) {\n#ifdef DEBUG\n   \
    \ for(int i = 0; i < h.size(); i++) assert(h[i] >= 0);\n#endif\n    if(h.empty())\
    \ return 0;\n\n    const int n = h.size();\n    vector<ll> l(n), r(n);  // \u9AD8\
    \u3055 h[i] \u3092\u5E83\u3052\u3089\u308C\u308B\u306E\u306F\u6700\u5927\u3067\
    \ [l[i], r[i]) \u3067\u3042\u308B\n    vector<ll> st;\n    // l \u3092\u6C42\u3081\
    \u308B\n    for(int i = 0; i < n; i++) {\n        while(!st.empty() && h[st.back()]\
    \ >= h[i]) st.pop_back();\n        if(st.empty()) l[i] = 0;\n        else l[i]\
    \ = st.back() + 1;\n        st.emplace_back(i);\n    }\n\n    st.clear();\n  \
    \  // r \u3092\u6C42\u3081\u308B\n    for(int i = n - 1; i >= 0; i--) {\n    \
    \    while(!st.empty() && h[st.back()] >= h[i]) st.pop_back();\n        if(st.empty())\
    \ r[i] = n;\n        else r[i] = st.back();\n        st.emplace_back(i);\n   \
    \ }\n\n    // \u7B54\u3048\u3092\u6C42\u3081\u308B\n    ll ret = 0;\n    for(int\
    \ i = 0; i < n; i++) {\n        ll area = h[i] * (r[i] - l[i]);\n        chmax(ret,\
    \ area);\n    }\n    return ret;\n}\n"
  dependsOn:
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/dp/max_rectangle.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/dp/max_rectangle.hpp
layout: document
redirect_from:
- /library/lib/dp/max_rectangle.hpp
- /library/lib/dp/max_rectangle.hpp.html
title: lib/dp/max_rectangle.hpp
---
