#include <bits/stdc++.h>
using namespace std;
#define filename "NUOCDONG"
#define ll long long
#define llmin LLONG_MIN
#define llmax LLONG_MAX
#define vect vector
int dx[4] = {0 , 0 , -1 , 1};
int dy[4] = {-1 , 1 , 0 , 0};
bool fillable(ll m , ll n , vect<vect<ll>> &v , vect<vect<bool>> &visited ,
              ll x , ll y , ll limit , ll &area){
    visited[x][y] = true;  // mark current cell immediately
    if (v[x][y] <= limit) area += limit - v[x][y];

    bool enclosed = true;
    for (int i=0 ; i<4 ; i++){
        ll nx = x+dx[i], ny = y+dy[i];
        if (nx<0 || nx>=m || ny<0 || ny>=n){
            enclosed = false; // leak to boundary
        } else {
            if (v[nx][ny] <= limit && !visited[nx][ny]){
                if (!fillable(m,n,v,visited,nx,ny,limit,area)){
                    enclosed = false;
                }
            }
        }
    }
    return enclosed;
}

void solve(){
    ll m , n ; cin >> m >>n;
    vect<vect<ll>> v(m, vect<ll>(n));
    ll minHeight=llmax , maxHeight=llmin;
    for (int i=0 ; i<m ; i++){
        for (int j=0 ; j<n ; j++){
            cin >> v[i][j];
            minHeight = min(v[i][j] , minHeight);
            maxHeight = max(v[i][j] , maxHeight);
        }
    }
    ll res = llmin;
    for (ll limit = minHeight ; limit <= maxHeight ; limit++){
        vect<vect<bool>> visited(m , vect<bool>(n));
        for (int i=0 ; i<m ; i++){
            for (int j=0 ; j<n ; j++){
                if (!visited[i][j]){
                    ll area = 0;
                    if (fillable(m , n , v , visited , i , j , limit , area)){
                        res = max(res , area);
                    }
                }
            }
        }
    }
    cout << res << "\n";
}
void IO(){
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //IO();
    solve();
    return 0;
}