---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tmp/power-test.cpp\"\n#include <slephy-cpp-lib/core/core.hpp>\n\
    #include <slephy-cpp-lib/math/power.hpp>\n#include <slephy-cpp-lib/modint/acl-modint.hpp>\n\
    \nusing mint = atcoder::modint998244353;\n\nint main(int argc, char *argv[]) {\n\
    \    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n    {\n        int\
    \ val = 3, exp = 5;\n        cout << power(val, exp) << endl;\n    }\n    {\n\
    \        ll val = 10, exp = 12;\n        cout << power(val, exp) << endl;\n  \
    \  }\n    {\n        ll val = 10;\n        int exp = 12;\n        cout << power(val,\
    \ exp) << endl;\n    }\n    {\n        int val = 10;\n        ll exp = 8;\n  \
    \      cout << power(val, exp) << endl;\n    }\n    {\n        mint val = 10,\
    \ exp = 12;\n        cout << power(val, exp) << endl;\n    }\n    {\n        mint\
    \ val = 10;\n        ll exp = 12;\n        cout << power(val, exp) << endl;\n\
    \    }\n    {\n        double val = 10, exp = 100;\n        cout << power(val,\
    \ exp) << endl;\n    }\n    {\n        double val = 10;\n        ll exp = 100;\n\
    \        cout << power(val, exp) << endl;\n    }\n\n    return 0;\n}\n"
  code: "#include <slephy-cpp-lib/core/core.hpp>\n#include <slephy-cpp-lib/math/power.hpp>\n\
    #include <slephy-cpp-lib/modint/acl-modint.hpp>\n\nusing mint = atcoder::modint998244353;\n\
    \nint main(int argc, char *argv[]) {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \n    {\n        int val = 3, exp = 5;\n        cout << power(val, exp) << endl;\n\
    \    }\n    {\n        ll val = 10, exp = 12;\n        cout << power(val, exp)\
    \ << endl;\n    }\n    {\n        ll val = 10;\n        int exp = 12;\n      \
    \  cout << power(val, exp) << endl;\n    }\n    {\n        int val = 10;\n   \
    \     ll exp = 8;\n        cout << power(val, exp) << endl;\n    }\n    {\n  \
    \      mint val = 10, exp = 12;\n        cout << power(val, exp) << endl;\n  \
    \  }\n    {\n        mint val = 10;\n        ll exp = 12;\n        cout << power(val,\
    \ exp) << endl;\n    }\n    {\n        double val = 10, exp = 100;\n        cout\
    \ << power(val, exp) << endl;\n    }\n    {\n        double val = 10;\n      \
    \  ll exp = 100;\n        cout << power(val, exp) << endl;\n    }\n\n    return\
    \ 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: tmp/power-test.cpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tmp/power-test.cpp
layout: document
redirect_from:
- /library/tmp/power-test.cpp
- /library/tmp/power-test.cpp.html
title: tmp/power-test.cpp
---
