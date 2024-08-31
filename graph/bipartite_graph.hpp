#pragma once

#include <vector>
#include <utility>
#include "graph_template.hpp"

/**
 * @brief Bipartite Graph (トポロジカルソート)
 */
template<class T> struct BipartiteGraph {
    int n, blackCnt, whiteCnt;
    bool isBipartite = true;
    std::vector<int> colors, black, white;

    BipartiteGraph(Graph<T> &graph) : n((int)(graph.size())), colors(n, -1) {
        bool ok = true;
        auto dfs = [&](auto f, int v, int p, int color) -> void {
            if (!ok) return;
            colors[v] = color;
            for (auto c: graph[v]) {
                if (c == p) continue;
                // もし二部グラフが作成できない場合
                if (colors[c] != -1) ok = false;
                f(f, c, v, 1 - color);
            }
            return;
        };
        for (int i = 0; i < n; i++) {
            if (colors[i] == -1) dfs(dfs, i, -1, 0);
            if (!ok) {
                colors = std::vector<int>(n, -1);
                isBipartite = false;
                return;
            }
        }
        for (int i = 0; i < n; i++) {
            if (colors[i] == 0) black.push_back(i);
            else if (colors[i] == 1) white.push_back(i);
            else assert(false);
        }
        blackCnt = (int)(black.size());
        whiteCnt = (int)(white.size());
        return;
    }
};