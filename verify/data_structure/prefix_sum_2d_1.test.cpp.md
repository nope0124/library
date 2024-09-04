---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data_structure/prefix_sum_2d.hpp
    title: "Prefix Sum 2D (\u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
  bundledCode: "#line 1 \"verify/data_structure/prefix_sum_2d_1.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\
    \n#include <bits/stdc++.h>\n#line 2 \"data_structure/prefix_sum_2d.hpp\"\n\n#line\
    \ 4 \"data_structure/prefix_sum_2d.hpp\"\n\n/**\n * @brief Prefix Sum 2D (\u4E8C\
    \u6B21\u5143\u7D2F\u7A4D\u548C)\n */\ntemplate<class T> struct PrefixSum2D {\n\
    \    int h, w;\n    std::vector<std::vector<T>> board;\n    PrefixSum2D(std::vector<std::vector<T>>&\
    \ V) {\n        h = (int)(V.size());\n        assert(h > 0);\n        w = (int)(V[0].size());\n\
    \        board.assign(h + 1, std::vector<T>(w + 1, T(0)));\n        for (int i\
    \ = 0; i < h; i++) {\n            for (int j = 0; j < w; j++) {\n            \
    \    board[i + 1][j + 1] = V[i][j];\n            }\n        }\n        for (int\
    \ i = 0; i < h; i++) {\n            for (int j = 0; j < w + 1; j++) {\n      \
    \          board[i + 1][j] += board[i][j];\n            }\n        }\n       \
    \ for (int j = 0; j < w; j++) {\n            for (int i = 0; i < h + 1; i++) {\n\
    \                board[i][j + 1] += board[i][j];\n            }\n        }\n \
    \       h++;\n        w++;\n    }\n\n    T getSum(int x1, int y1, int x2, int\
    \ y2) {\n        assert(0 <= x1 && x1 <= x2 && x2 < w);\n        assert(0 <= y1\
    \ && y1 <= y2 && y2 < h);\n        T val = board[y2][x2] - board[y2][x1] - board[y1][x2]\
    \ + board[y1][x1];\n        return val;\n    }\n\n    T get(int x, int y) {\n\
    \        assert(0 <= x && x < w);\n        assert(0 <= y && y < h);\n        return\
    \ board[y][x];\n    }\n\n};\n#line 4 \"verify/data_structure/prefix_sum_2d_1.test.cpp\"\
    \nusing namespace std;\ntypedef long long int ll;\n#define rep(i, N) for(ll i\
    \ = 0; i < (ll)N; i++)\n\nint main() {\n    ll N; cin >> N;\n    vector<vector<ll>>\
    \ V(1010, vector<ll>(1010, 0));\n    rep (i, N) {\n        ll x1, y1, x2, y2;\
    \ cin >> x1 >> y1 >> x2 >> y2;\n        V[y1][x1]++;\n        V[y2][x2]++;\n \
    \       V[y1][x2]--;\n        V[y2][x1]--;\n    }\n    PrefixSum2D<ll> ps(V);\n\
    \    ll ans = 0;\n    rep (i, ps.h) {\n        rep (j, ps.w) {\n            ans\
    \ = max(ans, ps.get(j, i));\n        }\n    }\n    cout << ans << endl;\n\n  \
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\
    \n#include <bits/stdc++.h>\n#include \"data_structure/prefix_sum_2d.hpp\"\nusing\
    \ namespace std;\ntypedef long long int ll;\n#define rep(i, N) for(ll i = 0; i\
    \ < (ll)N; i++)\n\nint main() {\n    ll N; cin >> N;\n    vector<vector<ll>> V(1010,\
    \ vector<ll>(1010, 0));\n    rep (i, N) {\n        ll x1, y1, x2, y2; cin >> x1\
    \ >> y1 >> x2 >> y2;\n        V[y1][x1]++;\n        V[y2][x2]++;\n        V[y1][x2]--;\n\
    \        V[y2][x1]--;\n    }\n    PrefixSum2D<ll> ps(V);\n    ll ans = 0;\n  \
    \  rep (i, ps.h) {\n        rep (j, ps.w) {\n            ans = max(ans, ps.get(j,\
    \ i));\n        }\n    }\n    cout << ans << endl;\n\n    return 0;\n}"
  dependsOn:
  - data_structure/prefix_sum_2d.hpp
  isVerificationFile: true
  path: verify/data_structure/prefix_sum_2d_1.test.cpp
  requiredBy: []
  timestamp: '2024-09-04 23:43:12+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/data_structure/prefix_sum_2d_1.test.cpp
layout: document
redirect_from:
- /verify/verify/data_structure/prefix_sum_2d_1.test.cpp
- /verify/verify/data_structure/prefix_sum_2d_1.test.cpp.html
title: verify/data_structure/prefix_sum_2d_1.test.cpp
---
