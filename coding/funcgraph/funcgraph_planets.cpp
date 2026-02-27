#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector
void fillReverse(ll node , vect<vect<ll>> &radj , vect<ll> &ans){
    for (const ll &child : radj[node]){
        if (ans[child] == -1){
            ans[child] = ans[node]+1;
            fillReverse(child , radj , ans);
        }
    }
}
void floyd(ll node, vect<ll> &adj, vect<vect<ll>> &radj, vect<ll> &ans) {
    ll a = adj[node], b = adj[adj[node]];
    while (a != b) {
        a = adj[a];
        b = adj[adj[b]];
    }
    a = node;
    while (a != b) {
        a = adj[a];
        b = adj[b];
    }
    ll length = 1;
    b = adj[a];
    while (a != b) {
        b = adj[b];
        length++;
    }
    // mark cycle nodes
    ans[a] = length;
    ll forward = adj[a];
    while (forward != a) {
        ans[forward] = length;
        forward = adj[forward];
    }
    fillReverse(a , radj , ans);
}

void solve() {
    ll n; cin >> n;
    vect<ll> adj(n);
    vect<vect<ll>> radj(n);
    for (int i = 0; i < n; i++) {
        ll t; cin >> t;
        adj[i] = t - 1;
        radj[t - 1].push_back(i);
    }
    vect<ll> ans(n, -1);
    for (int i = 0; i < n; i++) {
        if (ans[i] == -1) floyd(i, adj, radj, ans);
    }
    for (ll x : ans) cout << x << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
