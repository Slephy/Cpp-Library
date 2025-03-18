#pragma once
#include <cassert>
#include <iostream>

#include "../util/i128-io.hpp"
using namespace std;

struct modint107 {
    using mint = modint107;
    using i64 = long long;
    using i128 = __int128_t;
    using u64 = unsigned long long;
    using u128 = __uint128_t;

    const static i128 m = ((i128)1 << 107) - 1;
    static constexpr u128 mask54 = (u128(1) << 54) - 1;
    static constexpr u128 mask53 = (u128(1) << 53) - 1;

    static constexpr i128 mod() { return m; }
    static mint raw(i128 v) {
        mint x;
        x._v = v;
        return x;
    }
    modint107() : _v(0) {}
    modint107(i128 v) {
        if(v >= 0) _v = calc_mod(v);
        else if(v >= -m) _v = v + m;
        else {
            i128 x = v % m;
            if(x < 0) x += m;
            _v = x;
        }
    }
    // modint107(bool v) { _v = ((unsigned int)(v) % umod()); }
    i128 val() const { return _v; }
    mint& operator++() {
        _v++;
        if(_v == m) _v = 0;
        return *this;
    }
    mint& operator--() {
        if(_v == 0) _v = m;
        _v--;
        return *this;
    }
    mint operator++(int) {
        mint result = *this;
        ++*this;
        return result;
    }
    mint operator--(int) {
        mint result = *this;
        --*this;
        return result;
    }
    mint& operator+=(const mint& rhs) {
        _v += rhs._v;
        if(_v >= m) _v -= m;
        return *this;
    }
    mint& operator-=(const mint& rhs) {
        _v -= rhs._v;
        if(_v >= umod()) _v += umod();
        return *this;
    }
    mint& operator*=(const mint& rhs) {
        u128 a = _v, b = rhs._v;
        u128 au = a >> 54;
        u128 ad = a & mask54;
        u128 bu = b >> 54;
        u128 bd = b & mask54;
        u128 mid = ad * bu + au * bd;
        u128 midu = mid >> 53;
        u128 midd = mid & mask53;
        _v = calc_mod(au * bu * 2 + midu + midd * (1ULL << 54) + ad * bd);
        return *this;
    }
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }
    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }
    mint pow(i128 n) const {
        assert(0 <= n);
        mint x = *this, r = (i128)1;
        while(n) {
            if(n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    mint inv() const {
        assert(_v);
        return pow(m - 2);
    }
    friend mint operator+(const mint& lhs, const mint& rhs) { return mint(lhs) += rhs; }
    friend mint operator-(const mint& lhs, const mint& rhs) { return mint(lhs) -= rhs; }
    friend mint operator*(const mint& lhs, const mint& rhs) { return mint(lhs) *= rhs; }
    friend mint operator/(const mint& lhs, const mint& rhs) { return mint(lhs) /= rhs; }
    friend bool operator==(const mint& lhs, const mint& rhs) { return lhs._v == rhs._v; }
    friend bool operator!=(const mint& lhs, const mint& rhs) { return lhs._v != rhs._v; }

    friend istream& operator>>(istream& i, mint& a) {
        i128 v;
        i >> v;
        a = v;
        return i;
    }
    friend ostream& operator<<(ostream& os, const mint& a) { return os << a.val(); }

private:
    u128 calc_mod(u128 x) {
        u128 res = (x >> 107) + (x & m);
        if(res >= m) res -= m;
        return res;
    }
    u128 _v;
    static constexpr u128 umod() { return m; }
};
