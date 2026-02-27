#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vect vector

void dfs(ll root, vect<vect<ll>> &graph, vect<bool> &visited, vect<ll> &traversal) {
    visited[root] = true;
    traversal.pb(root);
    for (const ll &i : graph[root]) {
        if (!visited[i]) {
            dfs(i, graph, visited, traversal);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin >> n;
    vect<vect<ll>> neighbor(n);
    vect<bool> visited(n, false);

    ll m; cin >> m;
    while (m--) {
        ll a, b; cin >> a >> b;
        neighbor[a-1].pb(b-1);
        neighbor[b-1].pb(a-1);
    }

    vect<ll> traversal;
    dfs(0, neighbor, visited, traversal); // start from node 0 (which is node 1 in input)

    for (const ll &i : traversal) cout << i+1 << " "; // print 1-based
    return 0;
}
