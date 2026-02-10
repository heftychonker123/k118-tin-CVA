#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n; 
    cin >> n;
    vector<ll> v(n);
    for (int i=0; i<n; i++) cin >> v[i];

    map<ll,ll> freq;
    for (ll x : v) freq[x] += x; 

    vector<ll> vals;
    for (auto &p : freq) vals.push_back(p.first);

    int m = vals.size();
    vector<ll> dp(m);

    dp[0] = freq[vals[0]];
    for (int i=1; i<m; i++) {
        if (vals[i] == vals[i-1] + 1) {
            ll take = freq[vals[i]] + (i>=2 ? dp[i-2] : 0);
            ll skip = dp[i-1];
            dp[i] = max(take, skip);
        } else {
            dp[i] = dp[i-1] + freq[vals[i]];
        }
    }

    cout << dp[m-1] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("chonqua.inp" , "r" , stdin);
    freopen("chonqua.out" , "w" , stdout);
    solve();
    return 0;
}