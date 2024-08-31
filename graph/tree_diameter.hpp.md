---
data:
  _extendedDependsOn:
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
  bundledCode: "#line 2 \"graph/tree_diameter.hpp\"\n\n#include <vector>\n#include\
    \ <queue>\n#line 2 \"graph/graph_template.hpp\"\n\n#line 4 \"graph/graph_template.hpp\"\
    \n\n/**\n * @brief \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n */\n\
    template<class T> struct Graph {\n    int n;\n    std::vector<std::vector<T>>\
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
    \ == n);\n    }\n};\n#line 6 \"graph/tree_diameter.hpp\"\n\n/**\n * @brief Tree\
    \ Diameter (\u6728\u306E\u76F4\u5F84)\n */\ntemplate<class T> int tree_diameter(Graph<T>\
    \ &graph) {\n    int n = (int)(graph.size());\n    std::vector<int> dist(n, -1);\n\
    \n    std::queue<int> que;\n    dist[0] = 0;\n    que.push(0);\n    while (!que.empty())\
    \ {\n        auto v = que.front(); que.pop();\n        for (auto c: graph[v])\
    \ {\n            if (dist[c] != -1) continue;\n            dist[c] = dist[v] +\
    \ 1;\n            que.push(c);\n        }\n    }\n    int idx = max_element(dist.begin(),\
    \ dist.end()) - dist.begin();\n    dist.assign(n, -1);\n    dist[idx] = 0;\n \
    \   que.push(idx);\n    while (!que.empty()) {\n        auto v = que.front();\
    \ que.pop();\n        for (auto c: graph[v]) {\n            if (dist[c] != -1)\
    \ continue;\n            dist[c] = dist[v] + 1;\n            que.push(c);\n  \
    \      }\n    }\n    return *max_element(dist.begin(), dist.end());\n}\n"
  code: "#pragma once\n\n#include <vector>\n#include <queue>\n#include \"graph_template.hpp\"\
    \n\n/**\n * @brief Tree Diameter (\u6728\u306E\u76F4\u5F84)\n */\ntemplate<class\
    \ T> int tree_diameter(Graph<T> &graph) {\n    int n = (int)(graph.size());\n\
    \    std::vector<int> dist(n, -1);\n\n    std::queue<int> que;\n    dist[0] =\
    \ 0;\n    que.push(0);\n    while (!que.empty()) {\n        auto v = que.front();\
    \ que.pop();\n        for (auto c: graph[v]) {\n            if (dist[c] != -1)\
    \ continue;\n            dist[c] = dist[v] + 1;\n            que.push(c);\n  \
    \      }\n    }\n    int idx = max_element(dist.begin(), dist.end()) - dist.begin();\n\
    \    dist.assign(n, -1);\n    dist[idx] = 0;\n    que.push(idx);\n    while (!que.empty())\
    \ {\n        auto v = que.front(); que.pop();\n        for (auto c: graph[v])\
    \ {\n            if (dist[c] != -1) continue;\n            dist[c] = dist[v] +\
    \ 1;\n            que.push(c);\n        }\n    }\n    return *max_element(dist.begin(),\
    \ dist.end());\n}"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/tree_diameter.hpp
  requiredBy: []
  timestamp: '2024-09-01 01:51:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree_diameter.hpp
layout: document
redirect_from:
- /library/graph/tree_diameter.hpp
- /library/graph/tree_diameter.hpp.html
title: "Tree Diameter (\u6728\u306E\u76F4\u5F84)"
---
