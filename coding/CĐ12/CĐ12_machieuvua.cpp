#include <bits/stdc++.h>
using namespace std;
#define filename "machieuvua"
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
//We don't know how it works but it works

//Helper structure because i am lazy
struct cord {
    int x, y;
    cord(int x, int y) : x(x), y(y) {}
};

// BFS with a start and end
void bfs(vect<vect<ll>> board , ll length , ll width , cord start , cord end){
    vect<vect<bool>> visited(length , vect<bool>(width , false));
    vect<vect<ll>> weight(length , vect<ll>(width , llmax));
    weight[start.x][start.y]=0;
    queue<cord> q;
    q.push(start);
    vect<pair<ll,ll>> direction ={{-2,-1},{-2,1},{-1,2},{-1,-2},{1,2} ,{1,-2},{2,-1} , {2,1}};
    while (!q.empty()){
        cord curr = q.front() ; q.pop();
        for (const pair<ll,ll> &dir : direction){
            ll nx = curr.x + dir.first;
            ll ny = curr.y + dir.second;
            // If neighbor position valid
            if (nx >= 0 && ny >= 0 && nx < length && ny < width){
                if (!visited[nx][ny]){
                    cord neighbor(nx,ny);
                    q.push(neighbor);
                    visited[nx][ny]=true;
                }
                weight[nx][ny] = min(weight[nx][ny],weight[curr.x][curr.y]+1);
            }
        }
    }
    if (weight[end.x][end.y]==llmax) cout << 0;
    else cout << weight[end.x][end.y];
    cout << "\n";
    return;
}

int main(){
    //freopen(filename".inp" , "r" , stdin);
    //freopen(filename".out" , "w" , stdout);
    int n; cin >> n;
    vect<vect<ll>> board(n , vect<ll>(n,0));
    ll m,z ; cin >> m >> z;
    cord start(m-1,z-1);
    ll x,y ; cin >> x >> y;
    cord end(x-1,y-1);
    bfs(board , n , n , start , end);
}