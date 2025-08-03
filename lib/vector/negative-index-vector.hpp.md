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
    \ 3 \"lib/vector/negative-index-vector.hpp\"\n// \u8CA0\u306E\u6DFB\u3048\u5B57\
    \u306B\u5BFE\u5FDC\u3057\u305Fvector\n// \u8CA0\u306E\u6DFB\u3048\u5B57\u306E\u4ED5\
    \u69D8\u306FPython\u306E\u30EA\u30B9\u30C8\u3068\u540C\u69D8\u3067\u3001\u305D\
    \u306E\u4ED6\u306F\u901A\u5E38\u306Evector\u3068\u540C\u3058\u3088\u3046\u306B\
    \u4F7F\u3048\u308B\ntemplate <class T> class Nvector : public vector<T> {\n#ifdef\
    \ DEBUG\n    int min_index = numeric_limits<int>::max();\n    int max_index =\
    \ numeric_limits<int>::min();\n    void check_index(int i) {\n        min_index\
    \ = min(min_index, i);\n        max_index = max(max_index, i);\n        if(max_index\
    \ - min_index >= (int)this->size()){\n            cerr << \"ERROR: Out of range\
    \ reference may be detected\" << endl;\n            cerr << \"min_index: \" <<\
    \ min_index << \", max_index: \" << max_index << \", size: \" << this->size()\
    \ << endl;\n            cerr << \"You accessed the index \" << i << endl;\n  \
    \          exit(1);\n        }\n    }\n#else\n#define check_index(i)\n#endif\n\
    \npublic:\n    using vector<T>::vector;\n    vector<T>::reference operator[](int\
    \ i) {\n        check_index(i);\n        if(i < 0) return vector<T>::operator[]((int)this->size()\
    \ + i);\n        else return vector<T>::operator[](i);\n    }\n    vector<T>::const_reference\
    \ operator[](int i) const {\n        check_index(i);\n        if(i < 0) return\
    \ vector<T>::operator[]((int)this->size() + i);\n        else return vector<T>::operator[](i);\n\
    \    }\n};\n\ntemplate <class T> inline Nvector<Nvector<T>> Nvector2(size_t i,\
    \ size_t j, const T &init = T()) {\n    return Nvector<Nvector<T>>(i, Nvector<T>(j,\
    \ init));\n}\ntemplate <class T> inline Nvector<Nvector<Nvector<T>>> Nvector3(size_t\
    \ i, size_t j, size_t k, const T &init = T()) {\n    return Nvector<Nvector<Nvector<T>>>(i,\
    \ Nvector<Nvector<T>>(j, Nvector<T>(k, init)));\n}\ntemplate <class T>\ninline\
    \ Nvector<Nvector<Nvector<Nvector<T>>>> Nvector4(size_t i, size_t j, size_t k,\
    \ size_t l, const T &init = T()) {\n    return Nvector<Nvector<Nvector<Nvector<T>>>>(\n\
    \        i, Nvector<Nvector<Nvector<T>>>(j, Nvector<Nvector<T>>(k, Nvector<T>(l,\
    \ init))));\n}\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\n// \u8CA0\u306E\u6DFB\u3048\u5B57\
    \u306B\u5BFE\u5FDC\u3057\u305Fvector\n// \u8CA0\u306E\u6DFB\u3048\u5B57\u306E\u4ED5\
    \u69D8\u306FPython\u306E\u30EA\u30B9\u30C8\u3068\u540C\u69D8\u3067\u3001\u305D\
    \u306E\u4ED6\u306F\u901A\u5E38\u306Evector\u3068\u540C\u3058\u3088\u3046\u306B\
    \u4F7F\u3048\u308B\ntemplate <class T> class Nvector : public vector<T> {\n#ifdef\
    \ DEBUG\n    int min_index = numeric_limits<int>::max();\n    int max_index =\
    \ numeric_limits<int>::min();\n    void check_index(int i) {\n        min_index\
    \ = min(min_index, i);\n        max_index = max(max_index, i);\n        if(max_index\
    \ - min_index >= (int)this->size()){\n            cerr << \"ERROR: Out of range\
    \ reference may be detected\" << endl;\n            cerr << \"min_index: \" <<\
    \ min_index << \", max_index: \" << max_index << \", size: \" << this->size()\
    \ << endl;\n            cerr << \"You accessed the index \" << i << endl;\n  \
    \          exit(1);\n        }\n    }\n#else\n#define check_index(i)\n#endif\n\
    \npublic:\n    using vector<T>::vector;\n    vector<T>::reference operator[](int\
    \ i) {\n        check_index(i);\n        if(i < 0) return vector<T>::operator[]((int)this->size()\
    \ + i);\n        else return vector<T>::operator[](i);\n    }\n    vector<T>::const_reference\
    \ operator[](int i) const {\n        check_index(i);\n        if(i < 0) return\
    \ vector<T>::operator[]((int)this->size() + i);\n        else return vector<T>::operator[](i);\n\
    \    }\n};\n\ntemplate <class T> inline Nvector<Nvector<T>> Nvector2(size_t i,\
    \ size_t j, const T &init = T()) {\n    return Nvector<Nvector<T>>(i, Nvector<T>(j,\
    \ init));\n}\ntemplate <class T> inline Nvector<Nvector<Nvector<T>>> Nvector3(size_t\
    \ i, size_t j, size_t k, const T &init = T()) {\n    return Nvector<Nvector<Nvector<T>>>(i,\
    \ Nvector<Nvector<T>>(j, Nvector<T>(k, init)));\n}\ntemplate <class T>\ninline\
    \ Nvector<Nvector<Nvector<Nvector<T>>>> Nvector4(size_t i, size_t j, size_t k,\
    \ size_t l, const T &init = T()) {\n    return Nvector<Nvector<Nvector<Nvector<T>>>>(\n\
    \        i, Nvector<Nvector<Nvector<T>>>(j, Nvector<Nvector<T>>(k, Nvector<T>(l,\
    \ init))));\n}\n"
  dependsOn:
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/vector/negative-index-vector.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/vector/negative-index-vector.hpp
layout: document
redirect_from:
- /library/lib/vector/negative-index-vector.hpp
- /library/lib/vector/negative-index-vector.hpp.html
title: lib/vector/negative-index-vector.hpp
---
