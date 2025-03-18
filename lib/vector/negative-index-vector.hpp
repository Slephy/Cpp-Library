#pragma once
#include <vector>
// 負の添え字に対応したvector
// 負の添え字の仕様はPythonのリストと同様で、その他は通常のvectorと同じように使える
template <class T> class Nvector : public vector<T> {
#ifdef DEBUG
    int min_index = numeric_limits<int>::max();
    int max_index = numeric_limits<int>::min();
    void check_index(int i) {
        min_index = min(min_index, i);
        max_index = max(max_index, i);
        if(max_index - min_index >= (int)this->size()){
            cerr << "ERROR: Out of range reference may be detected" << endl;
            cerr << "min_index: " << min_index << ", max_index: " << max_index << ", size: " << this->size() << endl;
            cerr << "You accessed the index " << i << endl;
            exit(1);
        }
    }
#else
#define check_index(i)
#endif

public:
    using vector<T>::vector;
    vector<T>::reference operator[](int i) {
        check_index(i);
        if(i < 0) return vector<T>::operator[]((int)this->size() + i);
        else return vector<T>::operator[](i);
    }
    vector<T>::const_reference operator[](int i) const {
        check_index(i);
        if(i < 0) return vector<T>::operator[]((int)this->size() + i);
        else return vector<T>::operator[](i);
    }
};

template <class T> inline Nvector<Nvector<T>> Nvector2(size_t i, size_t j, const T &init = T()) {
    return Nvector<Nvector<T>>(i, Nvector<T>(j, init));
}
template <class T> inline Nvector<Nvector<Nvector<T>>> Nvector3(size_t i, size_t j, size_t k, const T &init = T()) {
    return Nvector<Nvector<Nvector<T>>>(i, Nvector<Nvector<T>>(j, Nvector<T>(k, init)));
}
template <class T>
inline Nvector<Nvector<Nvector<Nvector<T>>>> Nvector4(size_t i, size_t j, size_t k, size_t l, const T &init = T()) {
    return Nvector<Nvector<Nvector<Nvector<T>>>>(
        i, Nvector<Nvector<Nvector<T>>>(j, Nvector<Nvector<T>>(k, Nvector<T>(l, init))));
}
