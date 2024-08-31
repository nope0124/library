#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C"
#include <bits/stdc++.h>
#include "graph/graph_template.hpp"
#include "graph/strongly_connected_component.hpp"
using namespace std;
typedef long long int ll;
#define rep(i, N) for(ll i = 0; i < (ll)N; i++)

int main() {
    ll N, M; cin >> N >> M;
    Graph<ll> graph(N), graphRev(N);
    rep (i, M) {
        ll a, b; cin >> a >> b;
        graph[a].push_back(b);
        graphRev[b].push_back(a);
    }

    StronglyConnectedComponent<ll> scc(graph, graphRev);
    ll Q; cin >> Q;
    rep (i, Q) {
        ll a, b; cin >> a >> b;
        if (scc.idxs[a] == scc.idxs[b]) cout << 1 << endl;
        else cout << 0 << endl;
    }

    return 0;
}
