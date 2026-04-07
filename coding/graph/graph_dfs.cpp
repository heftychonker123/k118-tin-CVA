#include <bits/stdc++.h>
using namespace std;
#define filename "dfs"
#define ll                  long long
#define llmin               LLONG_MIN
#define llmax               LLONG_MAX
#define pb                  push_back
#define vect                vector
#define FOR(i , m , n)      for (int i=m ; i<n ; i++)
#define FOR_r(i , m , n)    for (int i=m ; i>n ; i--)
vect<ll> visited(1000 , false);
vect<ll> adj[1000];

void dfs(ll node){
    visited[node] = true;
    cout << node+1 << " ";
    for (ll &neighbor : adj[node]){
        if (!visited[neighbor]) dfs(neighbor);
    }
    return;
}
void IO(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen(filename".inp" , "r"))
    {
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    }
}
int main(){
    IO();
    ll n,m,s; cin >> n >> m >> s;
    FOR(i , 0 , m){
        ll a,b ; cin >> a >> b;
        adj[a-1].pb(b-1);
    }
    FOR(i , 0 , n){
        sort(adj[i].begin() , adj[i].end());
    }
    dfs(s-1);
    return 0;
}