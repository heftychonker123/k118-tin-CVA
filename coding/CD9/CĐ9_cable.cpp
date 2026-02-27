#include <bits/stdc++.h>
using namespace std;
#define filename "cable"
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
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n ; cin >> n;
    vect<ll> dist(n-1);
    for (int i=1 ; i<n ; i++) cin >> dist[i-1];
    vect<ll> dp(n+1 , 0);
    dp[1] = LLONG_MAX;
    for (int i=2 ; i<=n ; i++){
        dp[i] = min(dp[i-1] , dp[i-2]) + dist[i-2];
    }
    cout << dp[n];
    return 0;
}