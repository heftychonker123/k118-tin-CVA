#include <bits/stdc++.h>
using namespace std;
#define ll long long

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m ; cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0 ; i<m ; i++){
        int a,b ; cin >> a >> b;
        a--;b--;
        graph[a].push_back(b);
    }

    vector<int> topo , inDeg(n);
    for (auto &v : graph) for (int &i : v) inDeg[i]++;
    queue<int> q; 
    for (int i = 0 ; i<n ; i++) if (inDeg[i] == 0) q.push(i);
    while (!q.empty()){
        auto curr = q.front() ; q.pop();
        topo.push_back(curr);

        for (int &i : graph[curr]) if (--inDeg[i] == 0) q.push(i);
    }

    if (topo.size() == n){
        for (int &i : topo) cout << i + 1 << ' ';
        cout << '\n';
    }
    else cout << 'IMPOSSIBLE' << '\n';
}