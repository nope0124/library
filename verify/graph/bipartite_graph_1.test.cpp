#define PROBLEM "https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_ao"
#include <bits/stdc++.h>
#include "graph/graph_template.hpp"
#include "graph/bipartite_graph.hpp"
using namespace std;
typedef long long int ll;
#define rep(i, N) for(ll i = 0; i < (ll)N; i++)

int main() {
    ll N, M; cin >> N >> M;
    Graph<ll> graph(N);
    rep (i, M) {
        ll a, b; cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    BipartiteGraph<ll> bg(graph);
    if (bg.isBipartite) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
