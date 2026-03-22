#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, V; 
    cin >> N >> V;
    vector<int> A(N+1), B(N+1);
    for (int i = 1; i <= N; i++) cin >> A[i] >> B[i];

    vector<vector<int>> dp(N+1, vector<int>(V+1, 0));
    vector<vector<int>> trace(N+1, vector<int>(V+1, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= V; j++) {
            dp[i][j] = dp[i-1][j];
            trace[i][j] = 0; 
            if (j >= A[i] && dp[i-1][j - A[i]] + B[i] > dp[i][j]) {
                dp[i][j] = dp[i-1][j - A[i]] + B[i];
                trace[i][j] = 1; 
            }
        }
    }

    cout << dp[N][V] << "\n";

    
    vector<int> res;
    int j = V;
    for (int i = N; i >= 1; i--) {
        if (trace[i][j]) {
            res.push_back(i);
            j -= A[i];
        }
    }
    reverse(res.begin(), res.end());
    for (int x : res) cout << x << " ";
}
