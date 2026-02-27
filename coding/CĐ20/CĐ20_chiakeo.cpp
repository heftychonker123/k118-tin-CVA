#include <bits/stdc++.h>
using namespace std;
#define filename "chiakeo"
#define ll long long
#define vect vector

ll dp[501][500*100 + 1];
ll n ; vect<ll> &candies;


void solve(){
    ll sum = accumulate(candies.begin() , candies.end() , 0);
    for (int i=1 ; i<=n ; i++){
        for (int j = 0 ; j <= sum ; j++){
            dp[i][j] = max(dp[i][j] , dp[i-1][j]); // Exclude
            // Include
            
        }
    }
}

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


    cin >> n; 
    candies.resize(n);
    for (int i=0 ; i<n ; i++) cin >> candies[i];


    solve();
    return 0;
}