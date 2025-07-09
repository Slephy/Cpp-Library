#pragma once
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int INF = (int)1e9 + 1001010;
const ll llINF = (long long)4e18 + 22000020;
const string endn = "\n";
template <class T> inline auto vector2(size_t i, size_t j, const T &init = T()) {
    return vector(i, vector<T>(j, init));
}
const string ELM_SEP = " ", VEC_SEP = endn;
template <class T> istream &operator>>(istream &i, vector<T> &A) {
    for(auto &I : A) i >> I;
    return i;
}
template <class T> ostream &operator<<(ostream &o, const vector<T> &A) {
    int i = A.size();
    for(const auto &I : A) o << I << (--i ? ELM_SEP : "");
    return o;
}
template <class T> ostream &operator<<(ostream &o, const vector<vector<T>> &A) {
    int i = A.size();
    for(const auto &I : A) o << I << (--i ? VEC_SEP : "");
    return o;
}
template <class T> vector<T> &operator++(vector<T> &A, int) {
    for(auto &I : A) I++;
    return A;
}
template <class T> vector<T> &operator--(vector<T> &A, int) {
    for(auto &I : A) I--;
    return A;
}
template <class T, class U> bool chmax(T &a, const U &b) { return ((a < b) ? (a = b, true) : false); }
template <class T, class U> bool chmin(T &a, const U &b) { return ((a > b) ? (a = b, true) : false); }
ll floor(ll a, ll b) {
    if(b < 0) a = -a, b = -b;
    return (a >= 0) ? a / b : (a + 1) / b - 1;
}
ll ceil(ll a, ll b) {
    if(b < 0) a = -a, b = -b;
    return (a > 0) ? (a - 1) / b + 1 : a / b;
}
ll check_bit(unsigned long long val, unsigned long long digit) { return (val >> digit) & 1; }
#ifdef DEBUG
#include <cpp-dump/cpp-dump.hpp>
#define dump(...) cpp_dump(__VA_ARGS__)
namespace cp = cpp_dump;
struct InitCppDump {
    InitCppDump() {
        if(!isatty(fileno(stderr))) CPP_DUMP_SET_OPTION(es_style, cpp_dump::types::es_style_t::no_es);
        CPP_DUMP_SET_OPTION(log_label_func, cp::log_label::line());
        CPP_DUMP_SET_OPTION(max_iteration_count, 30);
    }
} init_cpp_dump;
#else
#define dump(...)
#endif
// ==================== ここまでテンプレ ====================
