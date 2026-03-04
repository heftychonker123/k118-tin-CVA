#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
};

vector<pair<int,int>> directions = {{1,0}, {0,1}, {1,1}};

int main() {
    freopen("LUOI.INP", "r", stdin);
    freopen("LUOI.OUT", "w", stdout);
    
    int m, n;
    cin >> m >> n;
    
    int dest_x, dest_y;
    cin >> dest_x >> dest_y;
    
    vector<vector<int>> grid(m, vector<int>(n));
    
    for (int i = m-1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    
    queue<Point> q;
    map<pair<int,int>, int> dist;
    map<pair<int,int>, pair<int,int>> parent;
    
    Point start(0, 0);
    q.push(start);
    dist[{0, 0}] = 0;
    parent[{0, 0}] = {-1, -1};
    
    while (!q.empty()) {
        Point curr = q.front();
        q.pop();
        
        if (curr.x == dest_x && curr.y == dest_y) break;
        
        for (auto& dir : directions) {
            int nx = curr.x + dir.first;
            int ny = curr.y + dir.second;
            
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                auto key = make_pair(nx, ny);
                if (dist.find(key) == dist.end()) {
                    dist[key] = dist[{curr.x, curr.y}] + 1;
                    parent[key] = {curr.x, curr.y};
                    q.push(Point(nx, ny));
                }
            }
        }
    }
    
    int total_steps = dist[{dest_x, dest_y}];
    int type2_count = 0;
    
    int x = dest_x, y = dest_y;
    while (parent[{x, y}].first != -1) {
        auto p = parent[{x, y}];
        int px = p.first, py = p.second;
        
        if (x - px == 1 && y - py == 1) {
            type2_count++;
        }
        
        x = px;
        y = py;
    }
    
    cout << total_steps << " " << type2_count << "\n";
    
    return 0;
}