#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n, k; cin >> n >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    ll res = 0;
    for (int i = 0; i < n; i++) {
        ll t = v[i];
        auto lowit = lower_bound(v.begin() + i + 1, v.end(), k - t);
        auto upit = upper_bound(v.begin() + i + 1, v.end(), k - t);
        res += (upit - lowit);
    }
    cout << res;
    return 0;
}
