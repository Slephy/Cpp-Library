#pragma once
#include <string>
#include <vector>
using namespace std;

template <typename Iterator> vector<int> z_algorithm(const Iterator begin, const Iterator end) {
    int n = end - begin;
    assert(n >= 0);
    vector<int> ret(n, 0);
    ret[0] = n;

    for(int i = 1, j = 0; i < n;) {
        while(i + j < n && begin[i + j] == begin[j]) j++;
        ret[i] = j;
        if(j == 0) {
            i++;
            continue;
        }

        int k = 1;
        while(i + k < n && k + ret[k] < ret[i]) ret[i + k] = ret[k], k++;
        i += k;
        j -= k;
    }
    return ret;
}

vector<int> z_algorithm(const string &s) { return z_algorithm(s.begin(), s.end()); }

template <class T> vector<int> z_algorithm(const vector<T> &v) { return z_algorithm(v.begin(), v.end()); }
