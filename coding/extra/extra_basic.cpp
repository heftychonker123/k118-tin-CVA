#include <bits/stdc++.h>
using namespace std;
#define filename "bfs_basic"
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
const ll INF = llmax;

void solve(umap<ll,vect<ll>> &graph , ll root){
    umap<ll,ll> weight;
    umap<ll,bool> visited;

    for (const auto &i : graph) {
        visited[i.first] = false;
        weight[i.first] = INF;
    }

    queue<ll> q;
    q.push(root);
    visited[root] = true;
    weight[root] = 0;

    while (!q.empty()){
        ll curr = q.front(); q.pop();
        for (ll neighbor : graph[curr]){
            if (!visited[neighbor]){
                visited[neighbor] = true;
                weight[neighbor] = weight[curr] + 1;
                q.push(neighbor);
            }
        }
    }

    vector<pair<ll,ll>> result(weight.begin(), weight.end());
    sort(result.begin(), result.end(),
        [&](auto &a, auto &b){
            if (a.second == b.second) return a.first < b.first;
            return a.second < b.second;
        }
    );

    for (auto &[key,value] : result){
        cout << key << " " << value << "\n";
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen(filename".inp" , "r" , stdin);
    //freopen(filename".out" , "w" , stdout);
    ll n,m,root ; cin >> n >> m >> root;
    umap<ll,vect<ll>> graph;
    while (m--){
        ll u,v ; cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    solve(graph,root);
}