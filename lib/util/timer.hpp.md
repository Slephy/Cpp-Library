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
    links:
    - https://naskya.net/post/0004/
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
    \ 3 \"lib/util/timer.hpp\"\n// from : https://naskya.net/post/0004/\n#line 5 \"\
    lib/util/timer.hpp\"\nnamespace utility {\nstruct Timer {\nprivate:\n    const\
    \ std::chrono::system_clock::time_point start;\n\npublic:\n    const unsigned\
    \ TIME_LIMIT;  // ms\n\n    // time_limit[ms]\n    Timer(unsigned time_limit =\
    \ 2000 - 50) noexcept : TIME_LIMIT(time_limit), start(std::chrono::system_clock::now())\
    \ {}\n\n    // \u7D4C\u904E\u6642\u9593 (ms) \u3092\u8FD4\u3059\n    [[nodiscard]]\
    \ auto elapsed() const {\n        using namespace std::chrono;\n        return\
    \ duration_cast<milliseconds>(system_clock::now() - start).count();\n    }\n\n\
    \    // \u7D4C\u904E\u6642\u9593\u306E\u5272\u5408\u3092\u8FD4\u3059\n    [[nodiscard]]\
    \ double elapsed_ratio() const { return elapsed() / static_cast<double>(TIME_LIMIT);\
    \ }\n\n    // \u7D4C\u904E\u6642\u9593\u304C\u5236\u9650\u6642\u9593\u306E nume/deno\
    \ \u500D\u672A\u6E80\u304B\u3092\u8FD4\u3059\n    // \u4F8B\u3048\u3070 frac<1,\
    \ 2>() \u306F\u7D4C\u904E\u6642\u9593\u304C\u5236\u9650\u6642\u9593\u306E 1/2\
    \ \u672A\u6E80\u304B\u3092\u8FD4\u3059\n    template <unsigned nume, unsigned\
    \ deno> [[nodiscard]] bool frac() const {\n        return elapsed() * deno < TIME_LIMIT\
    \ * nume;\n    }\n\n    // \u7D4C\u904E\u6642\u9593\u304C\u5236\u9650\u6642\u9593\
    \u672A\u6E80\u304B\u3092\u8FD4\u3059\n    [[nodiscard]] bool good() const { return\
    \ elapsed() < TIME_LIMIT; }\n};\n}  // namespace utility\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\n// from : https://naskya.net/post/0004/\n\
    #include <chrono>\nnamespace utility {\nstruct Timer {\nprivate:\n    const std::chrono::system_clock::time_point\
    \ start;\n\npublic:\n    const unsigned TIME_LIMIT;  // ms\n\n    // time_limit[ms]\n\
    \    Timer(unsigned time_limit = 2000 - 50) noexcept : TIME_LIMIT(time_limit),\
    \ start(std::chrono::system_clock::now()) {}\n\n    // \u7D4C\u904E\u6642\u9593\
    \ (ms) \u3092\u8FD4\u3059\n    [[nodiscard]] auto elapsed() const {\n        using\
    \ namespace std::chrono;\n        return duration_cast<milliseconds>(system_clock::now()\
    \ - start).count();\n    }\n\n    // \u7D4C\u904E\u6642\u9593\u306E\u5272\u5408\
    \u3092\u8FD4\u3059\n    [[nodiscard]] double elapsed_ratio() const { return elapsed()\
    \ / static_cast<double>(TIME_LIMIT); }\n\n    // \u7D4C\u904E\u6642\u9593\u304C\
    \u5236\u9650\u6642\u9593\u306E nume/deno \u500D\u672A\u6E80\u304B\u3092\u8FD4\u3059\
    \n    // \u4F8B\u3048\u3070 frac<1, 2>() \u306F\u7D4C\u904E\u6642\u9593\u304C\u5236\
    \u9650\u6642\u9593\u306E 1/2 \u672A\u6E80\u304B\u3092\u8FD4\u3059\n    template\
    \ <unsigned nume, unsigned deno> [[nodiscard]] bool frac() const {\n        return\
    \ elapsed() * deno < TIME_LIMIT * nume;\n    }\n\n    // \u7D4C\u904E\u6642\u9593\
    \u304C\u5236\u9650\u6642\u9593\u672A\u6E80\u304B\u3092\u8FD4\u3059\n    [[nodiscard]]\
    \ bool good() const { return elapsed() < TIME_LIMIT; }\n};\n}  // namespace utility\n"
  dependsOn:
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/util/timer.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/util/timer.hpp
layout: document
redirect_from:
- /library/lib/util/timer.hpp
- /library/lib/util/timer.hpp.html
title: lib/util/timer.hpp
---
