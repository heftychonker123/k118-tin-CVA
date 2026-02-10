#include <bits/stdc++.h>
using namespace std;
#define ll long long
int m, n, sx, sy;
bool visited[16][16];
int a[16][16];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int ans = -1;
bool check(int x, int y)
{
    return (x >= 1 && x <= m && y >= 1 && y <= n && a[x][y] == 0 && !visited[x][y]);
}

bool end(int x, int y)
{
    if (x == sx && y == sy)
        return false;
    return (x == 1 || x == m || y == 1 || y == n);
}

void back_track(int x, int y, int len)
{
    if (end(x, y))
    {
        ans = max(ans, len);
        return;
    }
    visited[x][y] = true;
    for (int k = 0; k < 4; k++)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (check(nx, ny))
        {
            back_track(nx, ny, len + 1);
        }
    }
    visited[x][y] = false;
}

void solve()
{
    cin >> m >> n >> sx >> sy;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    back_track(sx, sy, 0);
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    freopen("mecung1.inp", "r", stdin);
    freopen("mecung1.out", "w", stdout);
    solve();
    return 0;
}