#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int sum = accumulate(v.begin(), v.end(), 0);
    vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));

    dp[0][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= v[i-1]) dp[i][j] = dp[i][j] || dp[i-1][j-v[i-1]];
        }
    }
    vector<ll> res;
    for (int j = 1; j <= sum; j++) {
        if (dp[n][j]) res.push_back(j);
    }
    cout << res.size() << "\n"; for (const ll &i : res) cout << i << "\n";
}
