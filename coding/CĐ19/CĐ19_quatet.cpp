#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n, S;
    cin >> n >> S;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++) cin >> v[i];

    ll sum = 0;
    ll res = LLONG_MAX;
    ll i = 0;

    for (ll j = 0; j < n; j++) {
        sum += v[j];

        while (sum >= S) {
            res = min(res, j - i + 1);
            sum -= v[i];
            i++;
        }
    }
    if (res == LLONG_MAX) cout << -1;
    else cout << res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
