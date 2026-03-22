#include <bits/stdc++.h>
using namespace std;
#define filename "quacau"
#define ll long long

void IO(){
    if (fopen(filename".inp" , "r")) {
        freopen(filename".inp" , "r" , stdin);
        freopen(filename".out" , "w" , stdout);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    IO();

    ll n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    vector<ll> dp(n);
    dp[0] = a[0];
    dp[1] = a[1];
    dp[2] = a[0] + a[1] + a[2];

    for (int i = 3; i < n; i++) {
        dp[i] = min(
            dp[i-1] + a[0] + a[i],
            dp[i-2] + a[0] + 2*a[1] + a[i]
        );
    }

    cout << dp[n-1] << "\n";
    return 0;
}
