#include <bits/stdc++.h>
using namespace std;

#define filename "khop"
#define ll long long
#define pb push_back
#define vect vector

vect<ll> adj[1000];
vect<ll> disc(1000, -1), low(1000, -1);
vect<bool> isAP(1000, false);
ll timer = 0;

void dfsAP(ll u, ll p) {
    disc[u] = low[u] = ++timer;
    ll children = 0;
    for (ll n : adj[u]) {
        if (n == p) continue;
        if (disc[n] == -1) {
            children++;
            dfsAP(n, u);
            low[u] = min(low[u], low[n]);
            if (p != -1 && low[n] >= disc[u]) {
                isAP[u] = true;
            }
        } else {
            low[u] = min(low[u], disc[n]);
        }
    }
    if (p == -1 && children > 1) {
        isAP[u] = true;
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
        if (disc[i] == -1) dfsAP(i, -1);
    }
    ll apCount = 0;
    for (int i = 0; i < n; i++) {
        if (isAP[i]) {
            apCount++;
        }
    }
    cout << apCount << "\n";
    return 0;
}
