#include <bits/stdc++.h>
using namespace std;
#define filename "nhietdo"
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
    
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    
    ll n; 
    cin >> n;
    vect<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    
    vect<ll> dp(n, llmax);
    dp[0] = 0;
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            ll diff = abs(v[i] - v[j]);
            ll maxDiff = max(dp[j], diff);
            dp[i] = min(dp[i], maxDiff);
        }
    }
    
    cout << dp[n-1] << "\n";
    
    return 0;
}
