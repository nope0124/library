---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/others/run_length_encoding_1.test.cpp
    title: verify/others/run_length_encoding_1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E (Run Length\
      \ Encoding)"
    links: []
  bundledCode: "#line 2 \"others/run_length_encoding.hpp\"\n\n#include <string>\n\
    #include <utility>\n#include <vector>\n\n/**\n * @brief \u30E9\u30F3\u30EC\u30F3\
    \u30B0\u30B9\u5727\u7E2E (Run Length Encoding)\n */\ntemplate<class T> std::vector<std::pair<T,\
    \ int>> run_length_encoding(std::vector<T>& V) {\n    assert((int)(V.size()) >\
    \ 0);\n    std::vector<std::pair<T, int>> res = {std::pair<T, int>(V.front(),\
    \ 0)};\n    for (auto c: V) {\n        if (c != res.back().first) {\n        \
    \    res.push_back(std::pair<T, int>(c, 0));\n        }\n        res.back().second++;\n\
    \    }\n    return res;\n}\n\nstd::vector<std::pair<char, int>> run_length_encoding(std::string&\
    \ S) {\n    int n = (int)(S.size());\n    std::vector<char> V(n);\n    for (int\
    \ i = 0; i < n; i++) V[i] = S[i];\n    return run_length_encoding(V);\n}\n"
  code: "#pragma once\n\n#include <string>\n#include <utility>\n#include <vector>\n\
    \n/**\n * @brief \u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E (Run Length\
    \ Encoding)\n */\ntemplate<class T> std::vector<std::pair<T, int>> run_length_encoding(std::vector<T>&\
    \ V) {\n    assert((int)(V.size()) > 0);\n    std::vector<std::pair<T, int>> res\
    \ = {std::pair<T, int>(V.front(), 0)};\n    for (auto c: V) {\n        if (c !=\
    \ res.back().first) {\n            res.push_back(std::pair<T, int>(c, 0));\n \
    \       }\n        res.back().second++;\n    }\n    return res;\n}\n\nstd::vector<std::pair<char,\
    \ int>> run_length_encoding(std::string& S) {\n    int n = (int)(S.size());\n\
    \    std::vector<char> V(n);\n    for (int i = 0; i < n; i++) V[i] = S[i];\n \
    \   return run_length_encoding(V);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: others/run_length_encoding.hpp
  requiredBy: []
  timestamp: '2024-09-04 05:39:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/others/run_length_encoding_1.test.cpp
documentation_of: others/run_length_encoding.hpp
layout: document
redirect_from:
- /library/others/run_length_encoding.hpp
- /library/others/run_length_encoding.hpp.html
title: "\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E (Run Length Encoding)"
---
