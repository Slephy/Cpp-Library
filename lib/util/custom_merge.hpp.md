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
    \ 3 \"lib/util/custom_merge.hpp\"\n\n// std::merge \u3068\u57FA\u672C\u7684\u306B\
    \u540C\u3058\n// \u305F\u3060\u3057 [first1, last1) \u3068 [first2, last2) \u304C\
    \u305D\u308C\u305E\u308C\u30BD\u30FC\u30C8\u6E08\u307F\u3067\u3042\u308B\u3053\
    \u3068\u3092\u4EEE\u5B9A\u3057\u306A\u3044\n// \u3088\u308A\u5E83\u3044\u7528\u9014\
    \u3067\u4F7F\u3048\u308B\u304C\u3001merge\u5F8C\u306E\u914D\u5217\u304C\u30BD\u30FC\
    \u30C8\u6E08\u307F\u3067\u3042\u308B\u3053\u3068\u306F\u4FDD\u8A3C\u3055\u308C\
    \u306A\u3044\n// O(N + M)\n\n// \u51FA\u529B\u30A4\u30C6\u30EC\u30FC\u30BF\u7248\
    \ntemplate <class InputIterator1, class InputIterator2, class OutputIterator,\
    \ class Compare>\nconstexpr OutputIterator custom_merge(InputIterator1 first1,\
    \ InputIterator1 last1, InputIterator2 first2,\n                             \
    \         InputIterator2 last2, OutputIterator result, Compare cmp) {\n    while(first1\
    \ != last1 && first2 != last2) {\n        if(cmp(*first1, *first2)) {\n      \
    \      *result = *first1;\n            ++first1;\n        }\n        else {\n\
    \            *result = *first2;\n            ++first2;\n        }\n        ++result;\n\
    \    }\n\n    // \u6B8B\u308A\u306E\u8981\u7D20\u3092\u30B3\u30D4\u30FC\n    result\
    \ = std::copy(first1, last1, result);\n    result = std::copy(first2, last2, result);\n\
    \n    return result;\n}\n\n// vector\u8FD4\u5374\u7248\ntemplate <class InputIterator,\
    \ class Compare>\nauto custom_merge(InputIterator first1, InputIterator last1,\
    \ InputIterator first2, InputIterator last2, Compare cmp) {\n    using T = typename\
    \ iterator_traits<InputIterator>::value_type;\n\n    vector<T> result;\n    result.reserve(distance(first1,\
    \ last1) + distance(first2, last2));\n\n    custom_merge(first1, last1, first2,\
    \ last2, back_inserter(result), cmp);\n\n    return result;\n}\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\n\n// std::merge \u3068\u57FA\
    \u672C\u7684\u306B\u540C\u3058\n// \u305F\u3060\u3057 [first1, last1) \u3068 [first2,\
    \ last2) \u304C\u305D\u308C\u305E\u308C\u30BD\u30FC\u30C8\u6E08\u307F\u3067\u3042\
    \u308B\u3053\u3068\u3092\u4EEE\u5B9A\u3057\u306A\u3044\n// \u3088\u308A\u5E83\u3044\
    \u7528\u9014\u3067\u4F7F\u3048\u308B\u304C\u3001merge\u5F8C\u306E\u914D\u5217\u304C\
    \u30BD\u30FC\u30C8\u6E08\u307F\u3067\u3042\u308B\u3053\u3068\u306F\u4FDD\u8A3C\
    \u3055\u308C\u306A\u3044\n// O(N + M)\n\n// \u51FA\u529B\u30A4\u30C6\u30EC\u30FC\
    \u30BF\u7248\ntemplate <class InputIterator1, class InputIterator2, class OutputIterator,\
    \ class Compare>\nconstexpr OutputIterator custom_merge(InputIterator1 first1,\
    \ InputIterator1 last1, InputIterator2 first2,\n                             \
    \         InputIterator2 last2, OutputIterator result, Compare cmp) {\n    while(first1\
    \ != last1 && first2 != last2) {\n        if(cmp(*first1, *first2)) {\n      \
    \      *result = *first1;\n            ++first1;\n        }\n        else {\n\
    \            *result = *first2;\n            ++first2;\n        }\n        ++result;\n\
    \    }\n\n    // \u6B8B\u308A\u306E\u8981\u7D20\u3092\u30B3\u30D4\u30FC\n    result\
    \ = std::copy(first1, last1, result);\n    result = std::copy(first2, last2, result);\n\
    \n    return result;\n}\n\n// vector\u8FD4\u5374\u7248\ntemplate <class InputIterator,\
    \ class Compare>\nauto custom_merge(InputIterator first1, InputIterator last1,\
    \ InputIterator first2, InputIterator last2, Compare cmp) {\n    using T = typename\
    \ iterator_traits<InputIterator>::value_type;\n\n    vector<T> result;\n    result.reserve(distance(first1,\
    \ last1) + distance(first2, last2));\n\n    custom_merge(first1, last1, first2,\
    \ last2, back_inserter(result), cmp);\n\n    return result;\n}\n"
  dependsOn:
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/util/custom_merge.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/util/custom_merge.hpp
layout: document
redirect_from:
- /library/lib/util/custom_merge.hpp
- /library/lib/util/custom_merge.hpp.html
title: lib/util/custom_merge.hpp
---
