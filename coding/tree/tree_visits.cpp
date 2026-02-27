#include <bits/stdc++.h>
using namespace std;
#define filename "milk_visits"
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
void dfs(ll root , ll components , str milk , vect<vect<ll>> &tree , vect<ll> &comp){
    comp[root] = components;
    for (const ll &i : tree[root]){
        if (milk[i] == milk[root] && comp[i] == -1) dfs(i , components , milk , tree , comp);
    }
    return;
}
void solve(){
    ll n,m; cin >> n >> m;
    str s ; cin >> s;
    vect<vect<ll>> tree(n);
    for (int i=1 ; i<n ; i++){
        ll a,b ; cin >> a >> b;
        tree[a-1].pb(b-1);
        tree[b-1].pb(a-1);
    }
    vect<ll> comp(n , -1);
    ll components = 0;
    for (int i=0 ; i<n ; i++){
        if (comp[i] == -1){
            components++;
            dfs(i , components , s , tree , comp);
        }
    }
    while (m--){
        ll a,b; cin >> a >> b;
        char milkType; cin >> milkType;
        a--; b--; 

        if (comp[a] != comp[b]) cout << "1";
        else if (s[a] == milkType) cout << "1";
        else cout << "0";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}