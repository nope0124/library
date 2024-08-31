#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A"
#include <bits/stdc++.h>
#include "graph/graph_template.hpp"
#include "graph/tree_diameter.hpp"
using namespace std;
typedef long long int ll;
#define rep(i, N) for(ll i = 0; i < (ll)N; i++)

int main() {
    ll N; cin >> N;
    Graph<Edge<ll>> graph(N);
    rep (i, N - 1) {
        ll a, b, c; cin >> a >> b >> c;
        graph[a].push_back(Edge<ll>(b, c));
        graph[b].push_back(Edge<ll>(a, c));
    }
    cout << tree_diameter(graph) << endl;

    return 0;
}
