#include <bits/stdc++.h>
using namespace std;
#define filename "lietke"
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
vect<vect<ll>> backtrack(ll n , vect<ll> temp){
    if (n==0) return {temp};
    vect<vect<ll>> ans;
    for (int i = temp.back() ; i<=n ; i++){
        temp.pb(i);
        vect<vect<ll>> sub = backtrack(n-i , temp);
        for (const vect<ll> v : sub) ans.pb(v);
        temp.pop_back();
    }
    return ans;
}
void solve(){
    ll n ; cin >> n;
    for (ll i=1 ; i<n ; i++){
        vect<vect<ll>> res = backtrack(n-i , {i});
        for (const auto v: res){
            for (const ll i:v){
                cout << i << " ";
            }
            cout << "\n";
        }
    }
    
}
void IO(){
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    IO();
    solve();
    return 0;
}