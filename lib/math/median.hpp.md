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
    \ 3 \"lib/math/median.hpp\"\n// \u6607\u9806\u307E\u305F\u306F\u964D\u9806\u306B\
    \u30BD\u30FC\u30C8\u6E08\u307F\u306E\u914D\u5217\u3092\u5165\u529B\u3068\u3059\
    \u308B\n// floor(\u4E2D\u592E\u5024)\u3092\u8FD4\u3059\ntemplate <class T> T median(const\
    \ vector<T> &v) {\n    static_assert(is_integral<T>::value, \"T must be integral\"\
    );\n    // assert(is_sorted(v.begin(), v.end()));\n\n    int n = v.size();\n \
    \   const T &l = v[n / 2 - 1];\n    const T &r = v[n / 2];\n    if(n % 2 == 1)\
    \ return r;\n    else if(l > 0 != r > 0) return floor_div(l + r, 2);\n    else\
    \ return l + floor_div(r - l, 2);\n}\n\n// \u6607\u9806\u307E\u305F\u306F\u964D\
    \u9806\u306B\u30BD\u30FC\u30C8\u6E08\u307F\u306E\u914D\u5217\u3092\u5165\u529B\
    \u3068\u3059\u308B\ntemplate <class T> string median_string(const vector<T> &v)\
    \ {\n    static_assert(is_integral<T>::value, \"T must be integral\");\n    //\
    \ assert(is_sorted(v.begin(), v.end()));\n\n    int n = v.size();\n    const T\
    \ &l = v[n / 2 - 1];\n    const T &r = v[n / 2];\n    T mid;\n    bool is_odd\
    \ = false;  // \u771F\u306E\u4E2D\u592E\u5024\u304C\u6574\u6570\u3067\u306A\u3044\
    \u5834\u5408\u306Ftrue\n    if(n % 2 == 1) mid = r;\n    else if(l > 0 != r >\
    \ 0) {\n        mid = floor_div(l + r, 2);\n        is_odd = (l + r) % 2;\n  \
    \  }\n    else {\n        mid = l + floor_div(r - l, 2);\n        is_odd = (r\
    \ - l) % 2;\n    }\n\n    string ret = \"\";\n    if(is_odd) {\n        // \u771F\
    \u306E\u4E2D\u592E\u5024\u306F mid+0.5 \u3067\u3042\u308B\n        if(mid < 0)\
    \ {\n            mid++;\n            mid = abs(mid);\n            ret += \"-\"\
    ;\n        }\n        ret += to_string(mid) + (string) \".5\";\n    }\n    else\
    \ {\n        ret += to_string(mid);\n    }\n    return ret;\n}\n\n// \u6607\u9806\
    \u307E\u305F\u306F\u964D\u9806\u306B\u30BD\u30FC\u30C8\u6E08\u307F\u306E\u914D\
    \u5217\u3092\u5165\u529B\u3068\u3059\u308B\ntemplate <class T> double median_double(const\
    \ vector<T> &v) {\n    int n = v.size();\n    double l = v[n / 2 - 1];\n    double\
    \ r = v[n / 2];\n    if(n % 2 == 1) return r;\n    else if(l > 0 != r > 0) return\
    \ (l + r) / 2.;\n    else return l - (l - r) / 2.;\n}\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\n// \u6607\u9806\u307E\u305F\u306F\
    \u964D\u9806\u306B\u30BD\u30FC\u30C8\u6E08\u307F\u306E\u914D\u5217\u3092\u5165\
    \u529B\u3068\u3059\u308B\n// floor(\u4E2D\u592E\u5024)\u3092\u8FD4\u3059\ntemplate\
    \ <class T> T median(const vector<T> &v) {\n    static_assert(is_integral<T>::value,\
    \ \"T must be integral\");\n    // assert(is_sorted(v.begin(), v.end()));\n\n\
    \    int n = v.size();\n    const T &l = v[n / 2 - 1];\n    const T &r = v[n /\
    \ 2];\n    if(n % 2 == 1) return r;\n    else if(l > 0 != r > 0) return floor_div(l\
    \ + r, 2);\n    else return l + floor_div(r - l, 2);\n}\n\n// \u6607\u9806\u307E\
    \u305F\u306F\u964D\u9806\u306B\u30BD\u30FC\u30C8\u6E08\u307F\u306E\u914D\u5217\
    \u3092\u5165\u529B\u3068\u3059\u308B\ntemplate <class T> string median_string(const\
    \ vector<T> &v) {\n    static_assert(is_integral<T>::value, \"T must be integral\"\
    );\n    // assert(is_sorted(v.begin(), v.end()));\n\n    int n = v.size();\n \
    \   const T &l = v[n / 2 - 1];\n    const T &r = v[n / 2];\n    T mid;\n    bool\
    \ is_odd = false;  // \u771F\u306E\u4E2D\u592E\u5024\u304C\u6574\u6570\u3067\u306A\
    \u3044\u5834\u5408\u306Ftrue\n    if(n % 2 == 1) mid = r;\n    else if(l > 0 !=\
    \ r > 0) {\n        mid = floor_div(l + r, 2);\n        is_odd = (l + r) % 2;\n\
    \    }\n    else {\n        mid = l + floor_div(r - l, 2);\n        is_odd = (r\
    \ - l) % 2;\n    }\n\n    string ret = \"\";\n    if(is_odd) {\n        // \u771F\
    \u306E\u4E2D\u592E\u5024\u306F mid+0.5 \u3067\u3042\u308B\n        if(mid < 0)\
    \ {\n            mid++;\n            mid = abs(mid);\n            ret += \"-\"\
    ;\n        }\n        ret += to_string(mid) + (string) \".5\";\n    }\n    else\
    \ {\n        ret += to_string(mid);\n    }\n    return ret;\n}\n\n// \u6607\u9806\
    \u307E\u305F\u306F\u964D\u9806\u306B\u30BD\u30FC\u30C8\u6E08\u307F\u306E\u914D\
    \u5217\u3092\u5165\u529B\u3068\u3059\u308B\ntemplate <class T> double median_double(const\
    \ vector<T> &v) {\n    int n = v.size();\n    double l = v[n / 2 - 1];\n    double\
    \ r = v[n / 2];\n    if(n % 2 == 1) return r;\n    else if(l > 0 != r > 0) return\
    \ (l + r) / 2.;\n    else return l - (l - r) / 2.;\n}\n"
  dependsOn:
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/math/median.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/median.hpp
layout: document
redirect_from:
- /library/lib/math/median.hpp
- /library/lib/math/median.hpp.html
title: lib/math/median.hpp
---
