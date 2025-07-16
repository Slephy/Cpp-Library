#pragma once
#include "../core/core.hpp"

template <class T> struct Matrix {
public:
    // コンストラクタ
    Matrix(size_t h, size_t w, T init = T()) : mat(h, vector<T>(w, init)) {}
    Matrix(const vector<vector<T>> &mat) : mat(mat) {}
    Matrix(vector<vector<T>> &&mat) : mat(std::move(mat)) {}

    // ゲッター
    size_t height() const { return mat.size(); }
    size_t width() const { return ((height() > 0) ? mat[0].size() : 0); }

    // 添え字演算子のオーバーロード
    inline const vector<T> &operator[](size_t index) const {
        assert(0 <= index && index < height());
        return mat[index];
    }
    inline vector<T> &operator[](size_t index) {
        assert(0 <= index && index < height());
        return mat[index];
    }

    // イテレータ
    auto begin() { return mat.begin(); }
    auto end() { return mat.end(); }

    // 入出力ストリーム
    friend istream &operator>>(istream &i, Matrix<T> &mat) {
        for(auto &I : mat)
            for(auto &J : I) {
                i >> J;
            }
        return i;
    }
    friend ostream &operator<<(ostream &o, const Matrix &A) {
        o << A.mat;
        return o;
    }

    // 静的メンバ関数
    static Matrix<T> identity(size_t size) {
        Matrix<T> res(size, size, 0);
        for(int i = 0; i < size; i++) {
            res[i][i] = 1;
        }
        return res;
    }
    static Matrix<T> identity(const Matrix<T> &mat_like) {
        assert(mat_like.height() == mat_like.width());
        size_t size = mat_like.height();
        Matrix<T> res(size, size, 0);
        for(int i = 0; i < size; i++) {
            res[i][i] = 1;
        }
        return res;
    }
    static Matrix<T> zero(size_t size) { return Matrix<T>(size, size, 0); }
    static Matrix<T> zero(size_t height, size_t width) { return Matrix<T>(height, width, 0); }
    static Matrix<T> zero(const Matrix<T> &mat_like) { return Matrix<T>::zero(mat_like.height(), mat_like.width()); }

    // 算術演算子のオーバーロード
    Matrix<T> operator+() { return *this; }
    Matrix<T> operator-() {
        Matrix<T> res(height(), width());
        for(int i = 0; i < height(); i++) {
            for(int j = 0; j < width(); j++) {
                res[i][j] = -mat[i][j];
            }
        }
        return res;
    }
    Matrix<T> &operator+=(const Matrix<T> &other) {
        assert(height() == other.height() && width() == other.width());
        for(int i = 0; i < height(); i++) {
            for(int j = 0; j < width(); j++) {
                (*this)[i][j] += other[i][j];
            }
        }
        return *this;
    }
    Matrix<T> &operator-=(const Matrix<T> &other) {
        assert(height() == other.height() && width() == other.width());
        for(int i = 0; i < height(); i++) {
            for(int j = 0; j < width(); j++) {
                (*this)[i][j] -= other[i][j];
            }
        }
        return *this;
    }
    Matrix<T> &operator*=(const Matrix<T> &other) {
        assert(width() == other.height());
        vector<vector<T>> res(height(), vector<T>(other.width(), 0));
        for(int i = 0; i < height(); i++) {
            for(int j = 0; j < other.width(); j++) {
                for(int k = 0; k < width(); k++) {
                    res[i][j] += (*this)[i][k] * other[k][j];
                }
            }
        }
        swap(mat, res);
        return *this;
    }
    Matrix<T> &operator^=(unsigned long long n) {
        assert(height() == width());
        Matrix<T> res = Matrix<T>::identity(height());
        while(n > 0) {
            if(n & 1) res *= *this;
            *this *= *this;
            n >>= 1;
        }
        swap(res, *this);
        return *this;
    }
    Matrix<T> operator+(const Matrix<T> &other) const { return Matrix<T>(*this) += other; }
    Matrix<T> operator-(const Matrix<T> &other) const { return Matrix<T>(*this) -= other; }
    Matrix<T> operator*(const Matrix<T> &other) const { return Matrix<T>(*this) *= other; }
    Matrix<T> operator^(unsigned long long n) const { return Matrix<T>(*this) ^= n; }

    // スカラとの演算
    friend Matrix<T> &operator+=(Matrix<T> &mat, const T &val) {
        for(int i = 0; i < mat.height(); i++)
            for(int j = 0; j < mat.width(); j++) mat[i][j] += val;
        return mat;
    }
    friend Matrix<T> &operator-=(Matrix<T> &mat, const T &val) {
        for(int i = 0; i < mat.height(); i++)
            for(int j = 0; j < mat.width(); j++) mat[i][j] -= val;
        return mat;
    }
    friend Matrix<T> &operator*=(Matrix<T> &mat, const T &val) {
        for(int i = 0; i < mat.height(); i++)
            for(int j = 0; j < mat.width(); j++) mat[i][j] *= val;
        return mat;
    }
    friend Matrix<T> operator+(const Matrix<T> &mat, const T &val) {
        Matrix<T> res(mat.height(), mat.width());
        for(int i = 0; i < mat.height(); i++)
            for(int j = 0; j < mat.width(); j++) res[i][j] = mat[i][j] + val;
        return res;
    }
    friend Matrix<T> operator+(const T &val, const Matrix<T> &mat) { return mat + val; }
    friend Matrix<T> operator-(const Matrix<T> &mat, const T &val) {
        Matrix<T> res(mat.height(), mat.width());
        for(int i = 0; i < mat.height(); i++)
            for(int j = 0; j < mat.width(); j++) res[i][j] = mat[i][j] - val;
        return res;
    }
    friend Matrix<T> operator-(const T &val, const Matrix<T> &mat) {
        Matrix<T> res(mat.height(), mat.width());
        for(int i = 0; i < mat.height(); i++)
            for(int j = 0; j < mat.width(); j++) res[i][j] = val - mat[i][j];
        return res;
    }
    friend Matrix<T> operator*(const Matrix<T> &mat, const T &val) {
        Matrix<T> res(mat.height(), mat.width());
        for(int i = 0; i < mat.height(); i++)
            for(int j = 0; j < mat.width(); j++) res[i][j] = mat[i][j] * val;
        return res;
    }
    friend Matrix<T> operator*(const T &val, const Matrix<T> &mat) { return mat * val; }

    T det() {
        assert(height() == width());
        Matrix<T> mat = *this;
        T res = 1;
        for(int i = 0; i < height(); i++) {
            int pivot = -1;
            for(int j = i; j < height(); j++) {
                if(mat[j][i] != 0) {
                    pivot = j;
                    break;
                }
            }
            if(pivot == -1) return 0;
            if(i != pivot) {
                res = -res;
                swap(mat[i], mat[pivot]);
            }
            res *= mat[i][i];
            T inv = T(1) / mat[i][i];
            for(int j = i + 1; j < height(); j++) {
                T r = mat[j][i] * inv;
                for(int k = i; k < width(); k++) {
                    mat[j][k] -= mat[i][k] * r;
                }
            }
        }
        return res;
    }

    // メンバ変数
private:
    vector<vector<T>> mat;
};
