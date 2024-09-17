---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/others/is_parenthesis_1.test.cpp
    title: verify/others/is_parenthesis_1.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "\u62EC\u5F27\u5217\u5224\u5B9A"
    links: []
  bundledCode: "#line 2 \"others/is_parenthesis.hpp\"\n\n#include <string>\n\n/**\n\
    \ * @brief \u62EC\u5F27\u5217\u5224\u5B9A\n */\nbool is_parenthesis(std::string&\
    \ parenthesis) {\n    int depth = 0;\n    for (int i = 0; i < (int)(parenthesis.size());\
    \ i++) {\n        if (parenthesis[i] == '(') depth++;\n        if (parenthesis[i]\
    \ == ')') depth--;\n        if (depth < 0) return false;\n    }\n    return (depth\
    \ == 0);\n}\n"
  code: "#pragma once\n\n#include <string>\n\n/**\n * @brief \u62EC\u5F27\u5217\u5224\
    \u5B9A\n */\nbool is_parenthesis(std::string& parenthesis) {\n    int depth =\
    \ 0;\n    for (int i = 0; i < (int)(parenthesis.size()); i++) {\n        if (parenthesis[i]\
    \ == '(') depth++;\n        if (parenthesis[i] == ')') depth--;\n        if (depth\
    \ < 0) return false;\n    }\n    return (depth == 0);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: others/is_parenthesis.hpp
  requiredBy: []
  timestamp: '2024-09-04 03:57:29+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/others/is_parenthesis_1.test.cpp
documentation_of: others/is_parenthesis.hpp
layout: document
redirect_from:
- /library/others/is_parenthesis.hpp
- /library/others/is_parenthesis.hpp.html
title: "\u62EC\u5F27\u5217\u5224\u5B9A"
---
