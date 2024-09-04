#pragma once

#include <vector>

/**
 * @brief Prefix Sum 2D (二次元累積和)
 */
template<class T> struct PrefixSum2D {
    int h, w;
    std::vector<std::vector<T>> board;
    PrefixSum2D(std::vector<std::vector<T>>& V) {
        h = (int)(V.size());
        assert(h > 0);
        w = (int)(V[0].size());
        board.assign(h + 1, std::vector<T>(w + 1, T(0)));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                board[i + 1][j + 1] = V[i][j];
            }
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w + 1; j++) {
                board[i + 1][j] += board[i][j];
            }
        }
        for (int j = 0; j < w; j++) {
            for (int i = 0; i < h + 1; i++) {
                board[i][j + 1] += board[i][j];
            }
        }
    }

    T getSum(int x1, int y1, int x2, int y2) {
        assert(0 <= x1 && x1 <= x2 && x2 <= w);
        assert(0 <= y1 && y1 <= y2 && y2 <= h);
        T val = board[y2][x2] - board[y2][x1] - board[y1][x2] + board[y1][x1];
        return val;
    }

    T get(int x, int y) {
        assert(0 <= x && x <= w);
        assert(0 <= y && y <= h);
        return board[y][x];
    }

};
