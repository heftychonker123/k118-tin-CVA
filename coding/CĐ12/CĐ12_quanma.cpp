#include <bits/stdc++.h>
using namespace std;
#define filename "quanma"
#define ll long long
#define ld long double
#define str string
#define llmin LLONG_MIN
#define llmax LLONG_MAX
#define pb push_back
#define strri string::reverse_iterator
#define stri string::iterator
#define vect vector
#define sstream stringstream
#define umap unordered_map
struct Point {
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
};

vect<pair<ll,ll>> direction ={{-2,-1},{-2,1},{-1,2},{-1,-2},{1,2} ,{1,-2},{2,-1} , {2,1}};
int main(){
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    ll m,energy; cin >> m >> energy;
    ll n=m;

    vect<vect<ll>> board(m , vect<ll>(n));
    vect<vect<ll>> weight(m , vect<ll>(n,llmax));
    vect<vect<ll>> tenergy(m , vect<ll>(n));
    vect<vect<bool>> visited(m,vect<bool>(n,false));
    Point start,end;
    for (int i=0 ; i<m ; i++){
        for (int j=0 ; j<n ; j++){
            cin >> board[i][j];
        }
    }
    queue<Point> q;
    ll ex,ey;
    for (int i=0 ; i<m ; i++){
        for (int j=0 ; j<n ; j++){
            Point temp(i,j);
            ll temp_val = board[i][j];
            if (temp_val==3){
                q.push(temp);
                weight[i][j]=0;
                tenergy[i][j]=energy;
                while (!q.empty()){
                    Point curr = q.front() ; q.pop();
                    for (const pair<ll,ll> dir : direction){
                        ll nx = curr.x + dir.first;
                        ll ny = curr.y + dir.second;
                        ll next_energy=tenergy[curr.x][curr.y];
                        if (0 <= nx && nx <= m-1 && 0<=ny && ny<=m-1){
                            if (board[nx][ny]==1){
                                next_energy++;
                            }
                            else if (board[nx][ny]==2){
                                next_energy--;
                            }
                            tenergy[nx][ny]=max(next_energy,tenergy[nx][ny]);
                            if (next_energy>0){
                                if (weight[nx][ny] > weight[curr.x][curr.y]+1){
                                    weight[nx][ny] = weight[curr.x][curr.y]+1;
                                }
                                if (!visited[nx][ny]){
                                    q.push(Point(nx,ny));
                                    visited[nx][ny]=true;
                                }
                            }
                        }
                    }
                }
            }
            if (temp_val==4){
                ex=i ; ey=j;
            }
        }
    }
    cout << weight[ex][ey];
    return 0;
}