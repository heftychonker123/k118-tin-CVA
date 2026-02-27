#include <bits/stdc++.h>
using namespace std;
#define filename "concomponent"
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
//Algorithm to find the number of connected components
void solve(umap<ll,vect<ll>> edges){
    umap<ll,bool> visited;
    for (const auto &i : edges) visited[i.first] = false;
    ll res=0;
    queue<ll> q;
    for (const auto &[point,neighbors] : edges){
        if (!visited[point]){
            res++;
            q.push(point);
            while (!q.empty()){
                ll curr = q.front() ; q.pop();
                for (const ll &neighbor : edges[curr]){
                    if (!visited[neighbor]){
                        visited[neighbor]=true;
                        q.push(neighbor);
                    }
                }
            }
        }
    }
    cout << res << "\n";
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen(filename".inp" , "r" , stdin);
    //freopen(filename".out" , "w" , stdout);
    umap<ll,vect<ll>> graph;
    ll m ; cin >> m;
    while (m--){
        ll u,v ; cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    solve(graph);
}