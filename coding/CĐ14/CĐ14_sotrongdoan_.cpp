#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n; cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    ll q; cin >> q;
    while (q--) {
        ll l, r; cin >> l >> r;
        auto lit = lower_bound(v.begin(), v.end(), l);
        auto rit = upper_bound(v.begin(), v.end(), r);
        cout << (rit - lit) << "\n";
    }
    return 0;
}
