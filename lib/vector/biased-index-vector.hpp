#pragma once
#include "../core/core.hpp"
// 添え字に下駄をはかせたvector
// 'a'や'A'などをゼロとして扱うことを想定している
template <class T, long long BIAS = 0> class Bvector : public vector<T> {
public:
    using vector<T>::vector;
    vector<T>::reference operator[](int i) { return vector<T>::operator[](i - BIAS); }
    vector<T>::const_reference operator[](int i) const { return vector<T>::operator[](i - BIAS); }
};

template <class T, long long BIAS = 0> using Bvector2_t = Bvector<Bvector<T, BIAS>, BIAS>;
template <class T, long long BIAS = 0> using Bvector3_t = Bvector<Bvector<Bvector<T, BIAS>, BIAS>, BIAS>;
template <class T, long long BIAS = 0> using Bvector4_t = Bvector<Bvector<Bvector<Bvector<T, BIAS>, BIAS>, BIAS>, BIAS>;

template <class T, long long BIAS = 0> inline Bvector2_t<T, BIAS> Bvector2(size_t i, size_t j, const T &init = T()) {
    return Bvector2_t<T, BIAS>(i, Bvector<T, BIAS>(j, init));
}
template <class T, long long BIAS = 0>
inline Bvector3_t<T, BIAS> Bvector3(size_t i, size_t j, size_t k, const T &init = T()) {
    return Bvector3_t<T, BIAS>(i, Bvector<Bvector<T, BIAS>, BIAS>(j, Bvector<T, BIAS>(k, init)));
}
template <class T, long long BIAS = 0>
inline Bvector4_t<T, BIAS> Bvector4(size_t i, size_t j, size_t k, size_t l, const T &init = T()) {
    return Bvector4_t<T, BIAS>(i, Bvector3_t<T, BIAS>(j, Bvector2_t<T, BIAS>(k, Bvector<T, BIAS>(l, init))));
}
