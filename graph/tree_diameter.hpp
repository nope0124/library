#pragma once

#include <vector>
#include <queue>

template<class T> int tree_diameter(Graph<T> &graph) {
    int n = (int)(graph.size());
    std::vector<int> dist(n, -1);

    std::queue<int> que;
    dist[0] = 0;
    que.push(0);
    while (!que.empty()) {
        auto v = que.front(); que.pop();
        for (auto c: graph[v]) {
            if (dist[c] != -1) continue;
            dist[c] = dist[v] + 1;
            que.push(c);
        }
    }
    int idx = max_element(dist.begin(), dist.end()) - dist.begin();
    dist.assign(n, -1);
    dist[idx] = 0;
    que.push(idx);
    while (!que.empty()) {
        auto v = que.front(); que.pop();
        for (auto c: graph[v]) {
            if (dist[c] != -1) continue;
            dist[c] = dist[v] + 1;
            que.push(c);
        }
    }
    return *max_element(dist.begin(), dist.end());
}