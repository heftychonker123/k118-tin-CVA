#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    multiset<ll> s;
    ll res = 0;
    for (ll i = 0, j = 0; j < n; j++) {
        s.insert(v[j]);
        while (*s.rbegin() - *s.begin() > k) {
            s.erase(s.find(v[i]));
            i++;
        }
        res += (j - i + 1);
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
