#pragma once
#include "../core/core.hpp"
// 反時計回りにグリッドを回転させる
template <class T> [[nodiscard]] vector<vector<T>> rotate_grid(const vector<vector<T>> &grid, int rotate_degree = 0) {
    rotate_degree = ((rotate_degree % 360) + 360) % 360;
    assert(rotate_degree % 90 == 0);

    assert(grid.size() > 0);
    int h = grid.size();
    assert(grid[0].size() > 0);
    int w = grid[0].size();

    vector<vector<T>> ret;
    if(rotate_degree % 180 == 0) ret = vector<vector<T>>(h, vector<T>(w));
    else ret = vector<vector<T>>(w, vector<T>(h));

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            switch(rotate_degree) {
                case 0: ret[i][j] = grid[i][j]; break;
                case 90: ret[w - j - 1][i] = grid[i][j]; break;
                case 180: ret[h - i - 1][w - j - 1] = grid[i][j]; break;
                case 270: ret[j][h - i - 1] = grid[i][j]; break;
            }
        }
    }
    return ret;
}
