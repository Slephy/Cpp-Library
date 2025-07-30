#pragma once
#include "../core/core.hpp"
// O(|s|)
// 先頭から貪欲に取っていき、重複する区間はカウントしない
// 例) ababa に aba は1つだけ含まれる
[[nodiscard]] ll count_substr(const string &s, const string &search){
    int head = 0;
    ll ret = 0;
    ll fi;
    while((fi = s.find(search, head)) != string::npos){
        ret++;
        head = fi + search.size();
    }
    return ret;
}
