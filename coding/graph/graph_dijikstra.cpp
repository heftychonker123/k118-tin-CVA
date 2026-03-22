#include <bits/stdc++.h>
using namespace std;
#define filename "Dijkstra"
#define ll                  long long
#define llmin               LLONG_MIN
#define llmax               LLONG_MAX
#define pb                  push_back
#define vect                vector
#define FOR(i , m , n)      for (int i=m ; i<n ; i++)
#define FOR_r(i , m , n)    for (int i=m ; i>n ; i--)

void dijikstra(ll nodes , vect<vect<pair<ll,ll>>> &graph , ll n){
    vect<ll> dist(n , llmax);
    vect<ll> trace(n,-1);
    set<ll> visited;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0 , nodes});
    dist[nodes]=0;
    while (!pq.empty()){
        auto [distance , node] = pq.top() ; pq.pop();
        if (visited.find(node) != visited.end()) continue;
        visited.insert(node);
        if (distance == llmax) break;
        for (auto [neighbor,weight] : graph[node]){
            if (visited.find(neighbor) == visited.end() 
            &&  distance + weight < dist[neighbor]){
                dist[neighbor] = distance + weight;
                trace[neighbor] = node;
                pq.push({dist[neighbor] , neighbor});
            }
        }
    }
    for (int i=0 ; i<n ; i++){
        if (i==nodes) continue;
        cout << nodes+1 << " " << i+1 << " " << dist[i] << " ";
        vect<ll> route = {i+1};
        int curr = i;
        while (trace[curr]!=-1){
            curr = trace[curr];
            route.push_back(curr+1);
        } 
        for (int i=route.size()-1 ; i>=0 ; i--) cout << route[i] << " ";
        cout << "\n";
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
    ll n,m,u ; cin >> n >> m >> u;
    vect<vect<pair<ll,ll>>> graph(n);
    for (int i=0 ; i<m ; i++){
        ll a,b,w; cin >> a >> b >> w;
        a--;b--;
        graph[a].push_back({b,w});
        graph[b].push_back({a,w});
    }
    u--;
    dijikstra(u , graph , n);
    return 0;
}