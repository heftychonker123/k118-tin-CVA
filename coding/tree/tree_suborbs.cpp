#include <bits/stdc++.h>
using namespace std;
#define filename "suborbs"
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
void dfs(ll root , vect<vect<ll>> &tree , vect<ll> &suborbs){
    suborbs[root]=1;
    for (const ll &i : tree[root]){
        dfs(i , tree , suborbs);
        suborbs[root] += suborbs[i];
    }
}
void solve(){
    ll n ; cin >> n;
    vect<vect<ll>> tree(n);
    for (int i=1 ; i<n ; i++){
        ll p ; cin >> p;
        p--;
        tree[p].pb(i);
    }
    vect<ll> suborbs(n);
    dfs(0 , tree , suborbs);
    for (const ll &i : suborbs) cout << i-1 << " ";
}
void IO(){
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //IO();
    solve();
    return 0;
}