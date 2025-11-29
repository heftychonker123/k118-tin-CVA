#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("QUANMA.INP", "r", stdin);
    freopen("QUANMA.OUT", "w", stdout);
    int m, n;
    cin >> m >> n;
    vector<vector<int>> board(m + 1, vector<int>(n + 1));
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> board[i][j];
        }
    }
    for (int i = 1; i <= m; ++i){
        for (int j = 1; j <= n; ++j){
            dp[i][j] = board[i][j];
        }
    }

    int dx[] = {1,2}; // direction of the knight in the x axis
    int dy[] = {2, -2, 1, -1}; // direction of the knight in the y axis

    for (int i = 1; i <= m; ++i){
        for (int j = 1; j <= n; ++j){
            for (int k = 0; k < 4; ++k) {
                int ni = i + dx[k], nj = j + dy[k];
                if (ni <= m && nj >= 1 && nj <= n){
                    dp[ni][nj] = max(dp[ni][nj], dp[i][j] + board[ni][nj]);
                }
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= m; ++i){
        for (int j = 1; j <= n; ++j){
            res = max(res, dp[i][j]);
        }
    }
    cout << res << endl;
}