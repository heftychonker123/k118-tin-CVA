#include <bits/stdc++.h>
using namespace std;
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

void solve(vect<vect<ll>> board, ll height , ll width){
    vect<vect<ll>> vec_black={
        {3,1} , 
        {0,2}
    };
    vect<vect<ll>> vec_white={
        {2,0} , 
        {1,3}
    };
    ll res_black=0;
    ll res_white=0;
    for (int i=1 ; i<height ; i++){
        for (int j=1 ; j<width ; j++){
            vect<vect<ll>> temp={
                {board[i-1][j-1] , board[i-1][j]}, 
                {board[i][j-1] , board[i][j]}
            };
            if (temp == vec_black){
                res_black++;
            }
            else if (temp == vec_white){
                res_white++;
            }
        }
    }
    cout << res_black << " " << res_white <<  "\n" ; return;
}

int main(){
    freopen("LATGACH.INP" , "r" , stdin);
    freopen("LATGACH.OUT" , "w" , stdout);
    int n,m ; cin >> n >> m;
    vect<vect<ll>> v(n , vect<ll>(m));
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cin >> v[i][j];
        }
    }
    solve(v,n,m);
    return 0;
}