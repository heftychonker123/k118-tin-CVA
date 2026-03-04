#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin >> n;
    vector<ll> v(n);
    for (int i=0; i<n; i++) cin >> v[i];

    vector<ll> dp(n+1, 0);

    if (n >= 1) dp[1] = v[0];
    if (n >= 2) dp[2] = v[0] + v[1];

    for (int i=3; i<=n; i++){
        ll exclude = dp[i-1];
        ll includeOnce = dp[i-2] + v[i-1];
        ll includeTwice = dp[i-3] + v[i-1] + v[i-2];
        dp[i] = max({exclude, includeOnce, includeTwice});
    }

    cout << dp[n];
    return 0;
}
