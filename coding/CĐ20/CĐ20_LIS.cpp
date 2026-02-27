#include <bits/stdc++.h>
using namespace std;
#define filename "LIS"
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
    ll n ; cin >> n;
    vect<ll> v(n); for (int i=0 ; i<n ; i++) cin >> v[i];
    vect<ll> dp(n , 0);
    for (int i=0 ; i<n ; i++){
        dp[i] = 1;
        for (int j=0 ; j<i ; j++){
            if (v[i] > v[j]) dp[i] = max(dp[j]+1 , dp[i]);
        }
    }
    cout << *max_element(dp.begin() , dp.end());
    return 0;
}