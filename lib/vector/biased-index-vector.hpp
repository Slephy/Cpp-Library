#include <vector>
// 添え字に下駄をはかせたvector
// 'a'や'A'などをゼロとして扱うことを想定している
template <class T> class Bvector : public vector<T> {
public:
    using vector<T>::vector;
    vector<T>::reference operator[](int i) { return vector<T>::operator[](i - this->bias); }
    vector<T>::const_reference operator[](int i) const { return vector<T>::operator[](i - this->bias); }
    static long long bias;
    static void set_bias(long long b) { bias = b; }
};

template <class T> inline Bvector<Bvector<T>> Bvector2(size_t i, size_t j, const T &init = T()) {
    return Bvector<Bvector<T>>(i, Bvector<T>(j, init));
}
template <class T> inline Bvector<Bvector<Bvector<T>>> Bvector3(size_t i, size_t j, size_t k, const T &init = T()) {
    return Bvector<Bvector<Bvector<T>>>(i, Bvector<Bvector<T>>(j, Bvector<T>(k, init)));
}
template <class T>
inline Bvector<Bvector<Bvector<Bvector<T>>>> Bvector4(size_t i, size_t j, size_t k, size_t l, const T &init = T()) {
    return Bvector<Bvector<Bvector<Bvector<T>>>>(
        i, Bvector<Bvector<Bvector<T>>>(j, Bvector<Bvector<T>>(k, Bvector<T>(l, init))));
}
