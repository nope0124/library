#pragma once

#include <string>
#include <utility>
#include <vector>

/**
 * @brief Run Length Encoding (ランレングス圧縮)
 */
template<class T> std::vector<std::pair<T, int>> run_length_encoding(std::vector<T>& V) {
    assert((int)(V.size()) > 0);
    std::vector<std::pair<T, int>> res = {std::pair<T, int>(V.front(), 0)};
    for (auto c: V) {
        if (c != res.back().first) {
            res.push_back(std::pair<T, int>(c, 0));
        }
        res.back().second++;
    }
    return res;
}

std::vector<std::pair<char, int>> run_length_encoding(std::string& S) {
    int n = (int)(S.size());
    std::vector<char> V(n);
    for (int i = 0; i < n; i++) V[i] = S[i];
    return run_length_encoding(V);
}
