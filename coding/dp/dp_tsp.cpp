#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    freopen("tsp.inp" , "r" , stdin);
    freopen("tsp.out" , "w" , stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll m, n;
    cin >> m >> n;
    vector<vector<ll>> board(m, vector<ll>(n));
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
    vector<vector<ll>> dp(m, vector<ll>(n, LLONG_MIN/2));
    vector<vector<int>> trace(m, vector<int>(n, -1));
    for(int i = 0; i < m; i++)dp[i][0] = board[i][0];
    for(int j = 1; j < n; j++){
        for(int i = 0; i < m; i++){
            int up   = (i - 1 + m) % m;
            int same = i;
            int down = (i + 1) % m;
            int best_row = same;
            if(dp[up][j-1]   > dp[best_row][j-1]) best_row = up;
            if(dp[down][j-1] > dp[best_row][j-1]) best_row = down;

            trace[i][j] = best_row;
            dp[i][j]    = dp[best_row][j-1] + board[i][j];
        }
    }
    ll best = LLONG_MIN;
    int best_row = 0;
    for(int i = 0; i < m; i++){
        if(dp[i][n-1] > best){
            best     = dp[i][n-1];
            best_row = i;
        }
    }
    vector<int> path(n);
    int cur = best_row;
    for(int j = n-1; j >= 0; j--){
        path[j] = cur + 1;       
        if(j > 0) cur = trace[cur][j];
    }
    cout << best << "\n";
    for(int j = 0; j < n; j++)
        cout << path[j] << " \n"[j == n-1];
    return 0;
}