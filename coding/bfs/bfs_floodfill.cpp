#include <bits/stdc++.h>
using namespace std;
#define vect vector
#define f first
#define s second

using pii = pair<int,int>;
const int MAXN = 1001;
int area = 0 , maxArea = 0;
bool visited[MAXN][MAXN];
int n,m;

void dfs(pii start , vect<string> &board , char og){
    int x = start.f , y = start.s;
    if (x < 1 || x > n || y < 1 || y > m) return;
    if (board[x-1][y-1] != og) return;
    if (visited[x][y]) return;
    area++;
    visited[x][y] = true;
    dfs({x+1,y}, board, og);
    dfs({x-1,y}, board, og);
    dfs({x,y+1}, board, og);
    dfs({x,y-1}, board, og);
}

int main(){
    cin >> n >> m;
    vect<string> board(n);
    for (int i = 0 ; i<n ; i++) cin >> board[i];
    for (int i = 1 ; i<=n ; i++){
        for (int j = 1 ; j<=m ; j++){
            if (!visited[i][j]) {
                area = 0;
                dfs({i,j}, board, board[i-1][j-1]);
                maxArea = max(maxArea, area);
            }
        }
    }
    cout << maxArea;
}
