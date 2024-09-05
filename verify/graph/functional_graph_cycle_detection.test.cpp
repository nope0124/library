#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2891"
#include <bits/stdc++.h>
#include "graph/graph_template.hpp"
#include "graph/functional_graph_cycle_detection.hpp"
using namespace std;
typedef long long int ll;
#define rep(i, N) for(ll i = 0; i < (ll)N; i++)

int main() {
    ll N; cin >> N;
    Graph<ll> graph(N);
    rep (i, N) {
        ll a, b; cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    FunctionalGraphCycleDetection<ll> fg(graph, false);
    ll Q; cin >> Q;
    rep (i, Q) {
        ll a, b; cin >> a >> b; a--; b--;
        if (fg.in_cycle[a] && fg.in_cycle[b]) cout << 2 << endl;
        else cout << 1 << endl;
    }

    return 0;
}
