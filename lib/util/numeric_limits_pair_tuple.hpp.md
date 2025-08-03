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
    \ 3 \"lib/util/numeric_limits_pair_tuple.hpp\"\nnamespace std {\ntemplate <class\
    \ T, class U> struct numeric_limits<pair<T, U>> {\n    static constexpr bool is_specialized\
    \ = true;\n    static constexpr auto max() { return pair<T, U>(numeric_limits<T>::max(),\
    \ numeric_limits<U>::max()); }\n    static constexpr auto min() { return pair<T,\
    \ U>(numeric_limits<T>::min(), numeric_limits<U>::min()); }\n};\n\ntemplate <typename...\
    \ Ts> struct numeric_limits<tuple<Ts...>> {\n    static constexpr bool is_specialized\
    \ = true;\n\n    template <size_t... Is> static constexpr auto make_tuple_max(index_sequence<Is...>)\
    \ {\n        return make_tuple(numeric_limits<tuple_element_t<Is, tuple<Ts...>>>::max()...);\n\
    \    }\n\n    template <size_t... Is> static constexpr auto make_tuple_min(index_sequence<Is...>)\
    \ {\n        return make_tuple(numeric_limits<tuple_element_t<Is, tuple<Ts...>>>::min()...);\n\
    \    }\n\n    static constexpr auto max() { return make_tuple_max(index_sequence_for<Ts...>{});\
    \ }\n\n    static constexpr auto min() { return make_tuple_min(index_sequence_for<Ts...>{});\
    \ }\n};\n};  // namespace std\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\nnamespace std {\ntemplate <class\
    \ T, class U> struct numeric_limits<pair<T, U>> {\n    static constexpr bool is_specialized\
    \ = true;\n    static constexpr auto max() { return pair<T, U>(numeric_limits<T>::max(),\
    \ numeric_limits<U>::max()); }\n    static constexpr auto min() { return pair<T,\
    \ U>(numeric_limits<T>::min(), numeric_limits<U>::min()); }\n};\n\ntemplate <typename...\
    \ Ts> struct numeric_limits<tuple<Ts...>> {\n    static constexpr bool is_specialized\
    \ = true;\n\n    template <size_t... Is> static constexpr auto make_tuple_max(index_sequence<Is...>)\
    \ {\n        return make_tuple(numeric_limits<tuple_element_t<Is, tuple<Ts...>>>::max()...);\n\
    \    }\n\n    template <size_t... Is> static constexpr auto make_tuple_min(index_sequence<Is...>)\
    \ {\n        return make_tuple(numeric_limits<tuple_element_t<Is, tuple<Ts...>>>::min()...);\n\
    \    }\n\n    static constexpr auto max() { return make_tuple_max(index_sequence_for<Ts...>{});\
    \ }\n\n    static constexpr auto min() { return make_tuple_min(index_sequence_for<Ts...>{});\
    \ }\n};\n};  // namespace std\n"
  dependsOn:
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/util/numeric_limits_pair_tuple.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/util/numeric_limits_pair_tuple.hpp
layout: document
redirect_from:
- /library/lib/util/numeric_limits_pair_tuple.hpp
- /library/lib/util/numeric_limits_pair_tuple.hpp.html
title: lib/util/numeric_limits_pair_tuple.hpp
---
