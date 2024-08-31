---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: graph/dijkstra.hpp
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: "\u884C\u304D\u304C\u3051\u9806\u3001\u5E30\u308A\u304C\u3051\u9806\u306E\
      \u914D\u5217\u3092\u4F5C\u308B"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
  bundledCode: "#line 1 \"verify/graph/dijkstra_1.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \n#include <bits/stdc++.h>\n#line 2 \"graph/graph_template.hpp\"\n\n#line 4 \"\
    graph/graph_template.hpp\"\n\ntemplate<class T> struct Graph {\n    int n;\n \
    \   std::vector<std::vector<T>> graph;\n\n    Graph(int n) : n(n), graph(n, std::vector<T>())\
    \ {}\n    inline std::vector<T>& operator[] (int i) { return graph[i]; }\n   \
    \ size_t size() const { return graph.size(); }\n\n    std::vector<int> preorder,\
    \ postorder;\n\n    /**\n     * @brief \u884C\u304D\u304C\u3051\u9806\u3001\u5E30\
    \u308A\u304C\u3051\u9806\u306E\u914D\u5217\u3092\u4F5C\u308B\n     */\n    void\
    \ calculateOrder() {\n        std::vector<bool> reached(n, false);\n        auto\
    \ dfs = [&](auto f, int v, int p) -> void {\n            if (reached[v]) return;\n\
    \            reached[v] = true;\n            preorder.push_back(v);\n        \
    \    for (auto c: graph[v]) {\n                if (c == p) continue;\n       \
    \         f(f, c, v);\n            }\n            postorder.push_back(v);\n  \
    \          return;\n        };\n\n        for (int i = 0; i < n; i++) if (!reached[i])\
    \ dfs(dfs, i, -1);\n\n        assert((int)(preorder.size()) == n);\n        assert((int)(postorder.size())\
    \ == n);\n    }\n};\n#line 2 \"graph/dijkstra.hpp\"\n\n#line 6 \"graph/dijkstra.hpp\"\
    \n\ntemplate<class T> struct Edge {\n    int to;\n    T cost;\n\n    Edge(int\
    \ to, T cost) : to(to), cost(cost) {}\n};\n\ntemplate<class T> struct Dijkstra\
    \ {\n    int n, inf;\n    std::vector<T> dist;\n    std::vector<int> parents;\n\
    \    Graph<Edge<T>> graph;\n\n    Dijkstra(Graph<Edge<T>> &graph, int start =\
    \ 0, T inf = 1e16) : n((int)(graph.size())), inf(inf), dist(n, inf), parents(n,\
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
    \ path.end());\n        return path;\n    }\n};\n#line 5 \"verify/graph/dijkstra_1.test.cpp\"\
    \nusing namespace std;\ntypedef long long int ll;\n#define rep(i, N) for(ll i\
    \ = 0; i < (ll)N; i++)\nconst ll INF = 1e17;\n\nint main() {\n    ll N, M, start;\
    \ cin >> N >> M >> start;\n    Graph<Edge<ll>> graph(N);\n    rep (i, M) {\n \
    \       ll a, b, c; cin >> a >> b >> c;\n        graph[a].push_back(Edge<ll>(b,\
    \ c));\n    }\n\n    Dijkstra<ll> ds(graph, start, INF);\n    rep (i, N) {\n \
    \       if (ds.dist[i] == INF) cout << \"INF\" << endl;\n        else cout <<\
    \ ds.dist[i] << endl;\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \n#include <bits/stdc++.h>\n#include \"graph/graph_template.hpp\"\n#include \"\
    graph/dijkstra.hpp\"\nusing namespace std;\ntypedef long long int ll;\n#define\
    \ rep(i, N) for(ll i = 0; i < (ll)N; i++)\nconst ll INF = 1e17;\n\nint main()\
    \ {\n    ll N, M, start; cin >> N >> M >> start;\n    Graph<Edge<ll>> graph(N);\n\
    \    rep (i, M) {\n        ll a, b, c; cin >> a >> b >> c;\n        graph[a].push_back(Edge<ll>(b,\
    \ c));\n    }\n\n    Dijkstra<ll> ds(graph, start, INF);\n    rep (i, N) {\n \
    \       if (ds.dist[i] == INF) cout << \"INF\" << endl;\n        else cout <<\
    \ ds.dist[i] << endl;\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - graph/graph_template.hpp
  - graph/dijkstra.hpp
  isVerificationFile: true
  path: verify/graph/dijkstra_1.test.cpp
  requiredBy: []
  timestamp: '2024-08-31 22:21:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/graph/dijkstra_1.test.cpp
layout: document
redirect_from:
- /verify/verify/graph/dijkstra_1.test.cpp
- /verify/verify/graph/dijkstra_1.test.cpp.html
title: verify/graph/dijkstra_1.test.cpp
---
