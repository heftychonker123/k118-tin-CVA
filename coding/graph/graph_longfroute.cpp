#include <bits/stdc++.h>
using namespace std;
const int INF = -1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n+1);
    vector<int> indeg(n+1,0);
    for (int i=0; i<m; i++) {
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        indeg[b]++;
    }

    // topo sort (Kahn)
    queue<int> q;
    for (int i=1; i<=n; i++) if (indeg[i]==0) q.push(i);
    vector<int> topo;
    while(!q.empty()){
        int v=q.front(); q.pop();
        topo.push_back(v);
        for(int u: adj[v]){
            indeg[u]--;
            if(indeg[u]==0) q.push(u);
        }
    }

    vector<int> dp(n+1, INF), parent(n+1,-1);
    dp[1] = 1;

    for(int v: topo){
        if(dp[v]==INF) continue;
        for(int u: adj[v]){
            if(dp[v]+1 > dp[u]){
                dp[u] = dp[v]+1;
                parent[u] = v;
            }
        }
    }

    if(dp[n]==INF){
        cout << "IMPOSSIBLE\n";
    } else {
        cout << dp[n] << "\n";
        vector<int> path;
        for(int v=n; v!=-1; v=parent[v]) path.push_back(v);
        reverse(path.begin(), path.end());
        for(int v: path) cout << v << " ";
    }
}
