#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector

ll dfsFill(int node, vect<ll>& v, vect<vect<int>>& tree, vect<ll>& c){
    v[node] = c[node];
    for (int child : tree[node]){
        v[node] += dfsFill(child, v, tree, c);
    }
    return v[node];
}

int main(){
    int n,m,t; cin >> n >> m >> t;
    vect<ll> c(n+1);
    for (int i=1;i<=n;i++) cin >> c[i];

    vect<vect<pair<int,ll>>> graph(n+1);
    for (int i=0;i<m;i++){
        int a,b; ll x; cin >> a >> b >> x;
        graph[a].push_back({b,x});
        graph[b].push_back({a,x});
    }

    vect<ll> dist(n+1, LLONG_MAX);
    vect<int> ances(n+1, -1);
    vect<bool> visited(n+1, false);
    dist[1] = 0;

    using T = pair<ll,int>; // (dist,node)
    priority_queue<T, vect<T>, greater<T>> pq;
    pq.push({0,1});

    while(!pq.empty()){
        auto [d,node] = pq.top(); pq.pop();
        if(visited[node]) continue;
        visited[node] = true;

        for(auto [nxt,w]:graph[node]){
            if(dist[nxt] > dist[node]+w){
                dist[nxt] = dist[node]+w;
                ances[nxt] = node;
                pq.push({dist[nxt],nxt});
            } else if(dist[nxt] == dist[node]+w){
                if(ances[nxt]==-1 || node<ances[nxt]) ances[nxt]=node;
            }
        }
    }

    vect<vect<int>> tree(n+1);
    for(int i=1;i<=n;i++){
        if(ances[i]>0) tree[ances[i]].push_back(i);
    }

    vect<ll> descNum(n+1,0);
    dfsFill(1, descNum, tree, c);

    ll res=0;
    for(int i=1;i<=n;i++){
        if(dist[i]>=t){
            res = max(res, descNum[i]*(dist[i]-t));
        }
    }
    cout << res << "\n";
}
