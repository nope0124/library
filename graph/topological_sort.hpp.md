---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: "\u884C\u304D\u304C\u3051\u9806\u3001\u5E30\u308A\u304C\u3051\u9806\u306E\
      \u914D\u5217\u3092\u4F5C\u308B"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/topological_sort.hpp\"\n\n#include <vector>\n#include\
    \ <queue>\n#line 2 \"graph/graph_template.hpp\"\n\n#line 4 \"graph/graph_template.hpp\"\
    \n\ntemplate<class T> struct Graph {\n    int n;\n    std::vector<std::vector<T>>\
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
    \ == n);\n    }\n};\n#line 6 \"graph/topological_sort.hpp\"\n\ntemplate<class\
    \ T> std::vector<int> topological_sort(Graph<T> &graph) {\n    int n = (int)(graph.size());\n\
    \    std::vector<int> res, indeg(n, 0);\n\n    for (int i = 0; i < n; i++) {\n\
    \        for (auto c: graph[i]) {\n            indeg[c]++;\n        }\n    }\n\
    \n    std::queue<int> que;\n    for (int i = 0; i < n; i++) {\n        if (indeg[i]\
    \ == 0) que.push(i);\n    }\n\n    while (!que.empty()) {\n        auto v = que.front();\
    \ que.pop();\n        res.push_back(v);\n        for (auto c: graph[v]) {\n  \
    \          indeg[c]--;\n            assert(indeg[c] >= 0);\n            if (indeg[c]\
    \ == 0) que.push(c);\n        }\n    }\n\n    return res;\n}\n"
  code: "#pragma once\n\n#include <vector>\n#include <queue>\n#include \"graph_template.hpp\"\
    \n\ntemplate<class T> std::vector<int> topological_sort(Graph<T> &graph) {\n \
    \   int n = (int)(graph.size());\n    std::vector<int> res, indeg(n, 0);\n\n \
    \   for (int i = 0; i < n; i++) {\n        for (auto c: graph[i]) {\n        \
    \    indeg[c]++;\n        }\n    }\n\n    std::queue<int> que;\n    for (int i\
    \ = 0; i < n; i++) {\n        if (indeg[i] == 0) que.push(i);\n    }\n\n    while\
    \ (!que.empty()) {\n        auto v = que.front(); que.pop();\n        res.push_back(v);\n\
    \        for (auto c: graph[v]) {\n            indeg[c]--;\n            assert(indeg[c]\
    \ >= 0);\n            if (indeg[c] == 0) que.push(c);\n        }\n    }\n\n  \
    \  return res;\n}"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/topological_sort.hpp
  requiredBy: []
  timestamp: '2024-08-31 00:59:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/topological_sort.hpp
layout: document
redirect_from:
- /library/graph/topological_sort.hpp
- /library/graph/topological_sort.hpp.html
title: graph/topological_sort.hpp
---
