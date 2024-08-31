#pragma once

#include <vector>
#include <queue>
#include "graph_template.hpp"

/**
 * @brief Topological Sort (トポロジカルソート)
 */
template<class T> std::vector<int> topological_sort(Graph<T> &graph) {
    int n = (int)(graph.size());
    std::vector<int> res, indeg(n, 0);

    for (int i = 0; i < n; i++) {
        for (auto c: graph[i]) {
            indeg[c]++;
        }
    }

    std::queue<int> que;
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) que.push(i);
    }

    while (!que.empty()) {
        auto v = que.front(); que.pop();
        res.push_back(v);
        for (auto c: graph[v]) {
            indeg[c]--;
            assert(indeg[c] >= 0);
            if (indeg[c] == 0) que.push(c);
        }
    }

    return res;
}