#include <bits/stdc++.h>
using namespace std;
#define filename "prime"
#define ll                  long long
#define llmin               LLONG_MIN
#define llmax               LLONG_MAX
#define pb                  push_back
#define vect                vector
#define FOR(i , m , n)      for (int i=m ; i<n ; i++)
#define FOR_r(i , m , n)    for (int i=m ; i>n ; i--)

ll Prims(ll n , vect<vect<pair<ll,ll>>> &adj) {
    vector<ll> dist(n, llmax);
    dist[0] = 0;
    ll tree_size = 0;
    set<ll> visited;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        auto [val, node] = pq.top(); pq.pop();
        if (visited.find(node) != visited.end()) continue;
        visited.insert(node);
        tree_size += val;

        for (auto [neighbor, edgeW] : adj[node]) {
            if (visited.find(neighbor) == visited.end() && edgeW < dist[neighbor]) {
                dist[neighbor] = edgeW;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }
    return tree_size;
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
    ll n,m ; cin >> n >> m;
    vect<vect<pair<ll,ll>>> graph(n);
    for (int i=0 ; i<m ; i++){
        ll a,b,w; cin >> a >> b >> w;
        a--;b--;
        graph[a].push_back({b,w});
        graph[b].push_back({a,w});
    }
    cout << Prims(n , graph);
    return 0;
}