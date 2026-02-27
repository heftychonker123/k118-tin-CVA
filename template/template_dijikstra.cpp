#include <bits/stdc++.h>
using namespace std;
#define filename "dijkstra"
#define ll long long
#define pb push_back
#define vect vector
#define umap unordered_map
const ll INF = LLONG_MAX;

void solve(umap<ll, vect<pair<ll,ll>>> &graph, ll root) {
    umap<ll,ll> dist;
    umap<ll,bool> visited;

    for (const auto &i : graph) {
        dist[i.first] = INF;
        visited[i.first] = false;
    }

    dist[root] = 0;

    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0, root});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (visited[u]) continue;
        visited[u] = true;

        for (const auto &[v, w] : graph[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    // Print distances
    for (const auto &i : dist) {
        if (i.second == INF)
            cout << "Node " << i.first << " is unreachable\n";
        else
            cout << "Node " << i.first << " distance = " << i.second << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, root; 
    cin >> n >> root;
    umap<ll,vect<pair<ll,ll>>> graph;

    while (n--) {
        ll u, v, w; 
        cin >> u >> v >> w;
        graph[u].pb({v, w});
    }

    solve(graph, root);
    return 0;
}
