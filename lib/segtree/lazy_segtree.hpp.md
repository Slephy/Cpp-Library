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
    \ 3 \"lib/segtree/lazy_segtree.hpp\"\n\n// ACL\u306E\u5B9F\u88C5\u3092\u4E00\u90E8\
    \u6539\u5909\u3057\u305F\u3082\u306E\n// == \u5909\u66F4\u70B9 ==\n// internal::ceil_pow2\
    \ \u3092\u57CB\u3081\u8FBC\u3093\u3060\n// add\u95A2\u6570\u3092\u8FFD\u52A0\n\
    // size\u95A2\u6570\u3092\u8FFD\u52A0\n// \u30C7\u30FC\u30BF\u306E\u521D\u671F\
    \u5316\u7528\u9014\u3067 init \u3092\u6E21\u305B\u308B\u3088\u3046\u306B\u3057\
    \u305F\uFF08\u5F93\u6765\u306E\u5B9F\u88C5\u3067\u306F e \u3067\u521D\u671F\u5316\
    \u3055\u308C\u308B\uFF09\n\ntemplate <class S, S (*op)(S, S), S (*e)(), class\
    \ F, S (*mapping)(F, S), F (*composition)(F, F), F (*id)(),\n          S (*init)()\
    \ = e>\nstruct lazy_segtree {\npublic:\n    lazy_segtree() : lazy_segtree(0) {}\n\
    \    explicit lazy_segtree(int n) : lazy_segtree(vector<S>(n, init())) {}\n  \
    \  explicit lazy_segtree(const vector<S>& v) : _n(int(v.size())) {\n        log\
    \ = 0;\n        while((1U << log) < (unsigned int)(_n)) log++;\n        _size\
    \ = 1 << log;\n        d = vector<S>(2 * _size, e());\n        lz = vector<F>(_size,\
    \ id());\n        for(int i = 0; i < _n; i++) d[_size + i] = v[i];\n        for(int\
    \ i = _size - 1; i >= 1; i--) {\n            update(i);\n        }\n    }\n\n\
    \    size_t size() const { return _n; }\n\n    void set(int p, S x) {\n      \
    \  assert(0 <= p && p < _n);\n        p += _size;\n        for(int i = log; i\
    \ >= 1; i--) push(p >> i);\n        d[p] = x;\n        for(int i = 1; i <= log;\
    \ i++) update(p >> i);\n    }\n\n    void add(int p, S x) {\n        assert(0\
    \ <= p && p < _n);\n        p += _size;\n        for(int i = log; i >= 1; i--)\
    \ push(p >> i);\n        d[p] += x;\n        for(int i = 1; i <= log; i++) update(p\
    \ >> i);\n    }\n\n    S get(int p) {\n        assert(0 <= p && p < _n);\n   \
    \     p += _size;\n        for(int i = log; i >= 1; i--) push(p >> i);\n     \
    \   return d[p];\n    }\n\n    S prod(int l, int r) {\n        assert(0 <= l &&\
    \ l <= r && r <= _n);\n        if(l == r) return e();\n\n        l += _size;\n\
    \        r += _size;\n\n        for(int i = log; i >= 1; i--) {\n            if(((l\
    \ >> i) << i) != l) push(l >> i);\n            if(((r >> i) << i) != r) push((r\
    \ - 1) >> i);\n        }\n\n        S sml = e(), smr = e();\n        while(l <\
    \ r) {\n            if(l & 1) sml = op(sml, d[l++]);\n            if(r & 1) smr\
    \ = op(d[--r], smr);\n            l >>= 1;\n            r >>= 1;\n        }\n\n\
    \        return op(sml, smr);\n    }\n\n    S all_prod() { return d[1]; }\n\n\
    \    void apply(int p, F f) {\n        assert(0 <= p && p < _n);\n        p +=\
    \ _size;\n        for(int i = log; i >= 1; i--) push(p >> i);\n        d[p] =\
    \ mapping(f, d[p]);\n        for(int i = 1; i <= log; i++) update(p >> i);\n \
    \   }\n    void apply(int l, int r, F f) {\n        assert(0 <= l && l <= r &&\
    \ r <= _n);\n        if(l == r) return;\n\n        l += _size;\n        r += _size;\n\
    \n        for(int i = log; i >= 1; i--) {\n            if(((l >> i) << i) != l)\
    \ push(l >> i);\n            if(((r >> i) << i) != r) push((r - 1) >> i);\n  \
    \      }\n\n        {\n            int l2 = l, r2 = r;\n            while(l <\
    \ r) {\n                if(l & 1) all_apply(l++, f);\n                if(r & 1)\
    \ all_apply(--r, f);\n                l >>= 1;\n                r >>= 1;\n   \
    \         }\n            l = l2;\n            r = r2;\n        }\n\n        for(int\
    \ i = 1; i <= log; i++) {\n            if(((l >> i) << i) != l) update(l >> i);\n\
    \            if(((r >> i) << i) != r) update((r - 1) >> i);\n        }\n    }\n\
    \n    template <bool (*g)(S)> int max_right(int l) {\n        return max_right(l,\
    \ [](S x) { return g(x); });\n    }\n    template <class G> int max_right(int\
    \ l, G g) {\n        assert(0 <= l && l <= _n);\n        assert(g(e()));\n   \
    \     if(l == _n) return _n;\n        l += _size;\n        for(int i = log; i\
    \ >= 1; i--) push(l >> i);\n        S sm = e();\n        do {\n            while(l\
    \ % 2 == 0) l >>= 1;\n            if(!g(op(sm, d[l]))) {\n                while(l\
    \ < _size) {\n                    push(l);\n                    l = (2 * l);\n\
    \                    if(g(op(sm, d[l]))) {\n                        sm = op(sm,\
    \ d[l]);\n                        l++;\n                    }\n              \
    \  }\n                return l - _size;\n            }\n            sm = op(sm,\
    \ d[l]);\n            l++;\n        } while((l & -l) != l);\n        return _n;\n\
    \    }\n\n    template <bool (*g)(S)> int min_left(int r) {\n        return min_left(r,\
    \ [](S x) { return g(x); });\n    }\n    template <class G> int min_left(int r,\
    \ G g) {\n        assert(0 <= r && r <= _n);\n        assert(g(e()));\n      \
    \  if(r == 0) return 0;\n        r += _size;\n        for(int i = log; i >= 1;\
    \ i--) push((r - 1) >> i);\n        S sm = e();\n        do {\n            r--;\n\
    \            while(r > 1 && (r % 2)) r >>= 1;\n            if(!g(op(d[r], sm)))\
    \ {\n                while(r < _size) {\n                    push(r);\n      \
    \              r = (2 * r + 1);\n                    if(g(op(d[r], sm))) {\n \
    \                       sm = op(d[r], sm);\n                        r--;\n   \
    \                 }\n                }\n                return r + 1 - _size;\n\
    \            }\n            sm = op(d[r], sm);\n        } while((r & -r) != r);\n\
    \        return 0;\n    }\n\n    friend ostream& operator<<(ostream& os, lazy_segtree&\
    \ seg) {\n        os << \"[\";\n        for(int i = 0; i < seg._n; i++) {\n  \
    \          if(i != 0) os << \", \";\n            os << seg.get(i);\n        }\n\
    \        os << \"]\";\n        return os;\n    }\n\nprivate:\n    int _n, _size,\
    \ log;\n    vector<S> d;\n    vector<F> lz;\n\n    void update(int k) { d[k] =\
    \ op(d[2 * k], d[2 * k + 1]); }\n    void all_apply(int k, F f) {\n        d[k]\
    \ = mapping(f, d[k]);\n        if(k < _size) lz[k] = composition(f, lz[k]);\n\
    \    }\n    void push(int k) {\n        all_apply(2 * k, lz[k]);\n        all_apply(2\
    \ * k + 1, lz[k]);\n        lz[k] = id();\n    }\n};\n\n\ntemplate <class S, class\
    \ F> struct RangeAdd_RangeMin {\n    static S op(S a, S b) { return min(a, b);\
    \ }\n    static S e() { return numeric_limits<S>::max(); }\n    static S mapping(F\
    \ f, S x) { return f + x; }\n    static F composition(F f, F g) { return f + g;\
    \ }\n    static F id() { return 0; }\n    using Type = struct lazy_segtree<S,\
    \ op, e, F, mapping, composition, id>;\n};\n\ntemplate <class S, class F> struct\
    \ RangeAdd_RangeMax {\n    static S op(S a, S b) { return max(a, b); }\n    static\
    \ S e() { return numeric_limits<S>::min(); }\n    static S mapping(F f, S x) {\
    \ return f + x; }\n    static F composition(F f, F g) { return f + g; }\n    static\
    \ F id() { return 0; }\n    using Type = struct lazy_segtree<S, op, e, F, mapping,\
    \ composition, id>;\n};\n\ntemplate <class ValType, class F> struct RangeAdd_RangeSum\
    \ {\n    struct S {\n        ValType value;\n        int size;\n    };\n    static\
    \ S op(S a, S b) { return {a.value + b.value, a.size + b.size}; }\n    static\
    \ S e() { return {0, 0}; }\n    static S mapping(F f, S x) { return {x.value +\
    \ f * x.size, x.size}; }\n    static F composition(F f, F g) { return f + g; }\n\
    \    static F id() { return numeric_limits<F>::max(); }\n    static S init() {\
    \ return {0, 1}; }\n    using Type = struct lazy_segtree<S, op, e, F, mapping,\
    \ composition, id, init>;\n};\n\ntemplate <class S, class F> struct RangeSet_RangeMin\
    \ {\n    static S op(S a, S b) { return min(a, b); }\n    static S e() { return\
    \ numeric_limits<S>::max(); }\n    static S mapping(F f, S x) { return (f == id()\
    \ ? x : f); }\n    static F composition(F f, F g) { return (f == id() ? g : f);\
    \ }\n    static F id() { return numeric_limits<F>::max(); }\n    using Type =\
    \ struct lazy_segtree<S, op, e, F, mapping, composition, id>;\n};\n\ntemplate\
    \ <class S, class F> struct RangeSet_RangeMax {\n    static S op(S a, S b) { return\
    \ max(a, b); }\n    static S e() { return numeric_limits<S>::min(); }\n    static\
    \ S mapping(F f, S x) { return (f == id() ? x : f); }\n    static F composition(F\
    \ f, F g) { return (f == id() ? g : f); }\n    static F id() { return numeric_limits<F>::max();\
    \ }\n    using Type = struct lazy_segtree<S, op, e, F, mapping, composition, id>;\n\
    };\n\ntemplate <class ValType, class F> struct RangeSet_RangeSum {\n    struct\
    \ S {\n        ValType value;\n        int size;\n    };\n    static S op(S a,\
    \ S b) { return {a.value + b.value, a.size + b.size}; }\n    static S e() { return\
    \ {0, 0}; }\n    static S mapping(F f, S x) {\n        if(f != id()) x.value =\
    \ x.size * f;\n        return x;\n    }\n    static F composition(F f, F g) {\
    \ return (f == id() ? g : f); }\n    static F id() { return numeric_limits<F>::max();\
    \ }\n    static S init() { return {0, 1}; }\n    using Type = struct lazy_segtree<S,\
    \ op, e, F, mapping, composition, id, init>;\n};\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\n\n// ACL\u306E\u5B9F\u88C5\u3092\
    \u4E00\u90E8\u6539\u5909\u3057\u305F\u3082\u306E\n// == \u5909\u66F4\u70B9 ==\n\
    // internal::ceil_pow2 \u3092\u57CB\u3081\u8FBC\u3093\u3060\n// add\u95A2\u6570\
    \u3092\u8FFD\u52A0\n// size\u95A2\u6570\u3092\u8FFD\u52A0\n// \u30C7\u30FC\u30BF\
    \u306E\u521D\u671F\u5316\u7528\u9014\u3067 init \u3092\u6E21\u305B\u308B\u3088\
    \u3046\u306B\u3057\u305F\uFF08\u5F93\u6765\u306E\u5B9F\u88C5\u3067\u306F e \u3067\
    \u521D\u671F\u5316\u3055\u308C\u308B\uFF09\n\ntemplate <class S, S (*op)(S, S),\
    \ S (*e)(), class F, S (*mapping)(F, S), F (*composition)(F, F), F (*id)(),\n\
    \          S (*init)() = e>\nstruct lazy_segtree {\npublic:\n    lazy_segtree()\
    \ : lazy_segtree(0) {}\n    explicit lazy_segtree(int n) : lazy_segtree(vector<S>(n,\
    \ init())) {}\n    explicit lazy_segtree(const vector<S>& v) : _n(int(v.size()))\
    \ {\n        log = 0;\n        while((1U << log) < (unsigned int)(_n)) log++;\n\
    \        _size = 1 << log;\n        d = vector<S>(2 * _size, e());\n        lz\
    \ = vector<F>(_size, id());\n        for(int i = 0; i < _n; i++) d[_size + i]\
    \ = v[i];\n        for(int i = _size - 1; i >= 1; i--) {\n            update(i);\n\
    \        }\n    }\n\n    size_t size() const { return _n; }\n\n    void set(int\
    \ p, S x) {\n        assert(0 <= p && p < _n);\n        p += _size;\n        for(int\
    \ i = log; i >= 1; i--) push(p >> i);\n        d[p] = x;\n        for(int i =\
    \ 1; i <= log; i++) update(p >> i);\n    }\n\n    void add(int p, S x) {\n   \
    \     assert(0 <= p && p < _n);\n        p += _size;\n        for(int i = log;\
    \ i >= 1; i--) push(p >> i);\n        d[p] += x;\n        for(int i = 1; i <=\
    \ log; i++) update(p >> i);\n    }\n\n    S get(int p) {\n        assert(0 <=\
    \ p && p < _n);\n        p += _size;\n        for(int i = log; i >= 1; i--) push(p\
    \ >> i);\n        return d[p];\n    }\n\n    S prod(int l, int r) {\n        assert(0\
    \ <= l && l <= r && r <= _n);\n        if(l == r) return e();\n\n        l +=\
    \ _size;\n        r += _size;\n\n        for(int i = log; i >= 1; i--) {\n   \
    \         if(((l >> i) << i) != l) push(l >> i);\n            if(((r >> i) <<\
    \ i) != r) push((r - 1) >> i);\n        }\n\n        S sml = e(), smr = e();\n\
    \        while(l < r) {\n            if(l & 1) sml = op(sml, d[l++]);\n      \
    \      if(r & 1) smr = op(d[--r], smr);\n            l >>= 1;\n            r >>=\
    \ 1;\n        }\n\n        return op(sml, smr);\n    }\n\n    S all_prod() { return\
    \ d[1]; }\n\n    void apply(int p, F f) {\n        assert(0 <= p && p < _n);\n\
    \        p += _size;\n        for(int i = log; i >= 1; i--) push(p >> i);\n  \
    \      d[p] = mapping(f, d[p]);\n        for(int i = 1; i <= log; i++) update(p\
    \ >> i);\n    }\n    void apply(int l, int r, F f) {\n        assert(0 <= l &&\
    \ l <= r && r <= _n);\n        if(l == r) return;\n\n        l += _size;\n   \
    \     r += _size;\n\n        for(int i = log; i >= 1; i--) {\n            if(((l\
    \ >> i) << i) != l) push(l >> i);\n            if(((r >> i) << i) != r) push((r\
    \ - 1) >> i);\n        }\n\n        {\n            int l2 = l, r2 = r;\n     \
    \       while(l < r) {\n                if(l & 1) all_apply(l++, f);\n       \
    \         if(r & 1) all_apply(--r, f);\n                l >>= 1;\n           \
    \     r >>= 1;\n            }\n            l = l2;\n            r = r2;\n    \
    \    }\n\n        for(int i = 1; i <= log; i++) {\n            if(((l >> i) <<\
    \ i) != l) update(l >> i);\n            if(((r >> i) << i) != r) update((r - 1)\
    \ >> i);\n        }\n    }\n\n    template <bool (*g)(S)> int max_right(int l)\
    \ {\n        return max_right(l, [](S x) { return g(x); });\n    }\n    template\
    \ <class G> int max_right(int l, G g) {\n        assert(0 <= l && l <= _n);\n\
    \        assert(g(e()));\n        if(l == _n) return _n;\n        l += _size;\n\
    \        for(int i = log; i >= 1; i--) push(l >> i);\n        S sm = e();\n  \
    \      do {\n            while(l % 2 == 0) l >>= 1;\n            if(!g(op(sm,\
    \ d[l]))) {\n                while(l < _size) {\n                    push(l);\n\
    \                    l = (2 * l);\n                    if(g(op(sm, d[l]))) {\n\
    \                        sm = op(sm, d[l]);\n                        l++;\n  \
    \                  }\n                }\n                return l - _size;\n \
    \           }\n            sm = op(sm, d[l]);\n            l++;\n        } while((l\
    \ & -l) != l);\n        return _n;\n    }\n\n    template <bool (*g)(S)> int min_left(int\
    \ r) {\n        return min_left(r, [](S x) { return g(x); });\n    }\n    template\
    \ <class G> int min_left(int r, G g) {\n        assert(0 <= r && r <= _n);\n \
    \       assert(g(e()));\n        if(r == 0) return 0;\n        r += _size;\n \
    \       for(int i = log; i >= 1; i--) push((r - 1) >> i);\n        S sm = e();\n\
    \        do {\n            r--;\n            while(r > 1 && (r % 2)) r >>= 1;\n\
    \            if(!g(op(d[r], sm))) {\n                while(r < _size) {\n    \
    \                push(r);\n                    r = (2 * r + 1);\n            \
    \        if(g(op(d[r], sm))) {\n                        sm = op(d[r], sm);\n \
    \                       r--;\n                    }\n                }\n     \
    \           return r + 1 - _size;\n            }\n            sm = op(d[r], sm);\n\
    \        } while((r & -r) != r);\n        return 0;\n    }\n\n    friend ostream&\
    \ operator<<(ostream& os, lazy_segtree& seg) {\n        os << \"[\";\n       \
    \ for(int i = 0; i < seg._n; i++) {\n            if(i != 0) os << \", \";\n  \
    \          os << seg.get(i);\n        }\n        os << \"]\";\n        return\
    \ os;\n    }\n\nprivate:\n    int _n, _size, log;\n    vector<S> d;\n    vector<F>\
    \ lz;\n\n    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }\n    void\
    \ all_apply(int k, F f) {\n        d[k] = mapping(f, d[k]);\n        if(k < _size)\
    \ lz[k] = composition(f, lz[k]);\n    }\n    void push(int k) {\n        all_apply(2\
    \ * k, lz[k]);\n        all_apply(2 * k + 1, lz[k]);\n        lz[k] = id();\n\
    \    }\n};\n\n\ntemplate <class S, class F> struct RangeAdd_RangeMin {\n    static\
    \ S op(S a, S b) { return min(a, b); }\n    static S e() { return numeric_limits<S>::max();\
    \ }\n    static S mapping(F f, S x) { return f + x; }\n    static F composition(F\
    \ f, F g) { return f + g; }\n    static F id() { return 0; }\n    using Type =\
    \ struct lazy_segtree<S, op, e, F, mapping, composition, id>;\n};\n\ntemplate\
    \ <class S, class F> struct RangeAdd_RangeMax {\n    static S op(S a, S b) { return\
    \ max(a, b); }\n    static S e() { return numeric_limits<S>::min(); }\n    static\
    \ S mapping(F f, S x) { return f + x; }\n    static F composition(F f, F g) {\
    \ return f + g; }\n    static F id() { return 0; }\n    using Type = struct lazy_segtree<S,\
    \ op, e, F, mapping, composition, id>;\n};\n\ntemplate <class ValType, class F>\
    \ struct RangeAdd_RangeSum {\n    struct S {\n        ValType value;\n       \
    \ int size;\n    };\n    static S op(S a, S b) { return {a.value + b.value, a.size\
    \ + b.size}; }\n    static S e() { return {0, 0}; }\n    static S mapping(F f,\
    \ S x) { return {x.value + f * x.size, x.size}; }\n    static F composition(F\
    \ f, F g) { return f + g; }\n    static F id() { return numeric_limits<F>::max();\
    \ }\n    static S init() { return {0, 1}; }\n    using Type = struct lazy_segtree<S,\
    \ op, e, F, mapping, composition, id, init>;\n};\n\ntemplate <class S, class F>\
    \ struct RangeSet_RangeMin {\n    static S op(S a, S b) { return min(a, b); }\n\
    \    static S e() { return numeric_limits<S>::max(); }\n    static S mapping(F\
    \ f, S x) { return (f == id() ? x : f); }\n    static F composition(F f, F g)\
    \ { return (f == id() ? g : f); }\n    static F id() { return numeric_limits<F>::max();\
    \ }\n    using Type = struct lazy_segtree<S, op, e, F, mapping, composition, id>;\n\
    };\n\ntemplate <class S, class F> struct RangeSet_RangeMax {\n    static S op(S\
    \ a, S b) { return max(a, b); }\n    static S e() { return numeric_limits<S>::min();\
    \ }\n    static S mapping(F f, S x) { return (f == id() ? x : f); }\n    static\
    \ F composition(F f, F g) { return (f == id() ? g : f); }\n    static F id() {\
    \ return numeric_limits<F>::max(); }\n    using Type = struct lazy_segtree<S,\
    \ op, e, F, mapping, composition, id>;\n};\n\ntemplate <class ValType, class F>\
    \ struct RangeSet_RangeSum {\n    struct S {\n        ValType value;\n       \
    \ int size;\n    };\n    static S op(S a, S b) { return {a.value + b.value, a.size\
    \ + b.size}; }\n    static S e() { return {0, 0}; }\n    static S mapping(F f,\
    \ S x) {\n        if(f != id()) x.value = x.size * f;\n        return x;\n   \
    \ }\n    static F composition(F f, F g) { return (f == id() ? g : f); }\n    static\
    \ F id() { return numeric_limits<F>::max(); }\n    static S init() { return {0,\
    \ 1}; }\n    using Type = struct lazy_segtree<S, op, e, F, mapping, composition,\
    \ id, init>;\n};\n"
  dependsOn:
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/segtree/lazy_segtree.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/segtree/lazy_segtree.hpp
layout: document
redirect_from:
- /library/lib/segtree/lazy_segtree.hpp
- /library/lib/segtree/lazy_segtree.hpp.html
title: lib/segtree/lazy_segtree.hpp
---
