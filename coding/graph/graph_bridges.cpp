#include <bits/stdc++.h>
using namespace std;

#define filename "bridges"
#define ll long long
#define pb push_back
#define vect vector

vect<ll> adj[1000];
vect<ll> disc(1000, -1), low(1000, -1);
vect<pair<ll,ll>> bridges;
ll timer = 0;

void dfsBR(ll u, ll p) {
    disc[u] = low[u] = ++timer;
    for (ll n : adj[u]) {
        if (n == p) continue;
        if (disc[n] == -1) {
            dfsBR(n, u);
            low[u] = min(low[u], low[n]);
            if (low[n] > disc[u]) {
                bridges.pb({u, n});
            }
        } else {
            low[u] = min(low[u], disc[n]);
        }
    }
}

void IO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen(filename".inp", "r")) {
        freopen(filename".inp", "r", stdin);
        freopen(filename".out", "w", stdout);
    }
}

int main() {
    IO();
    ll n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll a, b; cin >> a >> b;
        adj[a-1].pb(b-1);
        adj[b-1].pb(a-1);
    }
    for (int i = 0; i < n; i++) {
        if (disc[i] == -1) dfsBR(i, -1);
    }
    cout << bridges.size() << "\n";
    return 0;
}
