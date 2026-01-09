#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, s;
    cin >> n >> s;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<ll> pref(n+1, 0);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i-1] + v[i-1];
    }

    ll res = 0;
    for (int i = 0; i < n; i++) {
        auto it = upper_bound(pref.begin()+i+1, pref.end(), pref[i] + s);
        if (it != pref.begin()+i+1) it--;
        res += (it - (pref.begin()+i));
    }

    cout << res << "\n";
    return 0;
}
