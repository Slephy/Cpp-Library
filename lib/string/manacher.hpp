#pragma once
#include "../core/core.hpp"

enum class ManacherType {
    even,
    odd,
};

enum class ManacherResultType {
    radius,    // 回文の半径
    diameter,  // 回文の直径（長さ）
};

// O(s.size())
template <class Iterator>
vector<int> Manacher(Iterator begin, Iterator end, ManacherType mtype, ManacherResultType rtype) {
    // evenのときはDAMMYを挟んで奇数にする
    string withDammy = "";
    const char DAMMY = '`';
    if(mtype == ManacherType::even) {
        for(auto i = begin; i < end; i++) {
            if(!withDammy.empty()) withDammy += DAMMY;
            withDammy += *i;
        }
        begin = withDammy.begin();
        end = withDammy.end();
    }

    // メイン処理
    vector<int> res;
    {
        int size = end - begin;
        res.resize(size);
        int i = 0, j = 1;
        while(i < res.size()) {
            while(i - j >= 0 && i + j < size && begin[i - j] == begin[i + j]) j++;

            res[i] = j;
            int k = 1;
            while(i - k >= 0 && i + k < size && i - res[i] < (i - k) - res[i - k]) {
                res[i + k] = res[i - k];
                k++;
            }
            i += k, j -= k;
        }
    }

    // even のときは DAMMY の位置だけ結果を抽出する
    if(mtype == ManacherType::even) {
        vector<int> tmp;
        tmp.reserve(res.size() / 2 + 1);
        for(int i = 1; i < res.size(); i += 2) tmp.emplace_back(res[i]);
        res = move(tmp);
    }

    // 結果を変換する
    if(rtype == ManacherResultType::radius) {
        if(mtype == ManacherType::odd)
            ;
        if(mtype == ManacherType::even)
            for(auto &v : res) v = v / 2;
    }
    if(rtype == ManacherResultType::diameter) {
        if(mtype == ManacherType::odd)
            for(auto &v : res) v = 2 * v - 1;
        if(mtype == ManacherType::even)
            for(auto &v : res) v = v - (v & 1);
    }
    return res;
}

vector<int> Manacher(const string &s, ManacherType mtype, ManacherResultType rtype) {
    return Manacher(s.begin(), s.end(), mtype, rtype);
}
