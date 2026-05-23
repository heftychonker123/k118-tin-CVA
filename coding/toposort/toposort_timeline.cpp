#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vect vector

const ll MAXN = 1e5 + 5;
vect<ll> topo;
int visited[MAXN];
vect<pair<ll,ll>> graph[MAXN];

void dfs(ll node){
    visited[node] = 1;
    for (auto &[i,temp] : graph[node]){
        if (visited[i] == 0) dfs(i);
    }
    visited[node] = 2;
    topo.push_back(node);
}

void toposort(ll n){
    for (int i = 1 ; i<=n ; i++){
        if (visited[i] != 2) dfs(i);
    }
}

void solve(ll n , vect<ll> mintime){
    toposort(n);

    vect<ll> time(n+1);
    for (ll &i : topo){
        time[i] = mintime[i];
        for (auto &[j,diff] : graph[i]){
            if (time[j] + diff > time[i]) time[i] = time[j]+diff;
        }
    }
    for (int i = 1 ; i<=n ; i++) cout << time[i] << "\n";
}

int main(){
    ll n,m,c ; cin >> n >> m >> c;
    vect<ll> mintime(n+1); for (int i = 1 ; i <= n ; i++) cin >> mintime[i];
    for (int i = 0 ; i<c ; i++){
        ll a,b,x ; cin >> a >> b >> x;
        graph[b].push_back(make_pair(a,x));
    }
    solve(n,mintime);
}