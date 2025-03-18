#pragma once
#include <vector>
// 添え字に下駄をはかせたvector
// 'a'や'A'などをゼロとして扱うことを想定している
template <class T, long long BIAS = 0> class Bvector : public vector<T> {
public:
    using vector<T>::vector;
    vector<T>::reference operator[](int i) { return vector<T>::operator[](i - BIAS); }
    vector<T>::const_reference operator[](int i) const { return vector<T>::operator[](i - BIAS); }
};

template <class T, long long BIAS = 0>
inline Bvector<Bvector<T, BIAS>, BIAS> Bvector2(size_t i, size_t j, const T &init = T()) {
    return Bvector<Bvector<T, BIAS>, BIAS>(i, Bvector<T, BIAS>(j, init));
}
template <class T, long long BIAS = 0>
inline Bvector<Bvector<Bvector<T, BIAS>, BIAS>, BIAS> Bvector3(size_t i, size_t j, size_t k, const T &init = T()) {
    return Bvector<Bvector<Bvector<T, BIAS>, BIAS>, BIAS>(
        i, Bvector<Bvector<T, BIAS>, BIAS>(j, Bvector<T, BIAS>(k, init)));
}
template <class T, long long BIAS = 0>
inline Bvector<Bvector<Bvector<Bvector<T, BIAS>, BIAS>, BIAS>, BIAS> Bvector4(size_t i, size_t j, size_t k, size_t l,
                                                                              const T &init = T()) {
    return Bvector<Bvector<Bvector<Bvector<T, BIAS>, BIAS>, BIAS>, BIAS>(
        i, Bvector<Bvector<Bvector<T, BIAS>, BIAS>, BIAS>(
               j, Bvector<Bvector<T, BIAS>, BIAS>(k, Bvector<T, BIAS>(l, init))));
}
