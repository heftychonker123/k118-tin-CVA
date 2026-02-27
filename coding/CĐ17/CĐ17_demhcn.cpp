#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
int board[MAXN][MAXN];
bool visited[MAXN][MAXN];

const vector<pair<int,int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};

void dfs(int x, int y, int m, int n,
        long long &area, int &maxX, int &minX, int &maxY, int &minY) {
    
    
    
    if (visited[x][y]) return;
    visited[x][y] = true;
    area++;

    maxX = max(maxX, x);
    minX = min(minX, x);
    maxY = max(maxY, y);
    minY = min(minY, y);

    for (auto [dx, dy] : dirs) {
        int nx = x + dx, ny = y + dy;
        if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
        if (board[nx][ny] == 1 && !visited[nx][ny]) {
            dfs(nx, ny, m, n, area, maxX, minX, maxY, minY);
        }
    }
}

void solve() {
    int m, n;
    cin >> m; n=m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    long long rects = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && board[i][j] == 1) {
                long long area = 0;
                int maxX = INT_MIN, minX = INT_MAX;
                int maxY = INT_MIN, minY = INT_MAX;

                dfs(i, j, m, n, area, maxX, minX, maxY, minY);

                if (area == (maxX - minX + 1) * (maxY - minY + 1)) {
                    rects++;
                }
            }
        }
    }

    cout << rects << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
