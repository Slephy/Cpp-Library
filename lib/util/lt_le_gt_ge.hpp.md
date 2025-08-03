---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: lib/core/core.hpp
    title: lib/core/core.hpp
  - icon: ':warning:'
    path: lib/util/wrapped_lb_ub.hpp
    title: lib/util/wrapped_lb_ub.hpp
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
    \ 3 \"lib/util/wrapped_lb_ub.hpp\"\n\nnamespace slephy_wrapped_lb_ub {\ntemplate\
    \ <typename Container, typename Key>\nconcept SupportsStdLowerBound = requires(Container\
    \ container, Key key) {\n    { std::lower_bound(container.begin(), container.end(),\
    \ key) } -> std::same_as<typename Container::iterator>;\n};\n\ntemplate <typename\
    \ Container, typename Key>\nconcept HasMemberLowerBound = requires(Container container,\
    \ Key key) {\n    { container.lower_bound(key) } -> std::same_as<typename Container::iterator>;\n\
    };\n\ntemplate <typename Container, typename Key>\n    requires HasMemberLowerBound<Container,\
    \ Key>\nauto lower_bound_wrap(const Container &container, const Key &key) {\n\
    \    return container.lower_bound(key);\n}\n\ntemplate <typename Container, typename\
    \ Key>\n    requires(SupportsStdLowerBound<Container, Key> && !HasMemberLowerBound<Container,\
    \ Key>)\nauto lower_bound_wrap(const Container &container, const Key &key) {\n\
    \    return std::lower_bound(container.begin(), container.end(), key);\n}\n\n\
    template <typename Container, typename Key>\n    requires HasMemberLowerBound<Container,\
    \ Key>\nauto upper_bound_wrap(const Container &container, const Key &key) {\n\
    \    return container.upper_bound(key);\n}\n\ntemplate <typename Container, typename\
    \ Key>\n    requires(SupportsStdLowerBound<Container, Key> && !HasMemberLowerBound<Container,\
    \ Key>)\nauto upper_bound_wrap(const Container &container, const Key &key) {\n\
    \    return std::upper_bound(container.begin(), container.end(), key);\n}\n} \
    \ // namespace slephy_wrapped_lb_ub\nusing namespace slephy_wrapped_lb_ub;\n#line\
    \ 4 \"lib/util/lt_le_gt_ge.hpp\"\n\nnamespace slephy_lt_le_gt_ge {\ntemplate <typename\
    \ Container, typename Key>\n    requires(SupportsStdLowerBound<Container, Key>\
    \ || HasMemberLowerBound<Container, Key>)\noptional<Key> get_lt(const Container\
    \ &container, const Key &key) {\n    auto it = lower_bound_wrap(container, key);\n\
    \    if(it == container.begin()) return nullopt;\n    return *prev(it);\n}\n\n\
    template <typename Container, typename Key>\n    requires(SupportsStdLowerBound<Container,\
    \ Key> || HasMemberLowerBound<Container, Key>)\noptional<Key> get_le(const Container\
    \ &container, const Key &key) {\n    auto it = upper_bound_wrap(container, key);\n\
    \    if(it == container.begin()) return nullopt;\n    return *prev(it);\n}\n\n\
    template <typename Container, typename Key>\n    requires(SupportsStdLowerBound<Container,\
    \ Key> || HasMemberLowerBound<Container, Key>)\noptional<Key> get_gt(const Container\
    \ &container, const Key &key) {\n    auto it = upper_bound_wrap(container, key);\n\
    \    if(it == container.end()) return nullopt;\n    return *it;\n}\n\ntemplate\
    \ <typename Container, typename Key>\n    requires(SupportsStdLowerBound<Container,\
    \ Key> || HasMemberLowerBound<Container, Key>)\noptional<Key> get_ge(const Container\
    \ &container, const Key &key) {\n    auto it = lower_bound_wrap(container, key);\n\
    \    if(it == container.end()) return nullopt;\n    return *it;\n}\n\ntemplate\
    \ <typename Container, typename Key>\n    requires(SupportsStdLowerBound<Container,\
    \ Key> || HasMemberLowerBound<Container, Key>)\noptional<Key> pop_lt(Container\
    \ &container, const Key &key) {\n    auto it = lower_bound_wrap(container, key);\n\
    \    if(it == container.begin()) return nullopt;\n    Key ret = *prev(it);\n \
    \   container.erase(prev(it));\n    return ret;\n}\n\ntemplate <typename Container,\
    \ typename Key>\n    requires(SupportsStdLowerBound<Container, Key> || HasMemberLowerBound<Container,\
    \ Key>)\noptional<Key> pop_le(Container &container, const Key &key) {\n    auto\
    \ it = upper_bound_wrap(container, key);\n    if(it == container.begin()) return\
    \ nullopt;\n    Key ret = *prev(it);\n    container.erase(prev(it));\n    return\
    \ ret;\n}\n\ntemplate <typename Container, typename Key>\n    requires(SupportsStdLowerBound<Container,\
    \ Key> || HasMemberLowerBound<Container, Key>)\noptional<Key> pop_gt(Container\
    \ &container, const Key &key) {\n    auto it = upper_bound_wrap(container, key);\n\
    \    if(it == container.end()) return nullopt;\n    Key ret = *it;\n    container.erase(it);\n\
    \    return ret;\n}\n\ntemplate <typename Container, typename Key>\n    requires(SupportsStdLowerBound<Container,\
    \ Key> || HasMemberLowerBound<Container, Key>)\noptional<Key> pop_ge(Container\
    \ &container, const Key &key) {\n    auto it = lower_bound_wrap(container, key);\n\
    \    if(it == container.end()) return nullopt;\n    Key ret = *it;\n    container.erase(it);\n\
    \    return ret;\n}\n}  // namespace slephy_lt_le_gt_ge\nusing namespace slephy_lt_le_gt_ge;\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\n#include \"wrapped_lb_ub.hpp\"\
    \n\nnamespace slephy_lt_le_gt_ge {\ntemplate <typename Container, typename Key>\n\
    \    requires(SupportsStdLowerBound<Container, Key> || HasMemberLowerBound<Container,\
    \ Key>)\noptional<Key> get_lt(const Container &container, const Key &key) {\n\
    \    auto it = lower_bound_wrap(container, key);\n    if(it == container.begin())\
    \ return nullopt;\n    return *prev(it);\n}\n\ntemplate <typename Container, typename\
    \ Key>\n    requires(SupportsStdLowerBound<Container, Key> || HasMemberLowerBound<Container,\
    \ Key>)\noptional<Key> get_le(const Container &container, const Key &key) {\n\
    \    auto it = upper_bound_wrap(container, key);\n    if(it == container.begin())\
    \ return nullopt;\n    return *prev(it);\n}\n\ntemplate <typename Container, typename\
    \ Key>\n    requires(SupportsStdLowerBound<Container, Key> || HasMemberLowerBound<Container,\
    \ Key>)\noptional<Key> get_gt(const Container &container, const Key &key) {\n\
    \    auto it = upper_bound_wrap(container, key);\n    if(it == container.end())\
    \ return nullopt;\n    return *it;\n}\n\ntemplate <typename Container, typename\
    \ Key>\n    requires(SupportsStdLowerBound<Container, Key> || HasMemberLowerBound<Container,\
    \ Key>)\noptional<Key> get_ge(const Container &container, const Key &key) {\n\
    \    auto it = lower_bound_wrap(container, key);\n    if(it == container.end())\
    \ return nullopt;\n    return *it;\n}\n\ntemplate <typename Container, typename\
    \ Key>\n    requires(SupportsStdLowerBound<Container, Key> || HasMemberLowerBound<Container,\
    \ Key>)\noptional<Key> pop_lt(Container &container, const Key &key) {\n    auto\
    \ it = lower_bound_wrap(container, key);\n    if(it == container.begin()) return\
    \ nullopt;\n    Key ret = *prev(it);\n    container.erase(prev(it));\n    return\
    \ ret;\n}\n\ntemplate <typename Container, typename Key>\n    requires(SupportsStdLowerBound<Container,\
    \ Key> || HasMemberLowerBound<Container, Key>)\noptional<Key> pop_le(Container\
    \ &container, const Key &key) {\n    auto it = upper_bound_wrap(container, key);\n\
    \    if(it == container.begin()) return nullopt;\n    Key ret = *prev(it);\n \
    \   container.erase(prev(it));\n    return ret;\n}\n\ntemplate <typename Container,\
    \ typename Key>\n    requires(SupportsStdLowerBound<Container, Key> || HasMemberLowerBound<Container,\
    \ Key>)\noptional<Key> pop_gt(Container &container, const Key &key) {\n    auto\
    \ it = upper_bound_wrap(container, key);\n    if(it == container.end()) return\
    \ nullopt;\n    Key ret = *it;\n    container.erase(it);\n    return ret;\n}\n\
    \ntemplate <typename Container, typename Key>\n    requires(SupportsStdLowerBound<Container,\
    \ Key> || HasMemberLowerBound<Container, Key>)\noptional<Key> pop_ge(Container\
    \ &container, const Key &key) {\n    auto it = lower_bound_wrap(container, key);\n\
    \    if(it == container.end()) return nullopt;\n    Key ret = *it;\n    container.erase(it);\n\
    \    return ret;\n}\n}  // namespace slephy_lt_le_gt_ge\nusing namespace slephy_lt_le_gt_ge;\n"
  dependsOn:
  - lib/core/core.hpp
  - lib/util/wrapped_lb_ub.hpp
  isVerificationFile: false
  path: lib/util/lt_le_gt_ge.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/util/lt_le_gt_ge.hpp
layout: document
redirect_from:
- /library/lib/util/lt_le_gt_ge.hpp
- /library/lib/util/lt_le_gt_ge.hpp.html
title: lib/util/lt_le_gt_ge.hpp
---
