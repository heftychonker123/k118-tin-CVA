#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> state; // 0=chưa thăm, 1=đang thăm, 2=đã xong
vector<ll> topo;
bool hasCycle = false;

void dfs(int u, vector<vector<int>>& graph) {
    state[u] = 1; // đang thăm
    for (int v : graph[u]) {
        if (state[v] == 0) dfs(v, graph);
        else if (state[v] == 1) hasCycle = true; // phát hiện chu trình
    }
    state[u] = 2;
    topo.push_back(u);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<vector<int>> graph(n+1);
    for (int i=0; i<m; i++) {
        int a,b; cin >> a >> b;
        graph[a].push_back(b);
    }

    state.assign(n+1,0);
    for (int i=1; i<=n; i++) {
        if (state[i]==0) dfs(i, graph);
    }

    if (hasCycle) {
        cout << "IMPOSSIBLE";
    } else {
        reverse(topo.begin(), topo.end());
        for (int x : topo) cout << x << " ";
    }
    return 0;
}
