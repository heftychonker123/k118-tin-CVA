#include <bits/stdc++.h>
using namespace std;

int dirx[4] = {-1,1,0,0};
int diry[4] = {0,0,1,-1};

int m, n, startx, starty;
int maze[20][20];
bool visited[20][20];
int longestPath = 0;

void dfs(int x, int y, int steps) {
    if (x < 0 || x >= m || y < 0 || y >= n) {
        longestPath = max(longestPath, steps-1);
        return;
    }

    if (maze[x][y] == 1 || visited[x][y]) return;

    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dirx[i], ny = y + diry[i];
        dfs(nx, ny, steps + 1);
    }

    visited[x][y] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("MECUNG1.INP", "r", stdin);
    freopen("MECUNG1.OUT", "w", stdout);

    cin >> m >> n >> startx >> starty;
    startx--; starty--; 

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }

    dfs(startx, starty, 0);

    cout << longestPath << "\n";
    return 0;
}
