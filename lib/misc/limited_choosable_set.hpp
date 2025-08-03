#pragma once
#include "../core/core.hpp"
#include "../random/random.hpp"
// [0, n) の整数を要素とする集合を扱うクラス
// 集合内からランダムに要素を抽出する操作を O(1) でできるのが強み（setだと時間がかかる）
class LimitedChoosableSet {
private:
    vector<int> vec;
    vector<int> idx;   // idx[val] := (vec内でのvalのインデックス), idx[val] = -1 のときvalは格納されていない
    size_t max_value;  // 挿入できる値の最大値


public:
    LimitedChoosableSet(size_t max_value) : max_value(max_value) {}
    // vector<int> で初期化. 重複要素は一つだけ格納される.
    LimitedChoosableSet(const vector<int> &vec, size_t max_value) : idx(max_value + 1, -1), max_value(max_value) {
        for(int i = 0; i < vec.size(); i++) {
            assert(0 <= vec[i] && vec[i] <= max_value);
            if(!this->contains(vec[i])) {
                this->vec.emplace_back(vec[i]);
                idx.at(vec[i]) = i;
            }
        }
    }

    // O(1)
    int size() const { return vec.size(); }

    // O(1)
    bool contains(const int val) const { return idx.at(val) != -1; }

    // O(1)
    bool empty() const { return vec.size() == 0; }

    // O(1)
    void emplace(const int val) {
        if(this->contains(val)) return;
        idx.at(val) = vec.size();
        vec.emplace_back(val);
    }

    // O(1)
    void erase(const int val) {
        if(!this->contains(val)) return;

        // valをvecの末尾に移動
        int val_index = idx.at(val);
        if(val_index + 1 != idx.size()) {
            idx[vec.back()] = val_index;
            swap(vec[val_index], vec.back());
        }

        // valを削除
        idx.at(val) = -1;
        vec.pop_back();
    }

    // O(1)
    // 要素から無作為に一つ抽出
    int choice() {
        assert(!this->empty());
        int ret = vec[rand_int(0, this->size())];
        return ret;
    }

    // O(N), ⚠️O(choice_num)ではない
    // 指定された個数だけ、要素から無作為に抽出
    vector<int> choice(size_t choice_num) {
        assert(this->size() >= choice_num);
        vector<int> ret;
        sample(vec.begin(), vec.end(), back_inserter(ret), choice_num, mt);
        return ret;
    }

    friend ostream &operator<<(ostream &o, const LimitedChoosableSet &ls) {
        o << ls.vec;
        return o;
    }
};
