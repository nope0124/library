---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: "Dijkstra (\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5)"
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Tree Diameter (\u6728\u306E\u76F4\u5F84)"
    links: []
  bundledCode: "#line 2 \"graph/tree_diameter.hpp\"\n\n#include <vector>\n#line 2\
    \ \"graph/graph_template.hpp\"\n\n#line 4 \"graph/graph_template.hpp\"\n\n/**\n\
    \ * @brief \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n */\ntemplate<class\
    \ T> struct Edge {\n    int to;\n    T cost;\n\n    Edge(int to, T cost) : to(to),\
    \ cost(cost) {}\n};\n\ntemplate<class T> struct Graph {\n    int n;\n    std::vector<std::vector<T>>\
    \ graph;\n\n    Graph(int n) : n(n), graph(n, std::vector<T>()) {}\n    inline\
    \ std::vector<T>& operator[] (int i) { return graph[i]; }\n    size_t size() const\
    \ { return graph.size(); }\n\n    std::vector<int> preorder, postorder;\n\n  \
    \  /**\n     * @brief \u884C\u304D\u304C\u3051\u9806\u3001\u5E30\u308A\u304C\u3051\
    \u9806\u306E\u914D\u5217\u3092\u4F5C\u308B\n     */\n    void calculateOrder()\
    \ {\n        std::vector<bool> reached(n, false);\n        auto dfs = [&](auto\
    \ f, int v, int p) -> void {\n            if (reached[v]) return;\n          \
    \  reached[v] = true;\n            preorder.push_back(v);\n            for (auto\
    \ c: graph[v]) {\n                if (c == p) continue;\n                f(f,\
    \ c, v);\n            }\n            postorder.push_back(v);\n            return;\n\
    \        };\n\n        for (int i = 0; i < n; i++) if (!reached[i]) dfs(dfs, i,\
    \ -1);\n\n        assert((int)(preorder.size()) == n);\n        assert((int)(postorder.size())\
    \ == n);\n    }\n};\n#line 2 \"graph/dijkstra.hpp\"\n\n#line 4 \"graph/dijkstra.hpp\"\
    \n#include <queue>\n#line 6 \"graph/dijkstra.hpp\"\n\n/**\n * @brief Dijkstra\
    \ (\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5)\n */\ntemplate<class T> struct\
    \ Dijkstra {\n    int n, inf;\n    std::vector<T> dist;\n    std::vector<int>\
    \ parents;\n    Graph<Edge<T>> graph;\n\n    Dijkstra(Graph<Edge<T>> &graph, int\
    \ start = 0, T inf = 1e16) : n((int)(graph.size())), inf(inf), dist(n, inf), parents(n,\
    \ -1), graph(graph) {\n        std::priority_queue<std::pair<T, int>, std::vector<std::pair<T,\
    \ int>>, std::greater<std::pair<T, int>>> que;\n        dist[start] = 0;\n\n \
    \       que.push(std::pair<T, int>(T(0), start)); // pair(\u8DDD\u96E2, \u5230\
    \u7740\u70B9)\n        while (!que.empty()) {\n            auto p = que.top();\
    \ que.pop();\n            T d = p.first;\n            int v = p.second;\n    \
    \        if (dist[v] < d) continue;\n            for (auto e: graph[v]) {\n  \
    \              if (dist[e.to] > dist[v] + e.cost) {\n                    dist[e.to]\
    \ = dist[v] + e.cost;\n                    parents[e.to] = v;\n              \
    \      que.push(std::pair<T, int>(dist[e.to], e.to));\n                }\n   \
    \         }\n        }\n    }\n\n    void init(int start) {\n        std::priority_queue<std::pair<T,\
    \ int>, std::vector<std::pair<T, int>>, std::greater<std::pair<T, int>>> que;\n\
    \        dist.assign(n, inf);\n        parents.assign(n, -1);\n        dist[start]\
    \ = 0;\n\n        que.push(std::pair<T, int>(T(0), start)); // pair(\u8DDD\u96E2\
    , \u5230\u7740\u70B9)\n        while (!que.empty()) {\n            auto p = que.top();\
    \ que.pop();\n            T d = p.first;\n            int v = p.second;\n    \
    \        if (dist[v] < d) continue;\n            for (auto e: graph[v]) {\n  \
    \              if (dist[e.to] > dist[v] + e.cost) {\n                    dist[e.to]\
    \ = dist[v] + e.cost;\n                    parents[e.to] = v;\n              \
    \      que.push(std::pair<T, int>(dist[e.to], e.to));\n                }\n   \
    \         }\n        }\n    }\n\n    std::vector<int> getPath(int end) {\n   \
    \     std::vector<int> path;\n        for (int cur = end; cur != -1; cur = parents[cur])\
    \ {\n            path.push_back(cur);\n        }\n        reverse(path.begin(),\
    \ path.end());\n        return path;\n    }\n};\n#line 6 \"graph/tree_diameter.hpp\"\
    \n\n/**\n * @brief Tree Diameter (\u6728\u306E\u76F4\u5F84)\n */\ntemplate<class\
    \ T> int tree_diameter(Graph<Edge<T>> &graph) {\n    Dijkstra<T> ds(graph);\n\
    \    int idx = max_element(ds.dist.begin(), ds.dist.end()) - ds.dist.begin();\n\
    \    ds.init(idx);\n    return *max_element(ds.dist.begin(), ds.dist.end());\n\
    }\n"
  code: "#pragma once\n\n#include <vector>\n#include \"graph_template.hpp\"\n#include\
    \ \"dijkstra.hpp\"\n\n/**\n * @brief Tree Diameter (\u6728\u306E\u76F4\u5F84)\n\
    \ */\ntemplate<class T> int tree_diameter(Graph<Edge<T>> &graph) {\n    Dijkstra<T>\
    \ ds(graph);\n    int idx = max_element(ds.dist.begin(), ds.dist.end()) - ds.dist.begin();\n\
    \    ds.init(idx);\n    return *max_element(ds.dist.begin(), ds.dist.end());\n\
    }"
  dependsOn:
  - graph/graph_template.hpp
  - graph/dijkstra.hpp
  isVerificationFile: false
  path: graph/tree_diameter.hpp
  requiredBy: []
  timestamp: '2024-09-01 02:25:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree_diameter.hpp
layout: document
redirect_from:
- /library/graph/tree_diameter.hpp
- /library/graph/tree_diameter.hpp.html
title: "Tree Diameter (\u6728\u306E\u76F4\u5F84)"
---
