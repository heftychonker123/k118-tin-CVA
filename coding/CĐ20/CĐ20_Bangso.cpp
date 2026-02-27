#include <bits/stdc++.h>
using namespace std;
#define filename "Bangso"
#define ll long long
#define pb push_back
#define vect vector

void IO(){
    if (fopen(filename".inp" , "r"))
    {
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    }
}

struct Tracer{
    ll x,y,val;
    // Initialization
    Tracer() : x(-1) , y(-1) , val(0) {};
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    IO();
    ll n ; cin >> n;
    vect<vect<ll>> board(n , vect<ll>(n));
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++) cin >> board[i][j];
    }
    vect<vect<Tracer>> dp(n+1 , vect<Tracer> (n+1 , Tracer()));

    for (int i=1 ; i<=n ; i++){
        for (int j=1 ; j<=n ; j++){
            ll right = LLONG_MAX;
            ll down = LLONG_MAX;
            if (j>1) right = dp[i][j-1].val;
            if (i>1) down = dp[i-1][j].val;
            if (i==1 && j==1){
                dp[i][j].val = board[i-1][j-1];
                continue;
            }
            if (right<=down){
                dp[i][j].x = i;
                dp[i][j].y = j-1;
                dp[i][j].val = right + board[i-1][j-1];
            }
            else{
                dp[i][j].x = i-1;
                dp[i][j].y = j;
                dp[i][j].val =  down + board[i-1][j-1];
            }
        }
    }
    cout << dp[n][n].val << "\n";
    ll row = n , col = n;
    vect<pair<ll,ll>> res;
    while(row != -1 && col != -1) {
        res.pb({row,col});
        ll newRow = dp[row][col].x;
        ll newCol = dp[row][col].y;
        row = newRow;
        col = newCol;
    }
    for (int i = res.size() - 1 ; i>=0 ; i--){
        cout << res[i].first << "," << res[i].second << "\n";
    }
    return 0;
}