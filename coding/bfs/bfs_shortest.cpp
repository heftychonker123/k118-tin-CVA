#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector
const ll MAXN = 1e5 + 1;
vect<int> graph[MAXN];
int depth[MAXN];
void bfs(ll start){
    depth[start] = 0;
    queue<pair<int,int>> q;
    q.push(make_pair(start , 0));
    while (!q.empty()){
        auto [curr , d] = q.front(); q.pop();
        for (int i : graph[curr]){
            if (depth[i] == -1){
                depth[i] = d + 1;
                q.push(make_pair(i , depth[i]));
            }
        }
    }
}

int main(){
    fill(&depth[0] , &depth[0] + MAXN , -1);
    int n,m ; cin >> n >> m;
    for (int i = 0 ; i<m ; i++){
        int a,b ; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bfs(1);
    for (int i = 1 ; i<=n ; i++){
        cout << depth[i] << "\n";
    }
}