#include <bits/stdc++.h>
using namespace std;
#define filename "gameseq"
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
    ll n,k ; cin >> n >> k;
    vector<ll> v(n); for (int i=0 ; i<n ; i++) cin >> v[i];
    vector<ll> dp(n+1 , llmin);
    dp[0] = 0;
    for (int i=1 ; i<=n ; i++){
        for (int j = max(0ll , i-k) ; j<i ; j++) dp[i] = max(dp[i] , dp[j] + v[i-1]);
    }
    cout << *max_element(dp.begin() , dp.end());
    return 0;
}