---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/data_structure/prefix_sum_2d_1.test.cpp
    title: verify/data_structure/prefix_sum_2d_1.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Prefix Sum 2D (\u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C)"
    links: []
  bundledCode: "#line 2 \"data_structure/prefix_sum_2d.hpp\"\n\n#include <vector>\n\
    \n/**\n * @brief Prefix Sum 2D (\u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C)\n */\ntemplate<class\
    \ T> struct PrefixSum2D {\n    int h, w;\n    std::vector<std::vector<T>> board;\n\
    \    PrefixSum2D(std::vector<std::vector<T>>& V) {\n        h = (int)(V.size());\n\
    \        assert(h > 0);\n        w = (int)(V[0].size());\n        board.assign(h\
    \ + 1, std::vector<T>(w + 1, T(0)));\n        for (int i = 0; i < h; i++) {\n\
    \            for (int j = 0; j < w; j++) {\n                board[i + 1][j + 1]\
    \ = V[i][j];\n            }\n        }\n        for (int i = 0; i < h; i++) {\n\
    \            for (int j = 0; j < w + 1; j++) {\n                board[i + 1][j]\
    \ += board[i][j];\n            }\n        }\n        for (int j = 0; j < w; j++)\
    \ {\n            for (int i = 0; i < h + 1; i++) {\n                board[i][j\
    \ + 1] += board[i][j];\n            }\n        }\n        h++;\n        w++;\n\
    \    }\n\n    T getSum(int x1, int y1, int x2, int y2) {\n        assert(0 <=\
    \ x1 && x1 <= x2 && x2 < w);\n        assert(0 <= y1 && y1 <= y2 && y2 < h);\n\
    \        T val = board[y2][x2] - board[y2][x1] - board[y1][x2] + board[y1][x1];\n\
    \        return val;\n    }\n\n    T get(int x, int y) {\n        assert(0 <=\
    \ x && x < w);\n        assert(0 <= y && y < h);\n        return board[y][x];\n\
    \    }\n\n};\n"
  code: "#pragma once\n\n#include <vector>\n\n/**\n * @brief Prefix Sum 2D (\u4E8C\
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
    \ board[y][x];\n    }\n\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/prefix_sum_2d.hpp
  requiredBy: []
  timestamp: '2024-09-04 23:43:12+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/data_structure/prefix_sum_2d_1.test.cpp
documentation_of: data_structure/prefix_sum_2d.hpp
layout: document
redirect_from:
- /library/data_structure/prefix_sum_2d.hpp
- /library/data_structure/prefix_sum_2d.hpp.html
title: "Prefix Sum 2D (\u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C)"
---
