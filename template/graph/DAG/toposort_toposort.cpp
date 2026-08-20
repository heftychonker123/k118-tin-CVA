#include <bits/stdc++.h>
using namespace std;

#define vect vector
const int MAXN = 1e5 + 1;
vect<int> graph[MAXN];

int process[MAXN];
bool s = true;
vect<int> topo;
void toposort(int start){
    process[start] = 1;
    for (int i : graph[start]){
        if (process[i] == 0){
            toposort(i);
        }
        else if (process[i] == 1) s = false;
    }
    process[start] = 2;
    topo.push_back(start);
}


signed main(){
    int n,m ; cin >> n >> m;
    for (int i = 0 ; i<m ; i++){
        int a,b ; cin >> a >> b;
        graph[b].push_back(a);
    }

    for (int i = 1 ; i<=n ; i++){
        if (!s) break;
        if (process[i] == 0) toposort(i);
    }
    if (!s) cout << "IMPOSSIBLE";
    else for (int i : topo) cout << i << " ";
}