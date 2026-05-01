#include <bits/stdc++.h>
using namespace std;
#define filename "saohoa"
#define ll long long

const int MAXN = 205;
const ll INF = 1e18;
ll dist[MAXN][MAXN];

void IO(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen(filename".inp", "r")){
        freopen(filename".inp", "r", stdin);
        freopen(filename".out", "w", stdout);
    }
}

int main(){
    IO();
    int n, m;
    cin >> n >> m;

    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            dist[i][j] = (i == j) ? 0 : INF;

    vector<array<ll,3>> edges(m);
    for(int i = 0; i < m; i++){
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
        ll u = edges[i][0], v = edges[i][1], w = edges[i][2];
        
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }

    
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    ll num = 0, sum = 0;
    for(auto& e : edges){
        ll u = e[0], v = e[1], w = e[2];

        
        if(dist[u][v] != w) continue;

        
        bool redundant = false;
        for(int k = 1; k <= n; k++){
            if(k == u || k == v) continue;
            if(dist[u][k] + dist[k][v] == w){
                redundant = true;
                break;
            }
        }

        if(!redundant){
            num++;
            sum += w;
        }
    }

    cout << num << " " << sum;
    return 0;
}