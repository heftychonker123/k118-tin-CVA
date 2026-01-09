#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, y, u;
    cin >> n >> y >> u;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++) cin >> v[i];

    unordered_map<ll, ll> freq;
    ll res = 0;
    ll l = 0;
    int distinct = 0;

    for (ll r = 0; r < n; r++) {
        if (++freq[v[r]] == 1) distinct++;  // new distinct element

        while (distinct > u) {  // shrink left if too many distinct
            if (--freq[v[l]] == 0) distinct--;
            l++;
        }

        // Now window [l..r] has at most u distinct
        // Count subarrays ending at r with at least y distinct
        if (distinct >= y) {
            res += (r - l + 1);
        }
    }

    cout << res << "\n";
    return 0;
}
