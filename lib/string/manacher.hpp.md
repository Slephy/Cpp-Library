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
    \ 3 \"lib/string/manacher.hpp\"\n\nenum class ManacherType {\n    even,\n    odd,\n\
    };\n\nenum class ManacherResultType {\n    radius,    // \u56DE\u6587\u306E\u534A\
    \u5F84\n    diameter,  // \u56DE\u6587\u306E\u76F4\u5F84\uFF08\u9577\u3055\uFF09\
    \n};\n\n// O(s.size())\ntemplate <class Iterator>\nvector<int> Manacher(Iterator\
    \ begin, Iterator end, ManacherType mtype, ManacherResultType rtype) {\n    //\
    \ even\u306E\u3068\u304D\u306FDAMMY\u3092\u631F\u3093\u3067\u5947\u6570\u306B\u3059\
    \u308B\n    string withDammy = \"\";\n    const char DAMMY = '`';\n    if(mtype\
    \ == ManacherType::even) {\n        for(auto i = begin; i < end; i++) {\n    \
    \        if(!withDammy.empty()) withDammy += DAMMY;\n            withDammy +=\
    \ *i;\n        }\n        begin = withDammy.begin();\n        end = withDammy.end();\n\
    \    }\n\n    // \u30E1\u30A4\u30F3\u51E6\u7406\n    vector<int> res;\n    {\n\
    \        int size = end - begin;\n        res.resize(size);\n        int i = 0,\
    \ j = 1;\n        while(i < res.size()) {\n            while(i - j >= 0 && i +\
    \ j < size && begin[i - j] == begin[i + j]) j++;\n\n            res[i] = j;\n\
    \            int k = 1;\n            while(i - k >= 0 && i + k < size && i - res[i]\
    \ < (i - k) - res[i - k]) {\n                res[i + k] = res[i - k];\n      \
    \          k++;\n            }\n            i += k, j -= k;\n        }\n    }\n\
    \n    // even \u306E\u3068\u304D\u306F DAMMY \u306E\u4F4D\u7F6E\u3060\u3051\u7D50\
    \u679C\u3092\u62BD\u51FA\u3059\u308B\n    if(mtype == ManacherType::even) {\n\
    \        vector<int> tmp;\n        tmp.reserve(res.size() / 2 + 1);\n        for(int\
    \ i = 1; i < res.size(); i += 2) tmp.emplace_back(res[i]);\n        res = move(tmp);\n\
    \    }\n\n    // \u7D50\u679C\u3092\u5909\u63DB\u3059\u308B\n    if(rtype == ManacherResultType::radius)\
    \ {\n        if(mtype == ManacherType::odd)\n            ;\n        if(mtype ==\
    \ ManacherType::even)\n            for(auto &v : res) v = v / 2;\n    }\n    if(rtype\
    \ == ManacherResultType::diameter) {\n        if(mtype == ManacherType::odd)\n\
    \            for(auto &v : res) v = 2 * v - 1;\n        if(mtype == ManacherType::even)\n\
    \            for(auto &v : res) v = v - (v & 1);\n    }\n    return res;\n}\n\n\
    vector<int> Manacher(const string &s, ManacherType mtype, ManacherResultType rtype)\
    \ {\n    return Manacher(s.begin(), s.end(), mtype, rtype);\n}\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\n\nenum class ManacherType {\n\
    \    even,\n    odd,\n};\n\nenum class ManacherResultType {\n    radius,    //\
    \ \u56DE\u6587\u306E\u534A\u5F84\n    diameter,  // \u56DE\u6587\u306E\u76F4\u5F84\
    \uFF08\u9577\u3055\uFF09\n};\n\n// O(s.size())\ntemplate <class Iterator>\nvector<int>\
    \ Manacher(Iterator begin, Iterator end, ManacherType mtype, ManacherResultType\
    \ rtype) {\n    // even\u306E\u3068\u304D\u306FDAMMY\u3092\u631F\u3093\u3067\u5947\
    \u6570\u306B\u3059\u308B\n    string withDammy = \"\";\n    const char DAMMY =\
    \ '`';\n    if(mtype == ManacherType::even) {\n        for(auto i = begin; i <\
    \ end; i++) {\n            if(!withDammy.empty()) withDammy += DAMMY;\n      \
    \      withDammy += *i;\n        }\n        begin = withDammy.begin();\n     \
    \   end = withDammy.end();\n    }\n\n    // \u30E1\u30A4\u30F3\u51E6\u7406\n \
    \   vector<int> res;\n    {\n        int size = end - begin;\n        res.resize(size);\n\
    \        int i = 0, j = 1;\n        while(i < res.size()) {\n            while(i\
    \ - j >= 0 && i + j < size && begin[i - j] == begin[i + j]) j++;\n\n         \
    \   res[i] = j;\n            int k = 1;\n            while(i - k >= 0 && i + k\
    \ < size && i - res[i] < (i - k) - res[i - k]) {\n                res[i + k] =\
    \ res[i - k];\n                k++;\n            }\n            i += k, j -= k;\n\
    \        }\n    }\n\n    // even \u306E\u3068\u304D\u306F DAMMY \u306E\u4F4D\u7F6E\
    \u3060\u3051\u7D50\u679C\u3092\u62BD\u51FA\u3059\u308B\n    if(mtype == ManacherType::even)\
    \ {\n        vector<int> tmp;\n        tmp.reserve(res.size() / 2 + 1);\n    \
    \    for(int i = 1; i < res.size(); i += 2) tmp.emplace_back(res[i]);\n      \
    \  res = move(tmp);\n    }\n\n    // \u7D50\u679C\u3092\u5909\u63DB\u3059\u308B\
    \n    if(rtype == ManacherResultType::radius) {\n        if(mtype == ManacherType::odd)\n\
    \            ;\n        if(mtype == ManacherType::even)\n            for(auto\
    \ &v : res) v = v / 2;\n    }\n    if(rtype == ManacherResultType::diameter) {\n\
    \        if(mtype == ManacherType::odd)\n            for(auto &v : res) v = 2\
    \ * v - 1;\n        if(mtype == ManacherType::even)\n            for(auto &v :\
    \ res) v = v - (v & 1);\n    }\n    return res;\n}\n\nvector<int> Manacher(const\
    \ string &s, ManacherType mtype, ManacherResultType rtype) {\n    return Manacher(s.begin(),\
    \ s.end(), mtype, rtype);\n}\n"
  dependsOn:
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/string/manacher.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/string/manacher.hpp
layout: document
redirect_from:
- /library/lib/string/manacher.hpp
- /library/lib/string/manacher.hpp.html
title: lib/string/manacher.hpp
---
