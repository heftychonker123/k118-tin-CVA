#include <bits/stdc++.h>
using namespace std;
#define filename "Chondo3"
#define ll long long
#define vect vector

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
    if (!(cin >> n >> m)) return 0;

    vect<ll> weight(n), price(n), number(n);
    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> price[i] >> number[i];
    }

    
    vect<vect<ll>> dp(n + 1, vect<ll>(m + 1, 0));
    vect<vect<int>> trace(n + 1, vect<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            
            dp[i][j] = dp[i - 1][j];
            trace[i][j] = 0;

            
            for (int k = 1; k <= number[i - 1]; k++) {
                ll total_w = k * weight[i - 1];
                if (j >= total_w) {
                    ll candidate = dp[i - 1][j - total_w] + k * price[i - 1];
                    if (candidate > dp[i][j]) {
                        dp[i][j] = candidate;
                        trace[i][j] = k;
                    }
                } else break; 
            }
        }
    }

    
    cout << dp[n][m] << "\n";

    
    vect<int> result(n);
    int curr_w = m;
    for (int i = n; i >= 1; i--) {
        result[i - 1] = trace[i][curr_w];
        curr_w -= result[i - 1] * weight[i - 1];
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << "\n";
    }

    return 0;
}