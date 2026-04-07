#include <bits/stdc++.h>
using namespace std;
#define filename "bfs_undir"
#define ll                  long long
#define llmin               LLONG_MIN
#define llmax               LLONG_MAX
#define pb                  push_back
#define vect                vector
#define FOR(i , m , n)      for (int i=m ; i<n ; i++)
#define FOR_r(i , m , n)    for (int i=m ; i>n ; i--)

vect<ll> adj[1000];
void bfs(ll node){
    queue<ll> q;
    set<ll> visited;
    q.push(node);
    visited.insert(node);
    while (!q.empty()){
        ll curr = q.front(); q.pop();
        cout << curr+1 << " ";
        for (ll &neighbor : adj[curr]){
            if (!visited.count(neighbor)){
                q.push(neighbor);
                visited.insert(neighbor);
            }
        }
    }
}

int main(){
    ll n,m,s; cin >> n >> m >> s;
    FOR(i , 0 , m){
        ll a,b ; cin >> a >> b;
        adj[a-1].pb(b-1);
    }
    FOR(i , 0 , n){
        sort(adj[i].begin() , adj[i].end());
    }
    bfs(s-1);
    return 0;
}