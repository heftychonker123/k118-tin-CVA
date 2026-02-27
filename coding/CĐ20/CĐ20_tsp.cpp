#include <bits/stdc++.h>
using namespace std;
#define filename "tsp"
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

void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen(filename".inp" , "r"))
    {
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    }
}

void tracing(ll i , ll j , vect<vect<ll>> &dp , ll m , vect<vect<ll>> &trace , vect<vect<ll>> board){
    ll up = dp[(i-1+m)%m][j-1];
    ll side = dp[(i)%m][j-1];
    ll down = dp[(i+1)%m][j-1];
    if (up == max({up,side,down})){
        trace[i][j] = (i-1+m)%m;
        dp[i][j] = up + board[i][j];
    }
    else if (side == max({up,side,down})){
        trace[i][j] = (i)%m;
        dp[i][j] = side + board[i][j];
    }
    else if (down == max({up,side,down})){
        trace[i][j] = (i+1)%m;
        dp[i][j] = down + board[i][j];
    }
}
int main(){
    fastIO();


    ll m , n; cin >> m >> n;
    vect<vect<ll>> board(m , vect<ll>(n)); for (int i=0 ; i<m ; i++) for (int j=0 ; j<n ; j++) cin >> board[i][j];

    vect<vect<ll>> dp(m , vect<ll>(n , -1e9));
    vect<vect<ll>> trace(m , vect<ll>(n));

    for (int i = 0 ; i<m ; i++) dp[i][0] = board[i][0];
    for (int i=0 ; i<m ; i++){
        for (int j=1 ; j<n ; j++){
            tracing(i,j,dp,m,trace,board);
        }
    }
    ll max = llmin ; ll maxPos = 0;
    for (int i=0 ; i<m ; i++){
        if (dp[i][n-1] > max){
            maxPos = i;
            max = dp[i][n-1];
        }
    }
    cout << max << "\n";
    ll i = n-1;
    vect<ll> res;
    while (i>-1){
        res.pb(maxPos+1);
        maxPos = trace[maxPos][i];
        i--;
    }
    for (int i = res.size()-1 ; i>-1 ; i--) cout << res[i] << " ";
    return 0;
}