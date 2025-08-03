#pragma once
#include "../core/core.hpp"
// (si, sj) を左上端とする rh x rw の矩形を反時計回りに deg 度回転する
// deg は 90 の倍数に限る
template <class T> void rotate_grid_partially(vector<vector<T>> &vec, int si, int sj, int rh, int rw, int deg) {
    const int H = vec.size();
    const int W = vec[0].size();
    assert(0 <= si && si < H);
    assert(0 <= sj && sj < W);
    assert(0 <= si + rh - 1 && si + rh - 1 < H);
    assert(0 <= sj + rw - 1 && sj + rw - 1 < W);

    if(deg < 0 || 360 <= deg) deg %= 360;
    if(deg < 0) deg += 360;
    assert(deg == 0 || deg == 90 || deg == 180 || deg == 270);

    // 90度回転、270度回転の場合は正方形でなければならない
    if(deg == 90 || deg == 270) assert(rh == rw);

    if(deg == 0) return;

    vector<vector<T>> tmp(rh, vector<T>(rw));
    for(int i = 0; i < rh; i++) {
        for(int j = 0; j < rw; j++) {
            switch(deg) {
                case 90: tmp[i][j] = vec[si + j][sj + rh - i - 1]; break;
                case 180: tmp[i][j] = vec[si + rh - i - 1][sj + rw - j - 1]; break;
                case 270: tmp[i][j] = vec[si + rw - j - 1][sj + i]; break;
                default: exit(1);
            }
        }
    }

    for(int i = 0; i < rh; i++) {
        for(int j = 0; j < rw; j++) {
            vec[si + i][sj + j] = tmp[i][j];
        }
    }
    return;
}
