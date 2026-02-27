#include <bits/stdc++.h>
using namespace std;
#define filename "flower"
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


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    IO();


    ll f,v; cin >> f >> v;
    vect<vect<ll>> board(f , vect<ll>(v));
    for (int i=0 ; i<f ; i++){
        for (int j=0 ; j<v ; j++) cin >> board[i][j];
    }
    vect<vect<ll>> dp(f+1 , vect<ll>(v+1 , -1e9));
    vect<vect<ll>> trace(f+1 , vect<ll> (v+1));
    dp[0][0] = 0;


    for (int i=1 ; i<=f ; i++){
        for (int j=1 ; j<=v ; j++){
            auto c = max_element(dp[i-1].begin() , dp[i-1].begin() + j);
            dp[i][j] = *c + board[i-1][j-1];
            trace[i][j] = c - dp[i-1].begin();
        }
    }


    ll i = f;
    auto start = max_element(dp[f].begin() , dp[f].end()) - dp[f].begin();
    cout << dp[f][start] << "\n";
    vect<ll> res;
    while (i>0){
        res.pb(start);
        start = trace[i][start];
        i--;
    }
    
    for (int i = res.size()-1 ; i>-1 ; i--) cout << res[i] << " ";
    return 0;
}