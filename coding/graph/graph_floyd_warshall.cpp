#include <bits/stdc++.h>
using namespace std;
#define filename "floyd_warshall"
#define ll                  long long
#define llmin               LLONG_MIN
#define llmax               LLONG_MAX
#define pb                  push_back
#define vect                vector


void floydWarshall(vector<array<ll,3>> edges, ll n) {
    vector<vector<ll>> dist(n, vector<ll>(n, llmax));
    vector<vector<int>> prev(n, vector<int>(n, -1));

    for (auto edge : edges) {
        dist[edge[0]][edge[1]] = edge[2];
        dist[edge[1]][edge[0]] = edge[2];
        prev[edge[0]][edge[1]] = edge[0];
        prev[edge[1]][edge[0]] = edge[1];
    }
    for (int i = 0; i < n; i++) dist[i][i] = 0;

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != llmax && dist[k][j] != llmax &&
                    dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    prev[i][j] = prev[k][j];
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i==j) continue;
            cout << i+1 << " " << j+1 << " " << dist[i][j] << " ";
            vect<ll> route = {j+1};
            int cur = j;
            while (prev[i][cur] != -1) {
                cur = prev[i][cur];
                route.push_back(cur+1);
            }
            for (int i=route.size() - 1 ; i>=0 ; i--) cout << route[i] << " ";
            cout << "\n";
        }
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
    ll n,m ; cin >> n >> m;
    vect<array<ll,3>> v(m);
    for (int i=0 ; i<m ; i++){
        ll a,b,w ; cin >> a >> b >> w;
        v[i][2] = w ; v[i][0] = a-1 ; v[i][1] = b-1;
    }
    floydWarshall(v , n);
    return 0;
}