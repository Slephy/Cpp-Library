#pragma once
#include "../core/core.hpp"

// string ELM_SEP = " ", VEC_SEP = "\n";
const string PT_SEP = " ";
// prototype declaration
template <class T> istream &operator>>(istream &i, vector<T> &A);
template <class T> ostream &operator<<(ostream &o, const vector<T> &A);
template <class T> ostream &operator<<(ostream &o, const vector<vector<T>> &A);
template <class T> ostream &operator<<(ostream &o, const deque<T> &A);
template <class T, class U> istream &operator>>(istream &i, pair<T, U> &A);
template <class T, class U> ostream &operator<<(ostream &o, const pair<T, U> &A);
template <class T, class U> istream &operator>>(istream &i, tuple<T, U> &A);
template <class T, class U> ostream &operator<<(ostream &o, const tuple<T, U> &A);
template <class T, class U, class V> istream &operator>>(istream &i, tuple<T, U, V> &A);
template <class T, class U, class V> ostream &operator<<(ostream &o, const tuple<T, U, V> &A);
template <class T, class U, class V, class W> istream &operator>>(istream &i, tuple<T, U, V, W> &A);
template <class T, class U, class V, class W> ostream &operator<<(ostream &o, const tuple<T, U, V, W> &A);
template <class T> ostream &operator<<(ostream &o, const set<T> &A);
template <class T, class U> ostream &operator<<(ostream &o, const map<T, U> &A);

// implementation
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
template <class T> ostream &operator<<(ostream &o, const deque<T> &A) {
    int i = A.size();
    for(auto &I : A) o << I << (--i ? ELM_SEP : "");
    return o;
}
template <class T, class U> istream &operator>>(istream &i, pair<T, U> &A) {
    i >> A.first >> A.second;
    return i;
}
template <class T, class U> ostream &operator<<(ostream &o, const pair<T, U> &A) {
    o << A.first << PT_SEP << A.second;
    return o;
}
template <class T, class U> istream &operator>>(istream &i, tuple<T, U> &A) {
    i >> get<0>(A) >> get<1>(A);
    return i;
}
template <class T, class U> ostream &operator<<(ostream &o, const tuple<T, U> &A) {
    o << get<0>(A) << PT_SEP << get<1>(A);
    return o;
}
template <class T, class U, class V> istream &operator>>(istream &i, tuple<T, U, V> &A) {
    i >> get<0>(A) >> get<1>(A) >> get<2>(A);
    return i;
}
template <class T, class U, class V> ostream &operator<<(ostream &o, const tuple<T, U, V> &A) {
    o << get<0>(A) << PT_SEP << get<1>(A) << PT_SEP << get<2>(A);
    return o;
}
template <class T, class U, class V, class W> istream &operator>>(istream &i, tuple<T, U, V, W> &A) {
    i >> get<0>(A) >> get<1>(A) >> get<2>(A) >> get<3>(A);
    return i;
}
template <class T, class U, class V, class W> ostream &operator<<(ostream &o, const tuple<T, U, V, W> &A) {
    o << get<0>(A) << PT_SEP << get<1>(A) << PT_SEP << get<2>(A) << PT_SEP << get<3>(A);
    return o;
}
template <class T> ostream &operator<<(ostream &o, const set<T> &A) {
    int i = A.size();
    for(const auto &I : A) o << I << (--i ? ELM_SEP : "");
    return o;
}
template <class T, class U> ostream &operator<<(ostream &o, const map<T, U> &A) {
    int i = A.size();
    for(const auto &[k, v] : A) o << "{" << k << ": " << v << "}" << (--i ? ELM_SEP : "");
    return o;
}
