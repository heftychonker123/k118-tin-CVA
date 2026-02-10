#include <bits/stdc++.h>
using namespace std;
#define filename "cowtagion"
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
void dfs(vect<vect<ll>> &tree , ll &sum, ll root = 0){
    if (!tree[root].empty()) {
        sum += log2(tree[root].size()+1) + tree[root].size();
        for (const ll &i : tree[root]){
            dfs(tree , sum , i);
        }
    }
    return;
}
void solve(){
    ll n ; cin >> n;
    vect<vect<ll>> tree(n);
    for (int i=1 ; i<n ; i++){
        ll a,b ; cin >> a >> b;
        tree[a-1].pb(b-1);
    }
    ll sum = 0;
    dfs(tree , sum);
    cout << sum;
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