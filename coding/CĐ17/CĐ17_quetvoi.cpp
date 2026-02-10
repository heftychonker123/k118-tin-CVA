#include <bits/stdc++.h>
using namespace std;
#define filename "quetvoi"
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
int dirx[4] = {-1,1,0,0};
int diry[4] = {0,0,1,-1};
int board[1000][1000];
bool visited[1000][1000];
void dfs(ll x, ll y , ll m , ll n , ll &paint){
    if (visited[x][y]) return;
    visited[x][y] = true;
    ll cnt=0;
    for (int i=0; i<4 ; i++){
        ll nxtx = x+dirx[i] , nxty = y+diry[i];
        if (nxtx>=0 && nxtx<m && nxty>=0 && nxty<n){
            cnt += min(board[x][y] , board[nxtx][nxty]);
        }
    }
    paint += 4*board[x][y] - cnt;
    for (int i=0 ; i<4 ; i++){
        ll nxtx = x+dirx[i] , nxty = y+diry[i];
        if (nxtx>=0 && nxtx<m && nxty>=0 && nxty<n && board[nxtx][nxty]>0){
            dfs(nxtx , nxty , m , n , paint);
        }
    }
}
void solve(){
    ll m,n ; cin >> m >> n;
    for (int i=0 ; i<m ; i++){
        for (int j=0 ; j<n ; j++) cin >> board[i][j];
    }
    ll islands = 0;
    ll total = 0;
    ll res = llmin;
    ll idx = 0;
    for (int i=0 ; i<m ; i++){
        for (int j=0 ; j<n ; j++){
            if (!visited[i][j] && board[i][j]>0){
                ll paint = 0;
                islands++;
                dfs(i,j,m,n,paint);
                if (paint>res){
                    idx = islands;
                    res = paint;
                }
                total+=paint;
            }
        }
    }
    cout << islands << "\n";
    cout << total << "\n";
    cout << idx << " " << res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}