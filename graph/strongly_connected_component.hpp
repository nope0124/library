#pragma once

#include <vector>
#include <utility>
#include "graph_template.hpp"

/**
 * @brief Strongly Connected Component (強連結成分分解)
 */
template<class T> struct StronglyConnectedComponent {
    int n, sz;
    std::vector<int> idxs;
    std::vector<std::vector<int>> groups;

    StronglyConnectedComponent(Graph<T> &graph, Graph<T> &graphRev) : n((int)(graph.size())), idxs(n, -1), groups(n) {
        graph.calculateOrder();
        std::vector<int> postorder = graph.postorder;
        reverse(postorder.begin(), postorder.end());

        int idx = 0;
        auto dfs = [&](auto f, int v, int p) -> void {
            if (idxs[v] != -1) return;
            idxs[v] = idx;
            groups[idx].push_back(v);
            for (auto c: graphRev[v]) {
                if (c == p) continue;
                f(f, c, v);
            }
            return;
        };

        for (int i = 0; i < n; i++) {
            if (idxs[postorder[i]] != -1) continue;
            dfs(dfs, postorder[i], -1);
            idx++;
        }

        sz = idx;

        return;
    }
};