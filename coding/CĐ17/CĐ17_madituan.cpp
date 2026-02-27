#include <bits/stdc++.h>
using namespace std;
#define filename "MADITUAN"
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

//Các hướng di chuyển của mã
int dx[8]={1,2,2,1,-1,-2,-2,-1}; 
int dy[8]={2,1,-1,-2,-2,-1,1,2};

bool traverse(ll x , ll y , ll n , vect<vect<bool>> &visited , vect<vect<ll>> &board , ll move=1){
    if (move == n*n){
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<n ; j++){
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        return true;
    }
    board[x][y] = move;
    visited[x][y] = true;
    for (int i=0 ; i<8 ; i++){
        if (x+dx[i] < n && x+dx[i] >=0 && y+dy[i] < n && y+dy[i] >=0 && // Valid postion
            !visited[x+dx[i]][y+dy[i]]) // 
        {

        }
    }
    visited[x][y] = false;
    board[x][y]=0;
    return false;
}
void solve(){
    ll n ; cin >> n;
    vect<vect<ll>> board(n , vect<ll>(n , 0));
    vect<vect<bool>> visited(n , vect<bool>(n , false));
    ll x,y ; cin >> x >> y;
    traverse(x-1 , y-1 , n , visited , board);
}
void IO(){
    freopen(filename".INP" , "r" , stdin);
    freopen(filename".OUT" , "w" , stdout);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    IO();
    solve();
    return 0;
}