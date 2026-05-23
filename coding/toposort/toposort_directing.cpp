#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector

const ll MAXN = 2e5 + 5;
vect<ll> graph[MAXN]; ll visited[MAXN]; bool SORT = true;
vect<ll> topo;

void dfs(ll node){
    visited[node] = 1;
    for (int i : graph[node]){
        if (visited[i] == 1) SORT = false;
        else if (visited[i] == 0) dfs(i);
    }
    visited[node] = 2;
    topo.push_back(node);
}

void toposort(ll n){
    for (int i = 1 ; i<=n ; i++){
        if (visited[i] == 0) dfs(i);
    }
}

void solve(){
    ll n,m ; cin >> n >> m;
    topo.clear();
    fill(visited, visited+n+1, 0);
    for (int i=0; i<=n; i++) graph[i].clear();
    SORT = true;
    vect<pair<ll,ll>> undirected_edge , directed_edge;
    for (int i = 0 ; i<m ; i++){
        ll x,a,b ; cin >> x >> a >> b;
        if (x==1) {
            graph[a].push_back(b);
            directed_edge.push_back(make_pair(a,b));
        }
        if (x==0) undirected_edge.push_back(make_pair(a,b));
    }
    toposort(n);
    if (!SORT){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    vect<ll> idx(n);
    for (int i = 0 ; i<n ; i++) idx[topo[i]-1] = i; // nếu node từ 1..n
    for (auto [a,b] : undirected_edge){
        if (idx[a-1] > idx[b-1]) cout << a << " " << b << "\n";
        else cout << b << " " << a << "\n";
    }
    for (auto [a,b] : directed_edge) cout << a << " " << b << "\n";
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t ; cin >> t;
    while (t--) solve();
}