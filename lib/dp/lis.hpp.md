---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: lib/core/core.hpp
    title: lib/core/core.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: lib/dp/permutation_lcs.hpp
    title: lib/dp/permutation_lcs.hpp
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
    \ 3 \"lib/dp/lis.hpp\"\nenum class LISType {\n    value,  // LIS\u3092\u69CB\u6210\
    \u3059\u308B\u5024\u3092\u8FD4\u3059\n    index,  // LIS\u3092\u69CB\u6210\u3059\
    \u308B\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u3092\u8FD4\u3059\n};\n\n// LIS\u3092\
    \u69CB\u6210\u3057\u3066\u8FD4\u3059\n// O(NlogN)\ntemplate <class T> vector<T>\
    \ LIS(const vector<T> &vec, LISType lisType = LISType::value) {\n    if(vec.empty())\
    \ return {};\n    int n = vec.size();\n    vector<T> dp(n, numeric_limits<T>::max());\
    \  // \u6570\u5024\u578B\u4EE5\u5916\u3067\u4F7F\u3046\u5834\u5408\u306F\u3001\
    \u6700\u5927\u5024\u3092\u81EA\u5206\u3067\u5B9A\u7FA9\u3059\u308B\u5FC5\u8981\
    \u3042\u308A\n    vector<int> dp_pos(n);                      // \u5404\u8981\u7D20\
    \u306ELIS\u3067\u306E\u4F4D\u7F6E\n    int max_length = 0;                   \
    \      // LIS\u306E\u9577\u3055\n    int end_id = 0;                         \
    \    // \u6700\u5F8C\u306BLIS\u306E\u9577\u3055\u304C\u66F4\u65B0\u3055\u308C\u305F\
    \u3068\u304D\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n\n    // LIS\u3092\u8A08\
    \u7B97\n    for(int i = 0; i < n; i++) {\n        int lb_index = lower_bound(dp.begin(),\
    \ dp.end(), vec[i]) - dp.begin();\n        dp[lb_index] = vec[i];\n        dp_pos[i]\
    \ = lb_index;\n        if(chmax(max_length, lb_index + 1)) end_id = i;\n    }\n\
    \n    // LIS\u3092\u69CB\u7BC9\n    vector<T> ret;\n    int index = max_length\
    \ - 1;\n    for(int i = end_id; i >= 0; i--) {\n        if(dp_pos[i] == index)\
    \ {\n            if(lisType == LISType::value) ret.emplace_back(vec[i]);\n   \
    \         if(lisType == LISType::index) ret.emplace_back(i);\n            index--;\n\
    \            if(index < 0) break;\n        }\n    }\n\n    reverse(ret.begin(),\
    \ ret.end());\n    return ret;\n}\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\nenum class LISType {\n    value,\
    \  // LIS\u3092\u69CB\u6210\u3059\u308B\u5024\u3092\u8FD4\u3059\n    index,  //\
    \ LIS\u3092\u69CB\u6210\u3059\u308B\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u3092\u8FD4\
    \u3059\n};\n\n// LIS\u3092\u69CB\u6210\u3057\u3066\u8FD4\u3059\n// O(NlogN)\n\
    template <class T> vector<T> LIS(const vector<T> &vec, LISType lisType = LISType::value)\
    \ {\n    if(vec.empty()) return {};\n    int n = vec.size();\n    vector<T> dp(n,\
    \ numeric_limits<T>::max());  // \u6570\u5024\u578B\u4EE5\u5916\u3067\u4F7F\u3046\
    \u5834\u5408\u306F\u3001\u6700\u5927\u5024\u3092\u81EA\u5206\u3067\u5B9A\u7FA9\
    \u3059\u308B\u5FC5\u8981\u3042\u308A\n    vector<int> dp_pos(n);             \
    \         // \u5404\u8981\u7D20\u306ELIS\u3067\u306E\u4F4D\u7F6E\n    int max_length\
    \ = 0;                         // LIS\u306E\u9577\u3055\n    int end_id = 0; \
    \                            // \u6700\u5F8C\u306BLIS\u306E\u9577\u3055\u304C\u66F4\
    \u65B0\u3055\u308C\u305F\u3068\u304D\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\
    \n\n    // LIS\u3092\u8A08\u7B97\n    for(int i = 0; i < n; i++) {\n        int\
    \ lb_index = lower_bound(dp.begin(), dp.end(), vec[i]) - dp.begin();\n       \
    \ dp[lb_index] = vec[i];\n        dp_pos[i] = lb_index;\n        if(chmax(max_length,\
    \ lb_index + 1)) end_id = i;\n    }\n\n    // LIS\u3092\u69CB\u7BC9\n    vector<T>\
    \ ret;\n    int index = max_length - 1;\n    for(int i = end_id; i >= 0; i--)\
    \ {\n        if(dp_pos[i] == index) {\n            if(lisType == LISType::value)\
    \ ret.emplace_back(vec[i]);\n            if(lisType == LISType::index) ret.emplace_back(i);\n\
    \            index--;\n            if(index < 0) break;\n        }\n    }\n\n\
    \    reverse(ret.begin(), ret.end());\n    return ret;\n}\n"
  dependsOn:
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/dp/lis.hpp
  requiredBy:
  - lib/dp/permutation_lcs.hpp
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/dp/lis.hpp
layout: document
redirect_from:
- /library/lib/dp/lis.hpp
- /library/lib/dp/lis.hpp.html
title: lib/dp/lis.hpp
---
