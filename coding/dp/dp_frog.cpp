#include <bits/stdc++.h>
using namespace std;
#define filename "frog"
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
    vect<ll> v(n) ; for (int i=0 ; i<n ; i++) cin >> v[i];
    vect<ll> dp(n,0);
    for (int i=1 ; i<n ; i++){
        for (int j=i-1 ; j >= max(0ll , i-k) ; j--){
            dp[i] = min(dp[i] , dp[j] + abs(v[i] - v[j]));
        }
    }
    cout << dp[n-1] << "\n";
    return 0;
}