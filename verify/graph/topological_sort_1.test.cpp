#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A"
#include <bits/stdc++.h>
#include "graph/graph_template.hpp"
#include "graph/topological_sort.hpp"
using namespace std;
typedef long long int ll;
#define rep(i, N) for(ll i = 0; i < (ll)N; i++)

int main() {
    ll N, M; cin >> N >> M;
    Graph<ll> graph(N);
    rep (i, M) {
        ll a, b; cin >> a >> b;
        graph[a].push_back(b);
    }

    auto V = topological_sort(graph);
    if ((int)(V.size()) != N) cout << 1 << endl;
    else cout << 0 << endl;

    return 0;
}
