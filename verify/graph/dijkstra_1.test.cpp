#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"
#include <bits/stdc++.h>
#include "graph/graph_template.hpp"
#include "graph/dijkstra.hpp"
using namespace std;
typedef long long int ll;
#define rep(i, N) for(ll i = 0; i < (ll)N; i++)
const ll INF = 1e17;

int main() {
    ll N, M, start; cin >> N >> M >> start;
    Graph<Edge<ll>> graph(N);
    rep (i, M) {
        ll a, b, c; cin >> a >> b >> c;
        graph[a].push_back(Edge<ll>(b, c));
    }

    Dijkstra<ll> ds(graph, start, INF);
    rep (i, N) {
        if (ds.dist[i] == INF) cout << "INF" << endl;
        else cout << ds.dist[i] << endl;
    }

    return 0;
}
