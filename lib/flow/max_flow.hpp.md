---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: lib/core/core.hpp
    title: lib/core/core.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/core/core.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing ull = unsigned long long;\nconst int INF\
    \ = (int)1e9 + 1001010;\nconst ll llINF = (long long)4e18 + 22000020;\nconst string\
    \ endn = \"\\n\";\ntemplate <class T> inline auto vector2(size_t i, size_t j,\
    \ const T &init = T()) {\n    return vector(i, vector<T>(j, init));\n}\nconst\
    \ string ELM_SEP = \" \", VEC_SEP = endn;\ntemplate <class T> istream &operator>>(istream\
    \ &i, vector<T> &A) {\n    for(auto &I : A) i >> I;\n    return i;\n}\ntemplate\
    \ <class T> ostream &operator<<(ostream &o, const vector<T> &A) {\n    int sz\
    \ = A.size();\n    for(const auto &I : A) o << I << (--sz ? ELM_SEP : \"\");\n\
    \    return o;\n}\ntemplate <class T> ostream &operator<<(ostream &o, const vector<vector<T>>\
    \ &A) {\n    int sz = A.size();\n    for(const auto &I : A) o << I << (--sz ?\
    \ VEC_SEP : \"\");\n    return o;\n}\ntemplate <class T> vector<T> &operator++(vector<T>\
    \ &A, int) {\n    for(auto &I : A) I++;\n    return A;\n}\ntemplate <class T>\
    \ vector<T> &operator--(vector<T> &A, int) {\n    for(auto &I : A) I--;\n    return\
    \ A;\n}\ntemplate <class T, class U> bool chmax(T &a, const U &b) { return ((a\
    \ < b) ? (a = b, true) : false); }\ntemplate <class T, class U> bool chmin(T &a,\
    \ const U &b) { return ((a > b) ? (a = b, true) : false); }\nll floor_div(ll a,\
    \ ll b) {\n    if(b < 0) a = -a, b = -b;\n    return (a >= 0) ? a / b : (a + 1)\
    \ / b - 1;\n}\nll ceil_div(ll a, ll b) {\n    if(b < 0) a = -a, b = -b;\n    return\
    \ (a > 0) ? (a - 1) / b + 1 : a / b;\n}\nbool check_bit(ull val, ull digit) {\
    \ return (val >> digit) & 1; }\n#ifdef DEBUG\n#include <cpp-dump/cpp-dump.hpp>\n\
    #define dump(...) cpp_dump(__VA_ARGS__)\nnamespace cp = cpp_dump;\nstruct InitCppDump\
    \ {\n    InitCppDump() {\n        if(!isatty(fileno(stderr))) CPP_DUMP_SET_OPTION(es_style,\
    \ cpp_dump::types::es_style_t::no_es);\n        CPP_DUMP_SET_OPTION(log_label_func,\
    \ cp::log_label::line());\n        CPP_DUMP_SET_OPTION(max_iteration_count, 30);\n\
    \    }\n} init_cpp_dump;\n#else\n#define dump(...)\n#endif\n// ====================\
    \ \u3053\u3053\u307E\u3067\u30C6\u30F3\u30D7\u30EC ====================\n#line\
    \ 3 \"lib/flow/max_flow.hpp\"\n// \u53C2\u8003 AtCoder Library\n// == ACL\u304B\
    \u3089\u306E\u5909\u66F4\u70B9 ==\n// internal::queue \u3092 std::queue \u306B\
    \u7F6E\u63DB\ntemplate <class Cap> struct mf_graph {\npublic:\n    mf_graph()\
    \ : _n(0) {}\n    mf_graph(int n) : _n(n), g(n) {}\n    int add_edge(int from,\
    \ int to, Cap cap) {\n        assert(0 <= from && from < _n);\n        assert(0\
    \ <= to && to < _n);\n        assert(0 <= cap);\n        int m = int(pos.size());\n\
    \        pos.push_back({from, int(g[from].size())});\n        g[from].push_back(_edge{to,\
    \ int(g[to].size()), cap});\n        g[to].push_back(_edge{from, int(g[from].size())\
    \ - 1, 0});\n        return m;\n    }\n\n    struct edge {\n        int from,\
    \ to;\n        Cap cap, flow;\n    };\n\n    edge get_edge(int i) {\n        int\
    \ m = int(pos.size());\n        assert(0 <= i && i < m);\n        auto _e = g[pos[i].first][pos[i].second];\n\
    \        auto _re = g[_e.to][_e.rev];\n        return edge{pos[i].first, _e.to,\
    \ _e.cap + _re.cap, _re.cap};\n    }\n\n    vector<edge> edges() {\n        int\
    \ m = int(pos.size());\n        vector<edge> result;\n        for(int i = 0; i\
    \ < m; i++) {\n            result.push_back(get_edge(i));\n        }\n       \
    \ return result;\n    }\n\n    void change_edge(int i, Cap new_cap, Cap new_flow)\
    \ {\n        int m = int(pos.size());\n        assert(0 <= i && i < m);\n    \
    \    assert(0 <= new_flow && new_flow <= new_cap);\n        auto& _e = g[pos[i].first][pos[i].second];\n\
    \        auto& _re = g[_e.to][_e.rev];\n        _e.cap = new_cap - new_flow;\n\
    \        _re.cap = new_flow;\n    }\n\n    Cap flow(int s, int t) { return flow(s,\
    \ t, numeric_limits<Cap>::max()); }\n\n    Cap flow(int s, int t, Cap flow_limit)\
    \ {\n        assert(0 <= s && s < _n);\n        assert(0 <= t && t < _n);\n  \
    \      vector<int> level(_n), iter(_n);\n        auto bfs = [&]() {\n        \
    \    queue<int> que;\n            fill(level.begin(), level.end(), -1);\n    \
    \        level[s] = 0;\n            que.push(s);\n            while(!que.empty())\
    \ {\n                int v = que.front();\n                que.pop();\n      \
    \          for(auto e : g[v]) {\n                    if(e.cap == 0 || level[e.to]\
    \ >= 0) continue;\n                    level[e.to] = level[v] + 1;\n         \
    \           if(e.to == t) return;\n                    que.push(e.to);\n     \
    \           }\n            }\n        };\n        auto dfs = [&](auto self, int\
    \ v, Cap up) {\n            if(v == s) return up;\n            Cap res = 0;\n\
    \            int level_v = level[v];\n            for(int& i = iter[v]; i < int(g[v].size());\
    \ i++) {\n                _edge& e = g[v][i];\n                if(level_v <= level[e.to]\
    \ || g[e.to][e.rev].cap == 0) continue;\n                Cap d = self(self, e.to,\
    \ min(up - res, g[e.to][e.rev].cap));\n                if(d <= 0) continue;\n\
    \                g[v][i].cap += d;\n                g[e.to][e.rev].cap -= d;\n\
    \                res += d;\n                if(res == up) break;\n           \
    \ }\n            return res;\n        };\n\n        Cap flow = 0;\n        while(flow\
    \ < flow_limit) {\n            bfs();\n            if(level[t] == -1) break;\n\
    \            fill(iter.begin(), iter.end(), 0);\n            while(flow < flow_limit)\
    \ {\n                Cap f = dfs(dfs, t, flow_limit - flow);\n               \
    \ if(!f) break;\n                flow += f;\n            }\n        }\n      \
    \  return flow;\n    }\n\n    vector<bool> min_cut(int s) {\n        vector<bool>\
    \ visited(_n);\n        queue<int> que;\n        que.push(s);\n        while(!que.empty())\
    \ {\n            int p = que.front();\n            que.pop();\n            visited[p]\
    \ = true;\n            for(auto e : g[p]) {\n                if(e.cap && !visited[e.to])\
    \ {\n                    visited[e.to] = true;\n                    que.push(e.to);\n\
    \                }\n            }\n        }\n        return visited;\n    }\n\
    \nprivate:\n    int _n;\n    struct _edge {\n        int to, rev;\n        Cap\
    \ cap;\n    };\n    vector<pair<int, int>> pos;\n    vector<vector<_edge>> g;\n\
    };\n"
  code: "#pragma once\n#include \"../core/core.hpp\"\n// \u53C2\u8003 AtCoder Library\n\
    // == ACL\u304B\u3089\u306E\u5909\u66F4\u70B9 ==\n// internal::queue \u3092 std::queue\
    \ \u306B\u7F6E\u63DB\ntemplate <class Cap> struct mf_graph {\npublic:\n    mf_graph()\
    \ : _n(0) {}\n    mf_graph(int n) : _n(n), g(n) {}\n    int add_edge(int from,\
    \ int to, Cap cap) {\n        assert(0 <= from && from < _n);\n        assert(0\
    \ <= to && to < _n);\n        assert(0 <= cap);\n        int m = int(pos.size());\n\
    \        pos.push_back({from, int(g[from].size())});\n        g[from].push_back(_edge{to,\
    \ int(g[to].size()), cap});\n        g[to].push_back(_edge{from, int(g[from].size())\
    \ - 1, 0});\n        return m;\n    }\n\n    struct edge {\n        int from,\
    \ to;\n        Cap cap, flow;\n    };\n\n    edge get_edge(int i) {\n        int\
    \ m = int(pos.size());\n        assert(0 <= i && i < m);\n        auto _e = g[pos[i].first][pos[i].second];\n\
    \        auto _re = g[_e.to][_e.rev];\n        return edge{pos[i].first, _e.to,\
    \ _e.cap + _re.cap, _re.cap};\n    }\n\n    vector<edge> edges() {\n        int\
    \ m = int(pos.size());\n        vector<edge> result;\n        for(int i = 0; i\
    \ < m; i++) {\n            result.push_back(get_edge(i));\n        }\n       \
    \ return result;\n    }\n\n    void change_edge(int i, Cap new_cap, Cap new_flow)\
    \ {\n        int m = int(pos.size());\n        assert(0 <= i && i < m);\n    \
    \    assert(0 <= new_flow && new_flow <= new_cap);\n        auto& _e = g[pos[i].first][pos[i].second];\n\
    \        auto& _re = g[_e.to][_e.rev];\n        _e.cap = new_cap - new_flow;\n\
    \        _re.cap = new_flow;\n    }\n\n    Cap flow(int s, int t) { return flow(s,\
    \ t, numeric_limits<Cap>::max()); }\n\n    Cap flow(int s, int t, Cap flow_limit)\
    \ {\n        assert(0 <= s && s < _n);\n        assert(0 <= t && t < _n);\n  \
    \      vector<int> level(_n), iter(_n);\n        auto bfs = [&]() {\n        \
    \    queue<int> que;\n            fill(level.begin(), level.end(), -1);\n    \
    \        level[s] = 0;\n            que.push(s);\n            while(!que.empty())\
    \ {\n                int v = que.front();\n                que.pop();\n      \
    \          for(auto e : g[v]) {\n                    if(e.cap == 0 || level[e.to]\
    \ >= 0) continue;\n                    level[e.to] = level[v] + 1;\n         \
    \           if(e.to == t) return;\n                    que.push(e.to);\n     \
    \           }\n            }\n        };\n        auto dfs = [&](auto self, int\
    \ v, Cap up) {\n            if(v == s) return up;\n            Cap res = 0;\n\
    \            int level_v = level[v];\n            for(int& i = iter[v]; i < int(g[v].size());\
    \ i++) {\n                _edge& e = g[v][i];\n                if(level_v <= level[e.to]\
    \ || g[e.to][e.rev].cap == 0) continue;\n                Cap d = self(self, e.to,\
    \ min(up - res, g[e.to][e.rev].cap));\n                if(d <= 0) continue;\n\
    \                g[v][i].cap += d;\n                g[e.to][e.rev].cap -= d;\n\
    \                res += d;\n                if(res == up) break;\n           \
    \ }\n            return res;\n        };\n\n        Cap flow = 0;\n        while(flow\
    \ < flow_limit) {\n            bfs();\n            if(level[t] == -1) break;\n\
    \            fill(iter.begin(), iter.end(), 0);\n            while(flow < flow_limit)\
    \ {\n                Cap f = dfs(dfs, t, flow_limit - flow);\n               \
    \ if(!f) break;\n                flow += f;\n            }\n        }\n      \
    \  return flow;\n    }\n\n    vector<bool> min_cut(int s) {\n        vector<bool>\
    \ visited(_n);\n        queue<int> que;\n        que.push(s);\n        while(!que.empty())\
    \ {\n            int p = que.front();\n            que.pop();\n            visited[p]\
    \ = true;\n            for(auto e : g[p]) {\n                if(e.cap && !visited[e.to])\
    \ {\n                    visited[e.to] = true;\n                    que.push(e.to);\n\
    \                }\n            }\n        }\n        return visited;\n    }\n\
    \nprivate:\n    int _n;\n    struct _edge {\n        int to, rev;\n        Cap\
    \ cap;\n    };\n    vector<pair<int, int>> pos;\n    vector<vector<_edge>> g;\n\
    };\n"
  dependsOn:
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/flow/max_flow.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/flow/max_flow.hpp
layout: document
redirect_from:
- /library/lib/flow/max_flow.hpp
- /library/lib/flow/max_flow.hpp.html
title: lib/flow/max_flow.hpp
---
