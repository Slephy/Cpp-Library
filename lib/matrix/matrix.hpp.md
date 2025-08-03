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
    \ 3 \"lib/matrix/matrix.hpp\"\n\ntemplate <class T> struct Matrix {\npublic:\n\
    \    // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n    Matrix(size_t h, size_t\
    \ w, T init = T()) : mat(h, vector<T>(w, init)) {}\n    Matrix(const vector<vector<T>>\
    \ &mat) : mat(mat) {}\n    Matrix(vector<vector<T>> &&mat) : mat(std::move(mat))\
    \ {}\n\n    // \u30B2\u30C3\u30BF\u30FC\n    size_t height() const { return mat.size();\
    \ }\n    size_t width() const { return ((height() > 0) ? mat[0].size() : 0); }\n\
    \n    // \u6DFB\u3048\u5B57\u6F14\u7B97\u5B50\u306E\u30AA\u30FC\u30D0\u30FC\u30ED\
    \u30FC\u30C9\n    inline const vector<T> &operator[](size_t index) const {\n \
    \       assert(0 <= index && index < height());\n        return mat[index];\n\
    \    }\n    inline vector<T> &operator[](size_t index) {\n        assert(0 <=\
    \ index && index < height());\n        return mat[index];\n    }\n\n    // \u30A4\
    \u30C6\u30EC\u30FC\u30BF\n    auto begin() { return mat.begin(); }\n    auto end()\
    \ { return mat.end(); }\n\n    // \u5165\u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\
    \n    friend istream &operator>>(istream &i, Matrix<T> &mat) {\n        for(auto\
    \ &I : mat)\n            for(auto &J : I) {\n                i >> J;\n       \
    \     }\n        return i;\n    }\n    friend ostream &operator<<(ostream &o,\
    \ const Matrix &A) {\n        o << A.mat;\n        return o;\n    }\n\n    //\
    \ \u9759\u7684\u30E1\u30F3\u30D0\u95A2\u6570\n    static Matrix<T> identity(size_t\
    \ size) {\n        Matrix<T> res(size, size, 0);\n        for(int i = 0; i < size;\
    \ i++) {\n            res[i][i] = 1;\n        }\n        return res;\n    }\n\
    \    static Matrix<T> identity(const Matrix<T> &mat_like) {\n        assert(mat_like.height()\
    \ == mat_like.width());\n        size_t size = mat_like.height();\n        Matrix<T>\
    \ res(size, size, 0);\n        for(int i = 0; i < size; i++) {\n            res[i][i]\
    \ = 1;\n        }\n        return res;\n    }\n    static Matrix<T> zero(size_t\
    \ size) { return Matrix<T>(size, size, 0); }\n    static Matrix<T> zero(size_t\
    \ height, size_t width) { return Matrix<T>(height, width, 0); }\n    static Matrix<T>\
    \ zero(const Matrix<T> &mat_like) { return Matrix<T>::zero(mat_like.height(),\
    \ mat_like.width()); }\n\n    // \u7B97\u8853\u6F14\u7B97\u5B50\u306E\u30AA\u30FC\
    \u30D0\u30FC\u30ED\u30FC\u30C9\n    Matrix<T> operator+() { return *this; }\n\
    \    Matrix<T> operator-() {\n        Matrix<T> res(height(), width());\n    \
    \    for(int i = 0; i < height(); i++) {\n            for(int j = 0; j < width();\
    \ j++) {\n                res[i][j] = -mat[i][j];\n            }\n        }\n\
    \        return res;\n    }\n    Matrix<T> &operator+=(const Matrix<T> &other)\
    \ {\n        assert(height() == other.height() && width() == other.width());\n\
    \        for(int i = 0; i < height(); i++) {\n            for(int j = 0; j < width();\
    \ j++) {\n                (*this)[i][j] += other[i][j];\n            }\n     \
    \   }\n        return *this;\n    }\n    Matrix<T> &operator-=(const Matrix<T>\
    \ &other) {\n        assert(height() == other.height() && width() == other.width());\n\
    \        for(int i = 0; i < height(); i++) {\n            for(int j = 0; j < width();\
    \ j++) {\n                (*this)[i][j] -= other[i][j];\n            }\n     \
    \   }\n        return *this;\n    }\n    Matrix<T> &operator*=(const Matrix<T>\
    \ &other) {\n        assert(width() == other.height());\n        vector<vector<T>>\
    \ res(height(), vector<T>(other.width(), 0));\n        for(int i = 0; i < height();\
    \ i++) {\n            for(int j = 0; j < other.width(); j++) {\n             \
    \   for(int k = 0; k < width(); k++) {\n                    res[i][j] += (*this)[i][k]\
    \ * other[k][j];\n                }\n            }\n        }\n        swap(mat,\
    \ res);\n        return *this;\n    }\n    Matrix<T> &operator^=(unsigned long\
    \ long n) {\n        assert(height() == width());\n        Matrix<T> res = Matrix<T>::identity(height());\n\
    \        while(n > 0) {\n            if(n & 1) res *= *this;\n            *this\
    \ *= *this;\n            n >>= 1;\n        }\n        swap(res, *this);\n    \
    \    return *this;\n    }\n    Matrix<T> operator+(const Matrix<T> &other) const\
    \ { return Matrix<T>(*this) += other; }\n    Matrix<T> operator-(const Matrix<T>\
    \ &other) const { return Matrix<T>(*this) -= other; }\n    Matrix<T> operator*(const\
    \ Matrix<T> &other) const { return Matrix<T>(*this) *= other; }\n    Matrix<T>\
    \ operator^(unsigned long long n) const { return Matrix<T>(*this) ^= n; }\n\n\
    \    // \u30B9\u30AB\u30E9\u3068\u306E\u6F14\u7B97\n    friend Matrix<T> &operator+=(Matrix<T>\
    \ &mat, const T &val) {\n        for(int i = 0; i < mat.height(); i++)\n     \
    \       for(int j = 0; j < mat.width(); j++) mat[i][j] += val;\n        return\
    \ mat;\n    }\n    friend Matrix<T> &operator-=(Matrix<T> &mat, const T &val)\
    \ {\n        for(int i = 0; i < mat.height(); i++)\n            for(int j = 0;\
    \ j < mat.width(); j++) mat[i][j] -= val;\n        return mat;\n    }\n    friend\
    \ Matrix<T> &operator*=(Matrix<T> &mat, const T &val) {\n        for(int i = 0;\
    \ i < mat.height(); i++)\n            for(int j = 0; j < mat.width(); j++) mat[i][j]\
    \ *= val;\n        return mat;\n    }\n    friend Matrix<T> operator+(const Matrix<T>\
    \ &mat, const T &val) {\n        Matrix<T> res(mat.height(), mat.width());\n \
    \       for(int i = 0; i < mat.height(); i++)\n            for(int j = 0; j <\
    \ mat.width(); j++) res[i][j] = mat[i][j] + val;\n        return res;\n    }\n\
    \    friend Matrix<T> operator+(const T &val, const Matrix<T> &mat) { return mat\
    \ + val; }\n    friend Matrix<T> operator-(const Matrix<T> &mat, const T &val)\
    \ {\n        Matrix<T> res(mat.height(), mat.width());\n        for(int i = 0;\
    \ i < mat.height(); i++)\n            for(int j = 0; j < mat.width(); j++) res[i][j]\
    \ = mat[i][j] - val;\n        return res;\n    }\n    friend Matrix<T> operator-(const\
    \ T &val, const Matrix<T> &mat) {\n        Matrix<T> res(mat.height(), mat.width());\n\
    \        for(int i = 0; i < mat.height(); i++)\n            for(int j = 0; j <\
    \ mat.width(); j++) res[i][j] = val - mat[i][j];\n        return res;\n    }\n\
    \    friend Matrix<T> operator*(const Matrix<T> &mat, const T &val) {\n      \
    \  Matrix<T> res(mat.height(), mat.width());\n        for(int i = 0; i < mat.height();\
    \ i++)\n            for(int j = 0; j < mat.width(); j++) res[i][j] = mat[i][j]\
    \ * val;\n        return res;\n    }\n    friend Matrix<T> operator*(const T &val,\
    \ const Matrix<T> &mat) { return mat * val; }\n\n    T det() {\n        assert(height()\
    \ == width());\n        Matrix<T> mat = *this;\n        T res = 1;\n        for(int\
    \ i = 0; i < height(); i++) {\n            int pivot = -1;\n            for(int\
    \ j = i; j < height(); j++) {\n                if(mat[j][i] != 0) {\n        \
    \            pivot = j;\n                    break;\n                }\n     \
    \       }\n            if(pivot == -1) return 0;\n            if(i != pivot) {\n\
    \                res = -res;\n                swap(mat[i], mat[pivot]);\n    \
    \        }\n            res *= mat[i][i];\n            T inv = T(1) / mat[i][i];\n\
    \            for(int j = i + 1; j < height(); j++) {\n                T r = mat[j][i]\
    \ * inv;\n                for(int k = i; k < width(); k++) {\n               \
    \     mat[j][k] -= mat[i][k] * r;\n                }\n            }\n        }\n\
    \        return res;\n    }\n\n    // \u30E1\u30F3\u30D0\u5909\u6570\nprivate:\n\
    \    vector<vector<T>> mat;\n};\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\n\ntemplate <class T> struct\
    \ Matrix {\npublic:\n    // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n    Matrix(size_t\
    \ h, size_t w, T init = T()) : mat(h, vector<T>(w, init)) {}\n    Matrix(const\
    \ vector<vector<T>> &mat) : mat(mat) {}\n    Matrix(vector<vector<T>> &&mat) :\
    \ mat(std::move(mat)) {}\n\n    // \u30B2\u30C3\u30BF\u30FC\n    size_t height()\
    \ const { return mat.size(); }\n    size_t width() const { return ((height() >\
    \ 0) ? mat[0].size() : 0); }\n\n    // \u6DFB\u3048\u5B57\u6F14\u7B97\u5B50\u306E\
    \u30AA\u30FC\u30D0\u30FC\u30ED\u30FC\u30C9\n    inline const vector<T> &operator[](size_t\
    \ index) const {\n        assert(0 <= index && index < height());\n        return\
    \ mat[index];\n    }\n    inline vector<T> &operator[](size_t index) {\n     \
    \   assert(0 <= index && index < height());\n        return mat[index];\n    }\n\
    \n    // \u30A4\u30C6\u30EC\u30FC\u30BF\n    auto begin() { return mat.begin();\
    \ }\n    auto end() { return mat.end(); }\n\n    // \u5165\u51FA\u529B\u30B9\u30C8\
    \u30EA\u30FC\u30E0\n    friend istream &operator>>(istream &i, Matrix<T> &mat)\
    \ {\n        for(auto &I : mat)\n            for(auto &J : I) {\n            \
    \    i >> J;\n            }\n        return i;\n    }\n    friend ostream &operator<<(ostream\
    \ &o, const Matrix &A) {\n        o << A.mat;\n        return o;\n    }\n\n  \
    \  // \u9759\u7684\u30E1\u30F3\u30D0\u95A2\u6570\n    static Matrix<T> identity(size_t\
    \ size) {\n        Matrix<T> res(size, size, 0);\n        for(int i = 0; i < size;\
    \ i++) {\n            res[i][i] = 1;\n        }\n        return res;\n    }\n\
    \    static Matrix<T> identity(const Matrix<T> &mat_like) {\n        assert(mat_like.height()\
    \ == mat_like.width());\n        size_t size = mat_like.height();\n        Matrix<T>\
    \ res(size, size, 0);\n        for(int i = 0; i < size; i++) {\n            res[i][i]\
    \ = 1;\n        }\n        return res;\n    }\n    static Matrix<T> zero(size_t\
    \ size) { return Matrix<T>(size, size, 0); }\n    static Matrix<T> zero(size_t\
    \ height, size_t width) { return Matrix<T>(height, width, 0); }\n    static Matrix<T>\
    \ zero(const Matrix<T> &mat_like) { return Matrix<T>::zero(mat_like.height(),\
    \ mat_like.width()); }\n\n    // \u7B97\u8853\u6F14\u7B97\u5B50\u306E\u30AA\u30FC\
    \u30D0\u30FC\u30ED\u30FC\u30C9\n    Matrix<T> operator+() { return *this; }\n\
    \    Matrix<T> operator-() {\n        Matrix<T> res(height(), width());\n    \
    \    for(int i = 0; i < height(); i++) {\n            for(int j = 0; j < width();\
    \ j++) {\n                res[i][j] = -mat[i][j];\n            }\n        }\n\
    \        return res;\n    }\n    Matrix<T> &operator+=(const Matrix<T> &other)\
    \ {\n        assert(height() == other.height() && width() == other.width());\n\
    \        for(int i = 0; i < height(); i++) {\n            for(int j = 0; j < width();\
    \ j++) {\n                (*this)[i][j] += other[i][j];\n            }\n     \
    \   }\n        return *this;\n    }\n    Matrix<T> &operator-=(const Matrix<T>\
    \ &other) {\n        assert(height() == other.height() && width() == other.width());\n\
    \        for(int i = 0; i < height(); i++) {\n            for(int j = 0; j < width();\
    \ j++) {\n                (*this)[i][j] -= other[i][j];\n            }\n     \
    \   }\n        return *this;\n    }\n    Matrix<T> &operator*=(const Matrix<T>\
    \ &other) {\n        assert(width() == other.height());\n        vector<vector<T>>\
    \ res(height(), vector<T>(other.width(), 0));\n        for(int i = 0; i < height();\
    \ i++) {\n            for(int j = 0; j < other.width(); j++) {\n             \
    \   for(int k = 0; k < width(); k++) {\n                    res[i][j] += (*this)[i][k]\
    \ * other[k][j];\n                }\n            }\n        }\n        swap(mat,\
    \ res);\n        return *this;\n    }\n    Matrix<T> &operator^=(unsigned long\
    \ long n) {\n        assert(height() == width());\n        Matrix<T> res = Matrix<T>::identity(height());\n\
    \        while(n > 0) {\n            if(n & 1) res *= *this;\n            *this\
    \ *= *this;\n            n >>= 1;\n        }\n        swap(res, *this);\n    \
    \    return *this;\n    }\n    Matrix<T> operator+(const Matrix<T> &other) const\
    \ { return Matrix<T>(*this) += other; }\n    Matrix<T> operator-(const Matrix<T>\
    \ &other) const { return Matrix<T>(*this) -= other; }\n    Matrix<T> operator*(const\
    \ Matrix<T> &other) const { return Matrix<T>(*this) *= other; }\n    Matrix<T>\
    \ operator^(unsigned long long n) const { return Matrix<T>(*this) ^= n; }\n\n\
    \    // \u30B9\u30AB\u30E9\u3068\u306E\u6F14\u7B97\n    friend Matrix<T> &operator+=(Matrix<T>\
    \ &mat, const T &val) {\n        for(int i = 0; i < mat.height(); i++)\n     \
    \       for(int j = 0; j < mat.width(); j++) mat[i][j] += val;\n        return\
    \ mat;\n    }\n    friend Matrix<T> &operator-=(Matrix<T> &mat, const T &val)\
    \ {\n        for(int i = 0; i < mat.height(); i++)\n            for(int j = 0;\
    \ j < mat.width(); j++) mat[i][j] -= val;\n        return mat;\n    }\n    friend\
    \ Matrix<T> &operator*=(Matrix<T> &mat, const T &val) {\n        for(int i = 0;\
    \ i < mat.height(); i++)\n            for(int j = 0; j < mat.width(); j++) mat[i][j]\
    \ *= val;\n        return mat;\n    }\n    friend Matrix<T> operator+(const Matrix<T>\
    \ &mat, const T &val) {\n        Matrix<T> res(mat.height(), mat.width());\n \
    \       for(int i = 0; i < mat.height(); i++)\n            for(int j = 0; j <\
    \ mat.width(); j++) res[i][j] = mat[i][j] + val;\n        return res;\n    }\n\
    \    friend Matrix<T> operator+(const T &val, const Matrix<T> &mat) { return mat\
    \ + val; }\n    friend Matrix<T> operator-(const Matrix<T> &mat, const T &val)\
    \ {\n        Matrix<T> res(mat.height(), mat.width());\n        for(int i = 0;\
    \ i < mat.height(); i++)\n            for(int j = 0; j < mat.width(); j++) res[i][j]\
    \ = mat[i][j] - val;\n        return res;\n    }\n    friend Matrix<T> operator-(const\
    \ T &val, const Matrix<T> &mat) {\n        Matrix<T> res(mat.height(), mat.width());\n\
    \        for(int i = 0; i < mat.height(); i++)\n            for(int j = 0; j <\
    \ mat.width(); j++) res[i][j] = val - mat[i][j];\n        return res;\n    }\n\
    \    friend Matrix<T> operator*(const Matrix<T> &mat, const T &val) {\n      \
    \  Matrix<T> res(mat.height(), mat.width());\n        for(int i = 0; i < mat.height();\
    \ i++)\n            for(int j = 0; j < mat.width(); j++) res[i][j] = mat[i][j]\
    \ * val;\n        return res;\n    }\n    friend Matrix<T> operator*(const T &val,\
    \ const Matrix<T> &mat) { return mat * val; }\n\n    T det() {\n        assert(height()\
    \ == width());\n        Matrix<T> mat = *this;\n        T res = 1;\n        for(int\
    \ i = 0; i < height(); i++) {\n            int pivot = -1;\n            for(int\
    \ j = i; j < height(); j++) {\n                if(mat[j][i] != 0) {\n        \
    \            pivot = j;\n                    break;\n                }\n     \
    \       }\n            if(pivot == -1) return 0;\n            if(i != pivot) {\n\
    \                res = -res;\n                swap(mat[i], mat[pivot]);\n    \
    \        }\n            res *= mat[i][i];\n            T inv = T(1) / mat[i][i];\n\
    \            for(int j = i + 1; j < height(); j++) {\n                T r = mat[j][i]\
    \ * inv;\n                for(int k = i; k < width(); k++) {\n               \
    \     mat[j][k] -= mat[i][k] * r;\n                }\n            }\n        }\n\
    \        return res;\n    }\n\n    // \u30E1\u30F3\u30D0\u5909\u6570\nprivate:\n\
    \    vector<vector<T>> mat;\n};\n"
  dependsOn:
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/matrix/matrix.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/matrix/matrix.hpp
layout: document
redirect_from:
- /library/lib/matrix/matrix.hpp
- /library/lib/matrix/matrix.hpp.html
title: lib/matrix/matrix.hpp
---
