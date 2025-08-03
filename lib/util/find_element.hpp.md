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
    \ 3 \"lib/util/find_element.hpp\"\n// \u30B3\u30F3\u30C6\u30CA\u5185 [first, last)\
    \ \u306B\u8981\u7D20val\u304C\u521D\u3081\u3066\u73FE\u308C\u308B(\u3082\u3057\
    \u304F\u306F\u73FE\u308C\u306A\u3044\uFF09\u30A4\u30C6\u30EC\u30FC\u30BF\u3092\
    \u7DDA\u5F62\u63A2\u7D22\u3057\u3066\u8FD4\u3059\n// find_first_*\u304C\u5148\u982D\
    \u304B\u3089\u3001find_last_*\u304C\u672B\u5C3E\u304B\u3089\u63A2\u7D22\u3059\u308B\
    \n// \u8FD4\u308A\u5024\u306F\u30A4\u30C6\u30EC\u30FC\u30BF\n// \u898B\u3064\u304B\
    \u3089\u306A\u304B\u3063\u305F\u5834\u5408\u306Flast\u3092\u8FD4\u3059\ntemplate\
    \ <class Iterator>\nIterator find_first_itr(const Iterator &first, const Iterator\
    \ &last,\n                        const typename iterator_traits<Iterator>::value_type\
    \ &val) {\n    for(auto itr = first; itr != last; itr++)\n        if(*itr == val)\
    \ return itr;\n    return last;\n};\ntemplate <class Iterator>\nIterator find_first_not_itr(const\
    \ Iterator &first, const Iterator &last,\n                            const typename\
    \ iterator_traits<Iterator>::value_type &val) {\n    for(auto itr = first; itr\
    \ != last; itr++)\n        if(*itr != val) return itr;\n    return last;\n};\n\
    template <class Iterator>\nIterator find_last_itr(const Iterator &first, const\
    \ Iterator &last,\n                       const typename iterator_traits<Iterator>::value_type\
    \ &val) {\n    if(first == last) return last;\n    for(auto itr = prev(last);;\
    \ itr--) {\n        if(*itr == val) return itr;\n        else if(itr == first)\
    \ return last;\n    }\n};\ntemplate <class Iterator>\nIterator find_last_not_itr(const\
    \ Iterator &first, const Iterator &last,\n                           const typename\
    \ iterator_traits<Iterator>::value_type &val) {\n    if(first == last) return\
    \ last;\n    for(auto itr = prev(last);; itr--) {\n        if(*itr != val) return\
    \ itr;\n        else if(itr == first) return last;\n    }\n};\ntemplate <class\
    \ Iterator>\nIterator find_first_itr(const Iterator &first, const Iterator &last,\n\
    \                        const function<bool(typename iterator_traits<Iterator>::value_type)>\
    \ &func) {\n    for(auto itr = first; itr != last; itr++)\n        if(func(*itr))\
    \ return itr;\n    return last;\n};\ntemplate <class Iterator>\nIterator find_last_itr(const\
    \ Iterator &first, const Iterator &last,\n                       const function<bool(typename\
    \ iterator_traits<Iterator>::value_type)> &func) {\n    if(first == last) return\
    \ last;\n    for(auto itr = prev(last);; itr--) {\n        if(func(*itr)) return\
    \ itr;\n        else if(itr == first) return last;\n    }\n};\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\n// \u30B3\u30F3\u30C6\u30CA\u5185\
    \ [first, last) \u306B\u8981\u7D20val\u304C\u521D\u3081\u3066\u73FE\u308C\u308B\
    (\u3082\u3057\u304F\u306F\u73FE\u308C\u306A\u3044\uFF09\u30A4\u30C6\u30EC\u30FC\
    \u30BF\u3092\u7DDA\u5F62\u63A2\u7D22\u3057\u3066\u8FD4\u3059\n// find_first_*\u304C\
    \u5148\u982D\u304B\u3089\u3001find_last_*\u304C\u672B\u5C3E\u304B\u3089\u63A2\u7D22\
    \u3059\u308B\n// \u8FD4\u308A\u5024\u306F\u30A4\u30C6\u30EC\u30FC\u30BF\n// \u898B\
    \u3064\u304B\u3089\u306A\u304B\u3063\u305F\u5834\u5408\u306Flast\u3092\u8FD4\u3059\
    \ntemplate <class Iterator>\nIterator find_first_itr(const Iterator &first, const\
    \ Iterator &last,\n                        const typename iterator_traits<Iterator>::value_type\
    \ &val) {\n    for(auto itr = first; itr != last; itr++)\n        if(*itr == val)\
    \ return itr;\n    return last;\n};\ntemplate <class Iterator>\nIterator find_first_not_itr(const\
    \ Iterator &first, const Iterator &last,\n                            const typename\
    \ iterator_traits<Iterator>::value_type &val) {\n    for(auto itr = first; itr\
    \ != last; itr++)\n        if(*itr != val) return itr;\n    return last;\n};\n\
    template <class Iterator>\nIterator find_last_itr(const Iterator &first, const\
    \ Iterator &last,\n                       const typename iterator_traits<Iterator>::value_type\
    \ &val) {\n    if(first == last) return last;\n    for(auto itr = prev(last);;\
    \ itr--) {\n        if(*itr == val) return itr;\n        else if(itr == first)\
    \ return last;\n    }\n};\ntemplate <class Iterator>\nIterator find_last_not_itr(const\
    \ Iterator &first, const Iterator &last,\n                           const typename\
    \ iterator_traits<Iterator>::value_type &val) {\n    if(first == last) return\
    \ last;\n    for(auto itr = prev(last);; itr--) {\n        if(*itr != val) return\
    \ itr;\n        else if(itr == first) return last;\n    }\n};\ntemplate <class\
    \ Iterator>\nIterator find_first_itr(const Iterator &first, const Iterator &last,\n\
    \                        const function<bool(typename iterator_traits<Iterator>::value_type)>\
    \ &func) {\n    for(auto itr = first; itr != last; itr++)\n        if(func(*itr))\
    \ return itr;\n    return last;\n};\ntemplate <class Iterator>\nIterator find_last_itr(const\
    \ Iterator &first, const Iterator &last,\n                       const function<bool(typename\
    \ iterator_traits<Iterator>::value_type)> &func) {\n    if(first == last) return\
    \ last;\n    for(auto itr = prev(last);; itr--) {\n        if(func(*itr)) return\
    \ itr;\n        else if(itr == first) return last;\n    }\n};\n"
  dependsOn:
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/util/find_element.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/util/find_element.hpp
layout: document
redirect_from:
- /library/lib/util/find_element.hpp
- /library/lib/util/find_element.hpp.html
title: lib/util/find_element.hpp
---
