#include <bits/stdc++.h>
using namespace std;
#define filename "min_knight"
#define ll long long
#define llmax LLONG_MAX
#define vect vector

vect<pair<ll,ll>> neighbors = {
    {-2,-1}, {-2,1},
    {-1,-2}, {-1,2},
    {1,-2},  {1,2},
    {2,-1},  {2,1}
};

struct point {
    ll x,y;
    point(ll x, ll y) : x(x), y(y) {}
};

vect<vect<ll>> bfs(point start, ll m, ll n) {
    vect<vect<bool>> visited(m, vect<bool>(n, false));
    vect<vect<ll>> dist(m, vect<ll>(n, llmax));
    queue<point> q;
    q.push(start);
    visited[start.x][start.y] = true;
    dist[start.x][start.y] = 0;

    while (!q.empty()) {
        auto [x,y] = q.front(); q.pop();
        for (auto [dx,dy] : neighbors) {
            ll nx = x+dx, ny = y+dy;
            if (0<=nx && nx<m && 0<=ny && ny<n) {
                if (dist[nx][ny] > dist[x][y] + 1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    if (!visited[nx][ny]) {
                        visited[nx][ny] = true;
                        q.push(point(nx,ny));
                    }
                }
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 4D vector: weight[startx][starty][endx][endy]
    vect<vect<vect<vect<ll>>>> weight(
        8, vect<vect<vect<ll>>>(
            8, vect<vect<ll>>(
                8, vect<ll>(8, llmax)
            )
        )
    );

    // Precompute BFS from each square
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            auto dis = bfs(point(i,j), 8, 8);
            for (int x=0; x<8; x++) {
                for (int y=0; y<8; y++) {
                    weight[i][j][x][y] = dis[x][y];
                }
            }
        }
    }

    ll t; cin >> t;
    while (t--) {
        ll x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
        cout << weight[x1][y1][x2][y2] << "\n";
    }
    return 0;
}
