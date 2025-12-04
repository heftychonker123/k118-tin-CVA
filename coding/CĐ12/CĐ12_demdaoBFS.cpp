#include <bits/stdc++.h>
using namespace std;
#define filename "demdaoBFS"
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
//We do not know how it works but it works.

//Helper function to find neighbor
vect<pair<ll,ll>> neighbor(ll length , ll width , ll x , ll y){
    //Direction in the following order: right , left , up , down
    vect<pair<ll,ll>> dirs = { 
        {0,1} , {0,-1} , {1,0} , {-1,0} 
    };
    vect<pair<ll,ll>> neighbor;
    //In each direction
    for (const auto &dir : dirs){
        //Find the corresponding neighbor position
        ll nx = x + dir.first;
        ll ny = y + dir.second;
        //If neighbor pos is valid, add neighbor pos to the list of neighbor
        if (nx>=0 && nx<length && ny>=0 && ny<width){
            neighbor.pb({nx,ny});
        }
    }
    //Obviously
    return neighbor;
}
//Main function to traverse through the board and count
//connected components
void bfs(vect<vect<ll>> &board , ll length , ll width){
    vect<vect<bool>> visited(length , vect<bool>(width, false));
    queue<pair<ll,ll>> q;
    ll res = 0;

    for (int i=0 ; i<length ; i++){
        for (int j=0 ; j<width ; j++){
            if (board[i][j] == 1 && !visited[i][j]){
                q.push({i,j});
                visited[i][j] = true;
                res++;
                while (!q.empty()){
                    auto curr = q.front();
                    q.pop();
                    ll cx = curr.first;
                    ll cy = curr.second;

                    vect<pair<ll,ll>> n = neighbor(length , width , cx , cy);
                    for (const auto &nb : n){
                        ll nx = nb.first;
                        ll ny = nb.second;
                        if (board[nx][ny] == 1 && !visited[nx][ny]){
                            q.push({nx,ny});
                            visited[nx][ny]=true;
                        }
                    }
                }
            }
        }
    }
    cout << res;
}

int main(){
    //freopen(filename".inp" , "r" , stdin);
    //freopen(filename".out" , "w" , stdout);
    int m,n ; cin >> m >> n;
    vect<vect<ll>> v(m, vect<ll>(n));
    for (int i=0 ; i<m ; i++){
        for (int j=0 ; j<n ; j++){
            cin >> v[i][j];
        }
    }
    bfs(v,m,n);
    return 0;
}