#pragma once
#include "../core/core.hpp"
// 添え字に関して多機能なvector
// 添え字がループ可能で、mod this->size() で等しい要素にアクセスされる
// biasを変更することで添え字に下駄をはかせることが可能
template <class T> class Svector : public vector<T> {
public:
    using vector<T>::vector;
    vector<T>::reference operator[](int i) { return vector<T>::operator[](calc_index(i)); }
    vector<T>::const_reference operator[](int i) const { return vector<T>::operator[](calc_index(i)); }

    ll bias = 0;

private:
    size_t calc_index(int i) {
        ll ret = (i - bias) % this->size();
        if(ret < 0) ret += this->size();
        return (size_t)ret;
    }
};

template <class T> inline Svector<Svector<T>> SVector2(size_t i, size_t j, const T &init = T()) {
    return Svector<Svector<T>>(i, Svector<T>(j, init));
}
template <class T> inline Svector<Svector<Svector<T>>> SVector3(size_t i, size_t j, size_t k, const T &init = T()) {
    return Svector<Svector<Svector<T>>>(i, Svector<Svector<T>>(j, Svector<T>(k, init)));
}
template <class T>
inline Svector<Svector<Svector<Svector<T>>>> SVector4(size_t i, size_t j, size_t k, size_t l, const T &init = T()) {
    return Svector<Svector<Svector<Svector<T>>>>(
        i, Svector<Svector<Svector<T>>>(j, Svector<Svector<T>>(k, Svector<T>(l, init))));
}
