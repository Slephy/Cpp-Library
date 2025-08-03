---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: lib/concepts/graph_concept.hpp
    title: lib/concepts/graph_concept.hpp
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
    \ 3 \"lib/concepts/graph_concept.hpp\"\ntemplate <typename T>\nconcept AdjListGraph\
    \ = std::convertible_to<typename T::value_type::value_type, int>;\n\ntemplate\
    \ <typename T>\nconcept AdjListWeightedGraph = requires(T graph) {\n    requires\
    \ AdjListGraph<T>;\n    requires requires(typename T::value_type::value_type edge)\
    \ {\n        { edge.to } -> std::convertible_to<int>;\n        edge.weight;\n\
    \    };\n};\n#line 4 \"lib/graph/scc.hpp\"\n\nnamespace slephy_scc {\nenum class\
    \ DAGType {\n    multiple,  // \u591A\u91CD\u8FBA\u3092\u6B8B\u3059\n    compress,\
    \  // \u591A\u91CD\u8FBA\u3092\u3072\u3068\u3064\u306B\u307E\u3068\u3081\u308B\
    \n};\n\ntemplate <AdjListGraph Graph> class SCC {\n    const Graph &graph;\n \
    \   Graph rgraph;\n    int n;\n    DAGType dag_type;\n    vector<int> ord;\n \
    \   vector<int> comp;\n    vector<vector<int>> scc;   // scc[i] := i\u756A\u76EE\
    \u306E\u5F37\u9023\u7D50\u6210\u5206\u306B\u542B\u307E\u308C\u308B\u9802\u70B9\
    \u306E\u96C6\u5408\n    vector<vector<int>> dag_;  // \u5F37\u9023\u7D50\u6210\
    \u5206\u3092\u9802\u70B9\u3068\u3057\u305FDAG (\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\
    \u30BD\u30FC\u30C8\u6E08\u307F)\n    vector<int> inner_edges;   // \u5F37\u9023\
    \u7D50\u6210\u5206\u5185\u306E\u8FBA\u306E\u6570\n\npublic:\n    SCC(const Graph\
    \ &graph, bool need_builing_dag = true, DAGType dag_type = DAGType::multiple)\n\
    \        : graph(graph), dag_type(dag_type), n(graph.size()), comp(graph.size(),\
    \ -1) {\n        rgraph.resize(n);\n        for(int i = 0; i < n; i++) {\n   \
    \         for(auto &to : graph[i]) {\n                rgraph[to].push_back(i);\n\
    \            }\n        }\n        build(need_builing_dag);\n    }\n\n    // \u5727\
    \u7E2E\u5F8C\u306EDAG\u306B\u304A\u3044\u3066\u9802\u70B9v\u306B\u96A3\u63A5\u3059\
    \u308B\u9802\u70B9\u3092\u8FD4\u3059\n    // @require 0 <= idx && idx < dag_.size()\n\
    \    vector<int> &dag(int v) { return dag_[v]; }\n\n    vector<vector<int>> &dag()\
    \ { return dag_; }\n\n    // \u9802\u70B9v\u304C\u542B\u307E\u308C\u308B\u5F37\
    \u9023\u7D50\u6210\u5206\u306E\u756A\u53F7\u3092\u8FD4\u3059\n    // @require\
    \ 0 <= idx && idx < n\n    int get_comp(int v) { return comp[v]; }\n\n    // idx\u756A\
    \u76EE\u306E\u5F37\u9023\u7D50\u6210\u5206\u306B\u542B\u307E\u308C\u308B\u9802\
    \u70B9\u3092\u8FD4\u3059\n    // @require 0 <= idx && idx < dag_.size()\n    vector<int>\
    \ &get_scc(int idx) { return scc[idx]; }\n\n    // \u5F37\u9023\u7D50\u6210\u5206\
    \u3054\u3068\u306B\u9802\u70B9\u3092\u307E\u3068\u3081\u305F\u3082\u306E\u3092\
    \u8FD4\u3059\n    vector<vector<int>> &get_scc() { return scc; }\n\n    // idx\u756A\
    \u76EE\u306E\u5F37\u9023\u7D50\u6210\u5206\u5185\u306B\u542B\u307E\u308C\u308B\
    \u8FBA\u306E\u672C\u6570\u3092\u8FD4\u3059\n    // @require 0 <= idx && idx <\
    \ dag_.size()\n    int get_edges_num(int idx) { return inner_edges[idx]; }\n\n\
    private:\n    void build(bool need_builing_dag) {\n        ord.resize(n, -1);\n\
    \        vector<bool> visited(n, false);\n        vector<int> vs;  // \u5E30\u308A\
    \u304C\u3051\u9806\n\n        // \u5E30\u308A\u304C\u3051\u9806\u306B\u756A\u53F7\
    \u3092\u632F\u308B\n        int iter = 0;\n        auto dfs = [&](auto &&dfs,\
    \ int now) -> void {\n            visited[now] = true;\n            for(auto &to\
    \ : graph[now]) {\n                if(!visited[to]) dfs(dfs, to);\n          \
    \  }\n            ord[now] = iter++;\n            vs.push_back(now);\n       \
    \ };\n        for(int i = 0; i < n; i++) {\n            if(!visited[i]) dfs(dfs,\
    \ i);\n        }\n\n\n        // \u9006\u8FBA\u3092\u5F35\u3063\u305F\u30B0\u30E9\
    \u30D5\u306B\u304A\u3044\u3066\u3001\u5E30\u308A\u304C\u3051\u9806\u306E\u5927\
    \u304D\u3044\u9806\u306BDFS\n        iter = 0;\n        visited.assign(n, false);\n\
    \        auto rdfs = [&](auto &&rdfs, int now, int scc_id) -> void {\n       \
    \     visited[now] = true;\n            comp[now] = scc_id;\n            scc[scc_id].push_back(now);\n\
    \            for(auto &to : rgraph[now]) {\n                if(!visited[to]) rdfs(rdfs,\
    \ to, scc_id);\n            }\n        };\n        for(int i = n - 1; i >= 0;\
    \ i--) {\n            if(!visited[vs[i]]) {\n                scc.push_back(vector<int>());\n\
    \                rdfs(rdfs, vs[i], iter++);\n            }\n        }\n\n    \
    \    // DAG\u3092\u69CB\u7BC9\n        if(need_builing_dag) construct_dag();\n\
    \    }\n\n    // dag_type == multiple then O(E + V)\n    // dag_type == compress\
    \ then O(ElogE + V)\n    void construct_dag() {\n        dag_.resize(scc.size());\n\
    \        inner_edges.resize(scc.size(), 0);\n        set<pair<int, int>> added_edge;\n\
    \        for(int i = 0; i < n; i++) {\n            for(auto &to : graph[i]) {\n\
    \                if(comp[i] == comp[to]) {\n                    inner_edges[comp[i]]++;\n\
    \                    continue;\n                }\n                else {\n  \
    \                  if(dag_type == DAGType::compress) {\n                     \
    \   if(added_edge.count({comp[i], comp[to]})) continue;\n                    \
    \    added_edge.emplace(comp[i], comp[to]);\n                        dag_[comp[i]].push_back(comp[to]);\n\
    \                    }\n                    else if(dag_type == DAGType::multiple)\
    \ {\n                        dag_[comp[i]].push_back(comp[to]);\n            \
    \        }\n                    else {\n                        cerr << \"Invalid\
    \ DAGType\" << endl;\n                        exit(1);\n                    }\n\
    \                }\n            }\n        }\n    }\n};\n};  // namespace slephy_scc\n\
    using slephy_scc::DAGType;\nusing slephy_scc::SCC;\n"
  code: "#pragma once\n#include \"../concepts/graph_concept.hpp\"\n#include \"../core/core.hpp\"\
    \n\nnamespace slephy_scc {\nenum class DAGType {\n    multiple,  // \u591A\u91CD\
    \u8FBA\u3092\u6B8B\u3059\n    compress,  // \u591A\u91CD\u8FBA\u3092\u3072\u3068\
    \u3064\u306B\u307E\u3068\u3081\u308B\n};\n\ntemplate <AdjListGraph Graph> class\
    \ SCC {\n    const Graph &graph;\n    Graph rgraph;\n    int n;\n    DAGType dag_type;\n\
    \    vector<int> ord;\n    vector<int> comp;\n    vector<vector<int>> scc;   //\
    \ scc[i] := i\u756A\u76EE\u306E\u5F37\u9023\u7D50\u6210\u5206\u306B\u542B\u307E\
    \u308C\u308B\u9802\u70B9\u306E\u96C6\u5408\n    vector<vector<int>> dag_;  //\
    \ \u5F37\u9023\u7D50\u6210\u5206\u3092\u9802\u70B9\u3068\u3057\u305FDAG (\u30C8\
    \u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\u6E08\u307F)\n    vector<int>\
    \ inner_edges;   // \u5F37\u9023\u7D50\u6210\u5206\u5185\u306E\u8FBA\u306E\u6570\
    \n\npublic:\n    SCC(const Graph &graph, bool need_builing_dag = true, DAGType\
    \ dag_type = DAGType::multiple)\n        : graph(graph), dag_type(dag_type), n(graph.size()),\
    \ comp(graph.size(), -1) {\n        rgraph.resize(n);\n        for(int i = 0;\
    \ i < n; i++) {\n            for(auto &to : graph[i]) {\n                rgraph[to].push_back(i);\n\
    \            }\n        }\n        build(need_builing_dag);\n    }\n\n    // \u5727\
    \u7E2E\u5F8C\u306EDAG\u306B\u304A\u3044\u3066\u9802\u70B9v\u306B\u96A3\u63A5\u3059\
    \u308B\u9802\u70B9\u3092\u8FD4\u3059\n    // @require 0 <= idx && idx < dag_.size()\n\
    \    vector<int> &dag(int v) { return dag_[v]; }\n\n    vector<vector<int>> &dag()\
    \ { return dag_; }\n\n    // \u9802\u70B9v\u304C\u542B\u307E\u308C\u308B\u5F37\
    \u9023\u7D50\u6210\u5206\u306E\u756A\u53F7\u3092\u8FD4\u3059\n    // @require\
    \ 0 <= idx && idx < n\n    int get_comp(int v) { return comp[v]; }\n\n    // idx\u756A\
    \u76EE\u306E\u5F37\u9023\u7D50\u6210\u5206\u306B\u542B\u307E\u308C\u308B\u9802\
    \u70B9\u3092\u8FD4\u3059\n    // @require 0 <= idx && idx < dag_.size()\n    vector<int>\
    \ &get_scc(int idx) { return scc[idx]; }\n\n    // \u5F37\u9023\u7D50\u6210\u5206\
    \u3054\u3068\u306B\u9802\u70B9\u3092\u307E\u3068\u3081\u305F\u3082\u306E\u3092\
    \u8FD4\u3059\n    vector<vector<int>> &get_scc() { return scc; }\n\n    // idx\u756A\
    \u76EE\u306E\u5F37\u9023\u7D50\u6210\u5206\u5185\u306B\u542B\u307E\u308C\u308B\
    \u8FBA\u306E\u672C\u6570\u3092\u8FD4\u3059\n    // @require 0 <= idx && idx <\
    \ dag_.size()\n    int get_edges_num(int idx) { return inner_edges[idx]; }\n\n\
    private:\n    void build(bool need_builing_dag) {\n        ord.resize(n, -1);\n\
    \        vector<bool> visited(n, false);\n        vector<int> vs;  // \u5E30\u308A\
    \u304C\u3051\u9806\n\n        // \u5E30\u308A\u304C\u3051\u9806\u306B\u756A\u53F7\
    \u3092\u632F\u308B\n        int iter = 0;\n        auto dfs = [&](auto &&dfs,\
    \ int now) -> void {\n            visited[now] = true;\n            for(auto &to\
    \ : graph[now]) {\n                if(!visited[to]) dfs(dfs, to);\n          \
    \  }\n            ord[now] = iter++;\n            vs.push_back(now);\n       \
    \ };\n        for(int i = 0; i < n; i++) {\n            if(!visited[i]) dfs(dfs,\
    \ i);\n        }\n\n\n        // \u9006\u8FBA\u3092\u5F35\u3063\u305F\u30B0\u30E9\
    \u30D5\u306B\u304A\u3044\u3066\u3001\u5E30\u308A\u304C\u3051\u9806\u306E\u5927\
    \u304D\u3044\u9806\u306BDFS\n        iter = 0;\n        visited.assign(n, false);\n\
    \        auto rdfs = [&](auto &&rdfs, int now, int scc_id) -> void {\n       \
    \     visited[now] = true;\n            comp[now] = scc_id;\n            scc[scc_id].push_back(now);\n\
    \            for(auto &to : rgraph[now]) {\n                if(!visited[to]) rdfs(rdfs,\
    \ to, scc_id);\n            }\n        };\n        for(int i = n - 1; i >= 0;\
    \ i--) {\n            if(!visited[vs[i]]) {\n                scc.push_back(vector<int>());\n\
    \                rdfs(rdfs, vs[i], iter++);\n            }\n        }\n\n    \
    \    // DAG\u3092\u69CB\u7BC9\n        if(need_builing_dag) construct_dag();\n\
    \    }\n\n    // dag_type == multiple then O(E + V)\n    // dag_type == compress\
    \ then O(ElogE + V)\n    void construct_dag() {\n        dag_.resize(scc.size());\n\
    \        inner_edges.resize(scc.size(), 0);\n        set<pair<int, int>> added_edge;\n\
    \        for(int i = 0; i < n; i++) {\n            for(auto &to : graph[i]) {\n\
    \                if(comp[i] == comp[to]) {\n                    inner_edges[comp[i]]++;\n\
    \                    continue;\n                }\n                else {\n  \
    \                  if(dag_type == DAGType::compress) {\n                     \
    \   if(added_edge.count({comp[i], comp[to]})) continue;\n                    \
    \    added_edge.emplace(comp[i], comp[to]);\n                        dag_[comp[i]].push_back(comp[to]);\n\
    \                    }\n                    else if(dag_type == DAGType::multiple)\
    \ {\n                        dag_[comp[i]].push_back(comp[to]);\n            \
    \        }\n                    else {\n                        cerr << \"Invalid\
    \ DAGType\" << endl;\n                        exit(1);\n                    }\n\
    \                }\n            }\n        }\n    }\n};\n};  // namespace slephy_scc\n\
    using slephy_scc::DAGType;\nusing slephy_scc::SCC;\n"
  dependsOn:
  - lib/concepts/graph_concept.hpp
  - lib/core/core.hpp
  isVerificationFile: false
  path: lib/graph/scc.hpp
  requiredBy: []
  timestamp: '2025-08-03 09:18:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/graph/scc.hpp
layout: document
redirect_from:
- /library/lib/graph/scc.hpp
- /library/lib/graph/scc.hpp.html
title: lib/graph/scc.hpp
---
