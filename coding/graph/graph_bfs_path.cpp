#include <bits/stdc++.h>
using namespace std;
#define filename "bfs_path"
#define ll                  long long
#define llmin               LLONG_MIN
#define llmax               LLONG_MAX
#define pb                  push_back
#define vect                vector
#define FOR(i , m , n)      for (int i=m ; i<n ; i++)
#define FOR_r(i , m , n)    for (int i=m ; i>n ; i--)

vect<ll> p(1000 , -1);
vect<ll> adj[1000];
void bfs(ll node , ll target){
    queue<ll> q; q.push(node); p[node] = node;
    while (!q.empty()){
        ll curr = q.front(); q.pop();
        for (ll &n : adj[curr]){
            if (p[n] == -1){
                p[n] = curr;
                q.push(n);
            }
        }
    }
    if (p[target] == -1) {
        cout << -1;
    } else {
        vect<ll> path;
        for (ll v = target; v != node; v = p[v]) {
            path.pb(v);
        }
        path.pb(node);
        reverse(path.begin(), path.end());
        FOR(i , 0 , path.size()) cout << path[i]+1 << " ";
    }
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
    ll n,m,s,t; cin >> n >> m >> s >> t;
    FOR(i , 0 , m){
        ll a,b ; cin >> a >> b;
        adj[a-1].pb(b-1);
    }
    bfs(s-1 , t-1);
    return 0;
}