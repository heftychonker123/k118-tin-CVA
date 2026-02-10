#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("running.inp" , "r" , stdin);
    freopen("running.out" , "w" , stdout);

    ll n, M;
    cin >> n >> M;
    vector<ll> d(n);
    for (int i = 0; i < n; i++) cin >> d[i];

    vector<vector<ll>> dp(n+1, vector<ll>(M+1, -1));
    dp[0][0] = 0;

    for (int idx = 0; idx < n; idx++){
        for (int tire = 0; tire <= M; tire++){
            if (dp[idx][tire] == -1) continue;

            // Chạy
            if (tire < M){
                dp[idx+1][tire+1] = max(dp[idx+1][tire+1], dp[idx][tire] + d[idx]);
            }

            // Nghỉ
            if (tire > 0){
                dp[idx+1][tire-1] = max(dp[idx+1][tire-1], dp[idx][tire]);
            } else {
                dp[idx+1][0] = max(dp[idx+1][0], dp[idx][tire]);
            }
        }
    }

    cout << dp[n][0] << "\n";
    return 0;
}
