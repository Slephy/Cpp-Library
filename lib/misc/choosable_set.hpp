#pragma once
#include "../core/core.hpp"
#include "../random/random.hpp"
// 集合を扱うクラス
// 集合内からランダムに要素を抽出する操作を O(1) でできるのが強み（setだと時間がかかる）
template <class T> class ChoosableSet {
private:
    vector<T> vec;
    map<T, size_t> idx;  // idx[val] := (vec内でのvalのインデックス)


public:
    // vector<int> で初期化. 重複要素は一つだけ格納される.
    ChoosableSet(const vector<T> &vec) {
        for(int i = 0; i < vec.size(); i++) {
            if(!this->contains(vec[i])) {
                idx[vec[i]] = this->vec.size();
                this->vec.emplace_back(vec[i]);
            }
        }
    }

    // O(1)
    int size() const { return vec.size(); }

    // O(logN)
    bool contains(const T val) const { return idx.count(val); }

    // O(1)
    bool empty() const { return vec.size() == 0; }

    // O(logN)
    void emplace(const T val) {
        if(this->contains(val)) return;
        idx[val] = vec.size();
        vec.emplace_back(val);
    }

    // O(logN)
    void erase(const int val) {
        if(!this->contains(val)) return;

        // valをvecの末尾に移動
        int val_index = idx.at(val);
        if(val_index + 1 != idx.size()) {
            idx[vec.back()] = val_index;
            swap(vec[val_index], vec.back());
        }

        // valを削除
        idx.erase(val);
        vec.pop_back();
    }

    // O(1)
    // 要素から無作為に一つ抽出
    T choice() {
        assert(!this->empty());
        T ret = vec[rand_int(0, this->size())];
        return ret;
    }

    // O(N), ⚠️O(choice_num)ではない
    // 指定された個数だけ、要素から無作為に抽出
    vector<T> choice(size_t choice_num) {
        assert(this->size() >= choice_num);
        vector<T> ret;
        sample(vec.begin(), vec.end(), back_inserter(ret), choice_num, mt);
        return ret;
    }

    friend ostream &operator<<(ostream &o, const ChoosableSet &cs) {
        o << cs.vec;
        return o;
    }
};
