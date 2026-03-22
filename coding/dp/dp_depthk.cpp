#include <bits/stdc++.h>
using namespace std;
#define filename "depthk"
#define ll long long

void IO() {
    if (fopen(filename ".inp", "r")) {
        freopen(filename ".inp", "r", stdin);
        freopen(filename ".out", "w", stdout);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    IO();

    ll n, m;
    cin >> n >> m;

    
    ll half = n / 2;

    
    vector<vector<vector<ll>>> dp(n + 1,
        vector<vector<ll>>(half + 1, vector<ll>(m + 1, 0)));

    dp[0][0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= half; j++) {
            for (int k = 0; k <= m; k++) {
                
                if (j > 0) {
                    int newDepth = max((ll)k, (ll)j);
                    if (newDepth <= m) {
                        dp[i][j][newDepth] += dp[i - 1][j - 1][k];
                    }
                }
                
                if (j < half) {
                    dp[i][j][k] += dp[i - 1][j + 1][k];
                }
            }
        }
    }

    
    cout << dp[n][0][m] << "\n";
    return 0;
}
