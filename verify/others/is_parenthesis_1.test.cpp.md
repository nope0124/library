---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: is_parenthesis.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/typical90/tasks/typical90_b\"\
    \n#include <bits/stdc++.h>\n#include \"is_parenthesis.hpp\"\nusing namespace std;\n\
    typedef long long int ll;\n#define rep(i, N) for(ll i = 0; i < (ll)N; i++)\n#define\
    \ ALL(V)  (V).begin(), (V).end()\n\nint main() {\n    ll N; cin >> N;\n    vector<string>\
    \ ans;\n    rep (bit, (1LL<<N)) {\n        string parenthesis = \"\";\n      \
    \  rep (i, N) {\n            if (bit >> i & 1) parenthesis += '(';\n         \
    \   else parenthesis += ')';\n        }\n        if (!is_parenthesis(parenthesis))\
    \ continue;\n        ans.push_back(parenthesis);\n    }\n    sort(ALL(ans));\n\
    \    rep (i, ans.size()) cout << ans[i] << \"\\n\";\n\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: verify/others/is_parenthesis_1.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/others/is_parenthesis_1.test.cpp
layout: document
redirect_from:
- /verify/verify/others/is_parenthesis_1.test.cpp
- /verify/verify/others/is_parenthesis_1.test.cpp.html
title: verify/others/is_parenthesis_1.test.cpp
---
