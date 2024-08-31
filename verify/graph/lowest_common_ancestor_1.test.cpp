#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C"
#include <bits/stdc++.h>
#include "graph/graph_template.hpp"
#include "graph/lowest_common_ancestor.hpp"
using namespace std;
typedef long long int ll;
#define rep(i, N) for(ll i = 0; i < (ll)N; i++)

int main() {
    ll N; cin >> N;
    Graph<ll> graph(N);
    rep (i, N) {
        ll K; cin >> K;
        rep (j, K) {
            ll a; cin >> a;
            graph[i].push_back(a);
        }
    }

    LowestCommonAncestor<ll> lca(graph);
    ll Q; cin >> Q;
    rep (i, Q) {
        ll a, b; cin >> a >> b;
        cout << lca.lca(a, b) << endl;
    }

    return 0;
}
