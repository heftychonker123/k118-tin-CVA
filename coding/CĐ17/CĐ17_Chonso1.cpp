#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, K;
ll bestSum = LLONG_MIN;
ll ways = 0;
vector<vector<ll>> A;

void dfs(int row, int chosen, ll sum, vector<bool>& usedCol) {
    if (chosen == K) {
        if (sum > bestSum) {
            bestSum = sum;
            ways = 1;
        } else if (sum == bestSum) {
            ways++;
        }
        return;
    }
    if (row == N) return;

    // Không chọn gì ở hàng này
    dfs(row+1, chosen, sum, usedCol);

    // Thử chọn một ô ở hàng này
    for (int j=0; j<N; j++) {
        if (!usedCol[j]) {
            usedCol[j] = true;
            dfs(row+1, chosen+1, sum + A[row][j], usedCol);
            usedCol[j] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("CHONSO1.INP","r",stdin);
    freopen("CHONSO1.OUT","w",stdout);

    cin >> N >> K;
    A.assign(N, vector<ll>(N));
    for (int i=0;i<N;i++)
        for (int j=0;j<N;j++)
            cin >> A[i][j];

    vector<bool> usedCol(N,false);
    dfs(0,0,0,usedCol);

    cout << bestSum << " " << ways;
}
