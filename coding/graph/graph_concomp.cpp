#include <bits/stdc++.h>
using namespace std;
#define filename "tplt"
#define ll long long
#define vect vector

void IO(){
    if (fopen(filename".inp" , "r"))
    {
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    }
}

void flood_fill(vect<bool> &visited , vect<vect<ll>> &graph , ll root){
    if (visited[root]) return;
    visited[root] = true;
    for (const ll neighbour : graph[root]){
        flood_fill(visited,graph,neighbour);
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    IO();
    ll n,m ; cin >> n >> m;
    vect<vect<ll>> graph(n);
    for (int i=0 ; i<m ; i++){
        ll a,b ; cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }
    
    ll connect_components = 0;
    vect<bool> visited(n);
    for (int i=0 ; i<n ; i++){
        if (!visited[i]){
            connect_components++;
            flood_fill(visited , graph , i);
        }
    }
    cout << connect_components;
    return 0;
}