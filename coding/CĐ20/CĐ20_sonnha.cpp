#include <bits/stdc++.h>
using namespace std;
#define filename "sonnha"
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
void solve(){
    ll n ; cin >> n;
    ll a,b,c;
    vect<vect<ll>> dp(n+1 , vect<ll>(3 , 0));

    for (int i=1 ; i<=n ; i++){
        cin >> a >> b >> c;
        dp[i][0] = min(dp[i-1][1] , dp[i-1][2]) + a;
        dp[i][1] = min(dp[i-1][0] , dp[i-1][2]) + b;
        dp[i][2] = min(dp[i-1][0] , dp[i-1][1]) + c;
    }
    cout << *min_element(dp[n].begin() , dp[n].end());
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
    solve();
    return 0;
}