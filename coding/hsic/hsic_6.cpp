#include <bits/stdc++.h>
using namespace std;
#define filename "6"
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
void solve(ll n , vect<ll> v){
    sort(v.begin() , v.end());
    ll sum=0;
    for (int i=0 ; i<n-1 ; i++){
        if (v[i]<v[i+1]) sum+=v[i];
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen(filename".inp" , "r" , stdin);
    //freopen(filename".out" , "w" , stdout);
    ll n ; cin >> n;
    vect<ll> v(n);
    for (ll i=0 ; i<n ; i++) cin >> v[i];
    solve(n,v);
}