#include <bits/stdc++.h>
using namespace std;
#define filename "demdao"
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
//Flood fill with DFS
void dfs(ll x , ll y , ll m , ll n , vect<vect<ll>> &board , vect<vect<bool>> &visited){
    if ((x<0 || x>=m || y<0 || y>=n)//Invalid position
        ||visited[x][y] //Visited
        ||board[x][y]!=1//Invalid color
    ) return;
    visited[x][y]=true;
    dfs(x+1 , y , m , n , board , visited);
    dfs(x-1 , y , m , n , board , visited);
    dfs(x , y+1 , m , n , board , visited);
    dfs(x , y-1 , m , n , board , visited);
}
void solve(){
    ll m , n ;cin >> m >> n;
    vect<vect<ll>> v(m , vect<ll>(n));
    vect<vect<bool>> visited(m , vect<bool>(n,false));
    for (int i=0 ; i<m ; i++){
        for (int j=0 ; j<n ; j++) cin >> v[i][j];
    }

    ll islands = 0;
    for (int i=0 ; i<m ; i++){
        for (int j=0 ; j<n ; j++){
            if (!visited[i][j] && v[i][j] == 1){
                islands++;
                dfs(i,j,m,n,v,visited);
            }
        }
    }
    cout << islands;
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