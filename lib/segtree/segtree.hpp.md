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
    \ 3 \"lib/segtree/segtree.hpp\"\n\n// ACL\u306E\u5B9F\u88C5\u3092\u4E00\u90E8\u6539\
    \u5909\u3057\u305F\u3082\u306E\n// == \u5909\u66F4\u70B9 ==\n// internal::ceil_pow2\
    \ \u3092\u57CB\u3081\u8FBC\u307F\n// add \u95A2\u6570 \u3092\u8FFD\u52A0\n// size\
    \ \u95A2\u6570 \u3092\u8FFD\u52A0\ntemplate <class S, S (*op)(S, S), S (*e)()>\
    \ struct segtree {\npublic:\n    segtree() : segtree(0) {}\n    explicit segtree(int\
    \ n) : segtree(vector<S>(n, e())) {}\n    explicit segtree(const vector<S>& v)\
    \ : _n(int(v.size())) {\n        log = 0;\n        while((1U << log) < (unsigned\
    \ int)(_n)) log++;\n        _size = 1 << log;\n        d = vector<S>(2 * _size,\
    \ e());\n        for(int i = 0; i < _n; i++) d[_size + i] = v[i];\n        for(int\
    \ i = _size - 1; i >= 1; i--) {\n            update(i);\n        }\n    }\n\n\
    \    size_t size() const { return _n; }\n\n    void set(int p, S x) {\n      \
    \  assert(0 <= p && p < _n);\n        p += _size;\n        d[p] = x;\n       \
    \ for(int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    void add(int p,\
    \ S x) {\n        assert(0 <= p && p < _n);\n        p += _size;\n        d[p]\
    \ += x;\n        for(int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    S\
    \ get(int p) const {\n        assert(0 <= p && p < _n);\n        return d[p +\
    \ _size];\n    }\n\n    S prod(int l, int r) const {\n        assert(0 <= l &&\
    \ l <= r && r <= _n);\n        S sml = e(), smr = e();\n        l += _size;\n\
    \        r += _size;\n\n        while(l < r) {\n            if(l & 1) sml = op(sml,\
    \ d[l++]);\n            if(r & 1) smr = op(d[--r], smr);\n            l >>= 1;\n\
    \            r >>= 1;\n        }\n        return op(sml, smr);\n    }\n\n    S\
    \ all_prod() const { return d[1]; }\n\n    template <bool (*f)(S)> int max_right(int\
    \ l) const {\n        return max_right(l, [](S x) { return f(x); });\n    }\n\
    \    template <class F> int max_right(int l, F f) const {\n        assert(0 <=\
    \ l && l <= _n);\n        assert(f(e()));\n        if(l == _n) return _n;\n  \
    \      l += _size;\n        S sm = e();\n        do {\n            while(l % 2\
    \ == 0) l >>= 1;\n            if(!f(op(sm, d[l]))) {\n                while(l\
    \ < _size) {\n                    l = (2 * l);\n                    if(f(op(sm,\
    \ d[l]))) {\n                        sm = op(sm, d[l]);\n                    \
    \    l++;\n                    }\n                }\n                return l\
    \ - _size;\n            }\n            sm = op(sm, d[l]);\n            l++;\n\
    \        } while((l & -l) != l);\n        return _n;\n    }\n\n    template <bool\
    \ (*f)(S)> int min_left(int r) const {\n        return min_left(r, [](S x) { return\
    \ f(x); });\n    }\n    template <class F> int min_left(int r, F f) const {\n\
    \        assert(0 <= r && r <= _n);\n        assert(f(e()));\n        if(r ==\
    \ 0) return 0;\n        r += _size;\n        S sm = e();\n        do {\n     \
    \       r--;\n            while(r > 1 && (r % 2)) r >>= 1;\n            if(!f(op(d[r],\
    \ sm))) {\n                while(r < _size) {\n                    r = (2 * r\
    \ + 1);\n                    if(f(op(d[r], sm))) {\n                        sm\
    \ = op(d[r], sm);\n                        r--;\n                    }\n     \
    \           }\n                return r + 1 - _size;\n            }\n        \
    \    sm = op(d[r], sm);\n        } while((r & -r) != r);\n        return 0;\n\
    \    }\n\n    friend ostream& operator<<(ostream& os, const segtree& seg) {\n\
    \        os << \"[\";\n        for(int i = 0; i < seg._n; i++) {\n           \
    \ if(i != 0) os << \", \";\n            os << seg.get(i);\n        }\n       \
    \ os << \"]\";\n        return os;\n    }\n\n\nprivate:\n    int _n, _size, log;\n\
    \    vector<S> d;\n\n    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]);\
    \ }\n};\n\n\ntemplate <class S> struct RangeSum {\n    static S op(S l, S r) {\
    \ return l + r; }\n    static S e() { return 0; }\n    using Type = struct segtree<S,\
    \ op, e>;\n};\ntemplate <class S> struct RangeMin {\n    static S op(S l, S r)\
    \ { return min(l, r); }\n    static S e() { return numeric_limits<S>::max(); }\n\
    \    using Type = struct segtree<S, op, e>;\n};\ntemplate <class S> struct RangeMax\
    \ {\n    static S op(S l, S r) { return max(l, r); }\n    static S e() { return\
    \ numeric_limits<S>::min(); }\n    using Type = struct segtree<S, op, e>;\n};\n\
    // ex) RangeMin<int>::Type seg(10);\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\n\n// ACL\u306E\u5B9F\u88C5\u3092\
    \u4E00\u90E8\u6539\u5909\u3057\u305F\u3082\u306E\n// == \u5909\u66F4\u70B9 ==\n\
    // internal::ceil_pow2 \u3092\u57CB\u3081\u8FBC\u307F\n// add \u95A2\u6570 \u3092\
    \u8FFD\u52A0\n// size \u95A2\u6570 \u3092\u8FFD\u52A0\ntemplate <class S, S (*op)(S,\
    \ S), S (*e)()> struct segtree {\npublic:\n    segtree() : segtree(0) {}\n   \
    \ explicit segtree(int n) : segtree(vector<S>(n, e())) {}\n    explicit segtree(const\
    \ vector<S>& v) : _n(int(v.size())) {\n        log = 0;\n        while((1U <<\
    \ log) < (unsigned int)(_n)) log++;\n        _size = 1 << log;\n        d = vector<S>(2\
    \ * _size, e());\n        for(int i = 0; i < _n; i++) d[_size + i] = v[i];\n \
    \       for(int i = _size - 1; i >= 1; i--) {\n            update(i);\n      \
    \  }\n    }\n\n    size_t size() const { return _n; }\n\n    void set(int p, S\
    \ x) {\n        assert(0 <= p && p < _n);\n        p += _size;\n        d[p] =\
    \ x;\n        for(int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    void\
    \ add(int p, S x) {\n        assert(0 <= p && p < _n);\n        p += _size;\n\
    \        d[p] += x;\n        for(int i = 1; i <= log; i++) update(p >> i);\n \
    \   }\n\n    S get(int p) const {\n        assert(0 <= p && p < _n);\n       \
    \ return d[p + _size];\n    }\n\n    S prod(int l, int r) const {\n        assert(0\
    \ <= l && l <= r && r <= _n);\n        S sml = e(), smr = e();\n        l += _size;\n\
    \        r += _size;\n\n        while(l < r) {\n            if(l & 1) sml = op(sml,\
    \ d[l++]);\n            if(r & 1) smr = op(d[--r], smr);\n            l >>= 1;\n\
    \            r >>= 1;\n        }\n        return op(sml, smr);\n    }\n\n    S\
    \ all_prod() const { return d[1]; }\n\n    template <bool (*f)(S)> int max_right(int\
    \ l) const {\n        return max_right(l, [](S x) { return f(x); });\n    }\n\
    \    template <class F> int max_right(int l, F f) const {\n        assert(0 <=\
    \ l && l <= _n);\n        assert(f(e()));\n        if(l == _n) return _n;\n  \
    \      l += _size;\n        S sm = e();\n        do {\n            while(l % 2\
    \ == 0) l >>= 1;\n            if(!f(op(sm, d[l]))) {\n                while(l\
    \ < _size) {\n                    l = (2 * l);\n                    if(f(op(sm,\
    \ d[l]))) {\n                        sm = op(sm, d[l]);\n                    \
    \    l++;\n                    }\n                }\n                return l\
    \ - _size;\n            }\n            sm = op(sm, d[l]);\n            l++;\n\
    \        } while((l & -l) != l);\n        return _n;\n    }\n\n    template <bool\
    \ (*f)(S)> int min_left(int r) const {\n        return min_left(r, [](S x) { return\
    \ f(x); });\n    }\n    template <class F> int min_left(int r, F f) const {\n\
    \        assert(0 <= r && r <= _n);\n        assert(f(e()));\n        if(r ==\
    \ 0) return 0;\n        r += _size;\n        S sm = e();\n        do {\n     \
    \       r--;\n            while(r > 1 && (r % 2)) r >>= 1;\n            if(!f(op(d[r],\
    \ sm))) {\n                while(r < _size) {\n                    r = (2 * r\
    \ + 1);\n                    if(f(op(d[r], sm))) {\n                        sm\
    \ = op(d[r], sm);\n                        r--;\n                    }\n     \
    \           }\n                return r + 1 - _size;\n            }\n        \
    \    sm = op(d[r], sm);\n        } while((r & -r) != r);\n        return 0;\n\
    \    }\n\n    friend ostream& operator<<(ostream& os, const segtree& seg) {\n\
    \        os << \"[\";\n        for(int i = 0; i < seg._n; i++) {\n           \
    \ if(i != 0) os << \", \";\n            os << seg.get(i);\n        }\n       \
    \ os << \"]\";\n        return os;\n    }\n\n\nprivate:\n    int _n, _size, log;\n\
    \    vector<S> d;\n\n    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]);\
    \ }\n};\n\n\ntemplate <class S> struct RangeSum {\n    static S op(S l, S r) {\
    \ return l + r; }\n    static S e() { return 0; }\n    using Type = struct segtree<S,\
    \ op, e>;\n};\ntemplate <class S> struct RangeMin {\n    static S op(S l, S r)\
    \ { return min(l, r); }\n    static S e() { return numeric_limits<S>::max(); }\n\
    \    using Type = struct segtree<S, op, e>;\n};\ntemplate <class S> struct RangeMax\
    \ {\n    static S op(S l, S r) { return max(l, r); }\n    static S e() { return\
    \ numeric_limits<S>::min(); }\n    using Type = struct segtree<S, op, e>;\n};\n\
    // ex) RangeMin<int>::Type seg(10);\n"
  dependsOn:
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/segtree/segtree.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/segtree/segtree.hpp
layout: document
redirect_from:
- /library/lib/segtree/segtree.hpp
- /library/lib/segtree/segtree.hpp.html
title: lib/segtree/segtree.hpp
---
