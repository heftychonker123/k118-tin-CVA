#include <bits/stdc++.h>
using namespace std;
#define filename "dayngoack"
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
    ll n,k ; cin >> n >> k;
    ll dp[n+1][k+1];
    for (int i=0 ; i<=n ; i++){
        for (int j=0 ; j<=k ; j++) dp[i][j] = 0;
    }

    dp[0][0] = 1;
    for (int i=2 ; i<=n ; i+=2){
        for (int j=1 ; j<=k ; j++){
            dp[i][j] = dp[i-2][j-1] + dp[i-2][j];
        }
    }
    for (int i=0 ; i<=n ; i++){
        for (int j=0 ; j<=k ; j++) cout << dp[i][j] << " ";
        cout << "\n";
    }
    return 0;
}