#include <bits/stdc++.h>
using namespace std;
#define filename "bai4"
#define ll long long
#define vect vector


ll n,m;
// 1-based indexed coordinates
ll x,y,z,g;
pair<ll,ll> dir[4] = {{-1,0} , {1,0} , {0 , -1} , {0 , 1}};


void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen(filename".inp" , "r"))
    {
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    }
}


bool valid(ll x , ll y){
    return (0<=x && x<n && 0<=y && y<m);
}

void solve(vect<vect<ll>> v){
    vect<vect<ll>> weight(n , vect<ll>(m , 1e9));
    map<ll,bool> used;
    map<ll,vect<pair<ll,ll>>> t;
    vect<vect<ll>> visited(n , vect<ll>(m , false));
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            used[v[i][j]] = false;
            t[v[i][j]].push_back({i,j});
        }
    }

    queue<pair<ll,ll>> q;
    q.push({x-1,y-1});
    visited[x-1][y-1] = true;
    weight[x-1][y-1] = 0;
    while (!q.empty()){
        auto [x,y] = q.front() ; q.pop();
        //Hopping
        if (!used[v[x][y]]){
            for (const auto [i , j ] : t[v[x][y]]){
                weight[i][j] = min(weight[i][j] , weight[x][y] + 1);
                if (!visited[i][j]){
                    visited[i][j] = true;
                    q.push({i,j});
                }
            }
        }
        for (const auto [dx , dy] : (vect<pair<ll,ll>>){{-1,0} , {1,0} , {0,-1} , {0,1}}){
            ll nxtx = x + dx , nxty = y + dy;
            if (0<=nxtx && nxtx < n && 0<=nxty && nxty < m && v[nxtx][nxty]!=0){
                weight[nxtx][nxty] = min(weight[nxtx][nxty] , weight[x][y] + 1);
                if (!visited[nxtx][nxty] ){
                    visited[nxtx][nxty] = true;
                    q.push({nxtx,nxty});
                }
            }
        }
    }
    cout << weight[z-1][g-1];
}


int main(){
    fastIO();
    cin >> n >> m;
    cin >> x >> y >> z >> g;

    vect<vect<ll>> v(n , vect<ll>(m));
    for (int i=0 ; i<n ; i++) for (int j=0 ; j<m ; j++) cin >> v[i][j];

    solve(v);
    return 0;
}