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


void bfs(vect<vect<ll>> &board , ll length , ll width , pair<ll,ll> root){
    vect<vect<bool>> visited(length , vect<bool>(width, false));
    vect<vect<ll>> dist(length , vect<ll>(width, llmax));

    queue<pair<ll,ll>> q;
    q.push(root);
    visited[root.first][root.second] = true;
    dist[root.first][root.second] = 0;

    while (!q.empty()){
        auto p = q.front(); q.pop();
        ll cx = p.first, cy = p.second;

        for (auto &nb : neighbor(length , width , cx , cy)){
            ll nx = nb.first, ny = nb.second;
            if (!visited[nx][ny] && board[nx][ny] == 0){
                visited[nx][ny] = true;
                dist[nx][ny] = dist[cx][cy] + 1;
                q.push({nx,ny});
            }
        }
    }
    ll res=llmax;
    for (int i=0 ; i<width ; i++){
        res = min(res, dist[0][i]);
    }
    for (int i=0 ; i<width ; i++){
        res = min(res, dist[length-1][i]);
    }
    for (int i=1 ; i<length-1 ; i++){
        res = min(res , dist[i][0]);
    }
    for (int i=1 ; i<length-1 ; i++){
        res = min(res , dist[i][width-1]);
    }
    if (res==llmax) cout << 0;
    else cout << res;
    return;
}

int main(){
    //freopen(filename".inp" , "r" , stdin);
    //freopen(filename".out" , "w" , stdout);
    int m,n ; cin >> m >> n;
    int x,y ; cin >> x >> y;
    vect<vect<ll>> v(m, vect<ll>(n));
    for (int i=0 ; i<m ; i++){
        for (int j=0 ; j<n ; j++){
            cin >> v[i][j];
        }
    }
    bfs(v,m,n,{x-1,y-1});
    return 0;
}