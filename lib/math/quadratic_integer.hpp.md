---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: lib/core/core.hpp
    title: lib/core/core.hpp
  - icon: ':warning:'
    path: lib/math/isqrt.hpp
    title: lib/math/isqrt.hpp
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
    \ 3 \"lib/math/isqrt.hpp\"\n\noptional<ll> isqrt(ll val) {\n    if(val < 0) return\
    \ nullopt;\n    ll sq = sqrt(val);\n    if(sq * sq == val) return sq;\n    else\
    \ return nullopt;\n}\n#line 4 \"lib/math/quadratic_integer.hpp\"\n\n// return\
    \ integer solutions of the quadratic equation ax^2 + bx + c = 0\nvector<ll> solve_quadratic_integer(ll\
    \ a, ll b, ll c) {\n    assert(a != 0 || b != 0 || c != 0); // infinite solutions\n\
    \    if(a == 0) {\n        if(b == 0) return {};\n        else return (c % b ==\
    \ 0) ? vector<ll>{-c / b} : vector<ll>{};\n    }\n\n    vector<ll> ret;\n    ll\
    \ d = b * b - 4 * a * c;\n    if(d < 0) return ret;\n    else if(d == 0) {\n \
    \       ret.push_back(-b / (2 * a));\n        return ret;\n    }\n    else {\n\
    \        auto sq = isqrt(d);\n        if(!sq) return {};\n        auto emplace_if_integer\
    \ = [&](ll sq) -> void {\n            ll nume = -b + sq;\n            ll deno\
    \ = 2 * a;\n            if(nume % deno == 0) ret.emplace_back(nume / deno);\n\
    \        };\n        emplace_if_integer(*sq);\n        emplace_if_integer(-*sq);\n\
    \        return ret;\n    }\n}\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\n#include \"../math/isqrt.hpp\"\
    \n\n// return integer solutions of the quadratic equation ax^2 + bx + c = 0\n\
    vector<ll> solve_quadratic_integer(ll a, ll b, ll c) {\n    assert(a != 0 || b\
    \ != 0 || c != 0); // infinite solutions\n    if(a == 0) {\n        if(b == 0)\
    \ return {};\n        else return (c % b == 0) ? vector<ll>{-c / b} : vector<ll>{};\n\
    \    }\n\n    vector<ll> ret;\n    ll d = b * b - 4 * a * c;\n    if(d < 0) return\
    \ ret;\n    else if(d == 0) {\n        ret.push_back(-b / (2 * a));\n        return\
    \ ret;\n    }\n    else {\n        auto sq = isqrt(d);\n        if(!sq) return\
    \ {};\n        auto emplace_if_integer = [&](ll sq) -> void {\n            ll\
    \ nume = -b + sq;\n            ll deno = 2 * a;\n            if(nume % deno ==\
    \ 0) ret.emplace_back(nume / deno);\n        };\n        emplace_if_integer(*sq);\n\
    \        emplace_if_integer(-*sq);\n        return ret;\n    }\n}\n"
  dependsOn:
  - lib/core/core.hpp
  - lib/math/isqrt.hpp
  isVerificationFile: false
  path: lib/math/quadratic_integer.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/quadratic_integer.hpp
layout: document
redirect_from:
- /library/lib/math/quadratic_integer.hpp
- /library/lib/math/quadratic_integer.hpp.html
title: lib/math/quadratic_integer.hpp
---
