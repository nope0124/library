#pragma once

#include <vector>
#include <queue>
#include "graph_template.hpp"

template<class T> struct Edge {
    int to;
    T cost;

    Edge(int to, T cost) : to(to), cost(cost) {}
};

template<class T> struct Dijkstra {
    int n, inf;
    std::vector<T> dist;
    std::vector<int> parents;
    Graph<Edge<T>> graph;

    Dijkstra(Graph<Edge<T>> &graph, int start = 0, T inf = 1e16) : n((int)(graph.size())), inf(inf), dist(n, inf), parents(n, -1), graph(graph) {
        std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>, std::greater<std::pair<T, int>>> que;
        dist[start] = 0;

        que.push(std::pair<T, int>(T(0), start)); // pair(距離, 到着点)
        while (!que.empty()) {
            auto p = que.top(); que.pop();
            T d = p.first;
            int v = p.second;
            if (dist[v] < d) continue;
            for (auto e: graph[v]) {
                if (dist[e.to] > dist[v] + e.cost) {
                    dist[e.to] = dist[v] + e.cost;
                    parents[e.to] = v;
                    que.push(std::pair<T, int>(dist[e.to], e.to));
                }
            }
        }
    }

    void init(int start) {
        std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>, std::greater<std::pair<T, int>>> que;
        dist.assign(n, inf);
        parents.assign(n, -1);
        dist[start] = 0;

        que.push(std::pair<T, int>(T(0), start)); // pair(距離, 到着点)
        while (!que.empty()) {
            auto p = que.top(); que.pop();
            T d = p.first;
            int v = p.second;
            if (dist[v] < d) continue;
            for (auto e: graph[v]) {
                if (dist[e.to] > dist[v] + e.cost) {
                    dist[e.to] = dist[v] + e.cost;
                    parents[e.to] = v;
                    que.push(std::pair<T, int>(dist[e.to], e.to));
                }
            }
        }
    }

    std::vector<int> get_path(int end) {
        std::vector<int> path;
        for (int cur = end; cur != -1; cur = parents[cur]) {
            path.push_back(cur);
        }
        reverse(path.begin(), path.end());
    }

};