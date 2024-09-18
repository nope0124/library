---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/bipartite_graph.hpp
    title: "Bipartite Graph (\u4E8C\u90E8\u30B0\u30E9\u30D5)"
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc327/tasks/abc327_d
    links:
    - https://atcoder.jp/contests/abc327/tasks/abc327_d
  bundledCode: "#line 1 \"verify/graph/bipartite_graph_1.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc327/tasks/abc327_d\"\n#include <bits/stdc++.h>\n\
    #line 2 \"graph/graph_template.hpp\"\n\n#line 4 \"graph/graph_template.hpp\"\n\
    \n/**\n * @brief \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n */\n\
    template<class T> struct Edge {\n    int from;\n    int to;\n    T cost;\n\n \
    \   Edge(int from = -1, int to = -1, T cost = -1) : from(from), to(to), cost(cost)\
    \ {}\n};\n\ntemplate<class T> struct Graph {\n    int n;\n    std::vector<std::vector<T>>\
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
    \ == n);\n    }\n};\n#line 2 \"graph/bipartite_graph.hpp\"\n\n#line 6 \"graph/bipartite_graph.hpp\"\
    \n\n/**\n * @brief Bipartite Graph (\u4E8C\u90E8\u30B0\u30E9\u30D5)\n */\ntemplate<class\
    \ T> struct BipartiteGraph {\n    int n, blackCnt, whiteCnt;\n    bool isBipartite\
    \ = true;\n    std::vector<int> colors, black, white;\n\n    BipartiteGraph(Graph<T>\
    \ &graph) : n((int)(graph.size())), colors(n, -1) {\n        bool ok = true;\n\
    \        auto dfs = [&](auto f, int v, int p, int color) -> void {\n         \
    \   if (!ok) return;\n            if (colors[v] != -1) return;\n            colors[v]\
    \ = color;\n            for (auto c: graph[v]) {\n                if (c == p)\
    \ continue;\n                // \u3082\u3057\u4E8C\u90E8\u30B0\u30E9\u30D5\u304C\
    \u4F5C\u6210\u3067\u304D\u306A\u3044\u5834\u5408\n                if (colors[c]\
    \ == color) ok = false;\n                f(f, c, v, 1 - color);\n            }\n\
    \            return;\n        };\n        for (int i = 0; i < n; i++) {\n    \
    \        if (colors[i] == -1) dfs(dfs, i, -1, 0);\n            if (!ok) {\n  \
    \              colors = std::vector<int>(n, -1);\n                isBipartite\
    \ = false;\n                return;\n            }\n        }\n        for (int\
    \ i = 0; i < n; i++) {\n            if (colors[i] == 0) black.push_back(i);\n\
    \            else if (colors[i] == 1) white.push_back(i);\n            else assert(false);\n\
    \        }\n        blackCnt = (int)(black.size());\n        whiteCnt = (int)(white.size());\n\
    \        return;\n    }\n};\n#line 5 \"verify/graph/bipartite_graph_1.test.cpp\"\
    \nusing namespace std;\ntypedef long long int ll;\n#define rep(i, N) for(ll i\
    \ = 0; i < (ll)N; i++)\n\nint main() {\n    ll N, M; cin >> N >> M;\n    vector<ll>\
    \ A(M), B(M);\n    Graph<ll> graph(N);\n    rep (i, M) cin >> A[i], A[i]--;\n\
    \    rep (i, M) cin >> B[i], B[i]--;\n    rep (i, M) {\n        graph[A[i]].push_back(B[i]);\n\
    \        graph[B[i]].push_back(A[i]);\n    }\n\n    BipartiteGraph<ll> bg(graph);\n\
    \    if (bg.isBipartite) cout << \"Yes\" << endl;\n    else cout << \"No\" <<\
    \ endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc327/tasks/abc327_d\"\n#include\
    \ <bits/stdc++.h>\n#include \"graph/graph_template.hpp\"\n#include \"graph/bipartite_graph.hpp\"\
    \nusing namespace std;\ntypedef long long int ll;\n#define rep(i, N) for(ll i\
    \ = 0; i < (ll)N; i++)\n\nint main() {\n    ll N, M; cin >> N >> M;\n    vector<ll>\
    \ A(M), B(M);\n    Graph<ll> graph(N);\n    rep (i, M) cin >> A[i], A[i]--;\n\
    \    rep (i, M) cin >> B[i], B[i]--;\n    rep (i, M) {\n        graph[A[i]].push_back(B[i]);\n\
    \        graph[B[i]].push_back(A[i]);\n    }\n\n    BipartiteGraph<ll> bg(graph);\n\
    \    if (bg.isBipartite) cout << \"Yes\" << endl;\n    else cout << \"No\" <<\
    \ endl;\n    return 0;\n}\n"
  dependsOn:
  - graph/graph_template.hpp
  - graph/bipartite_graph.hpp
  isVerificationFile: true
  path: verify/graph/bipartite_graph_1.test.cpp
  requiredBy: []
  timestamp: '2024-09-19 03:10:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/graph/bipartite_graph_1.test.cpp
layout: document
redirect_from:
- /verify/verify/graph/bipartite_graph_1.test.cpp
- /verify/verify/graph/bipartite_graph_1.test.cpp.html
title: verify/graph/bipartite_graph_1.test.cpp
---
