#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, q; cin >> n >> q;
    vect<ll> v(n);
    for (int i=0; i<n; i++) cin >> v[i];

    vect<ll> diff(n);
    diff[0] = v[0];
    for (int i=1; i<n; i++) diff[i] = v[i] - v[i-1];

    while (q--) {
        ll l, r, val; cin >> l >> r >> val;
        diff[l] += val;
        if (r+1 < n) diff[r+1] -= val;
    }

    vect<ll> res(n);
    res[0] = diff[0];
    for (int i=1; i<n; i++) res[i] = res[i-1] + diff[i];

    for (ll x : res) cout << x << " ";
    return 0;
}
