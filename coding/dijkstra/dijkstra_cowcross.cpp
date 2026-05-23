#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<ll,ll> dir[4] = {{-1,0},{1,0},{0,-1},{0,1}};
struct edge {
    ll a,b;
    ll d,s;
    edge(ll x,ll y,ll dist,ll turn) : a(x), b(y), d(dist), s(turn) {}
};
struct comp {
    bool operator()(const edge& a,const edge& b) const {
        return a.d > b.d;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,t; cin >> n >> t;
    vector<vector<ll>> g(n, vector<ll>(n));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> g[i][j];

    vector<vector<vector<ll>>> dist(n, vector<vector<ll>>(n, vector<ll>(3, LLONG_MAX)));
    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(n, vector<bool>(3,false)));

    dist[0][0][0] = 0;
    priority_queue<edge, vector<edge>, comp> pq;
    pq.push(edge(0,0,0,0));

    while(!pq.empty()){
        edge curr = pq.top(); pq.pop();
        if(visited[curr.a][curr.b][curr.s]) continue;
        visited[curr.a][curr.b][curr.s] = true;

        for(auto [dx,dy]:dir){
            ll nx = curr.a+dx, ny = curr.b+dy;
            if(nx>=0 && nx<n && ny>=0 && ny<n){
                if(curr.s+1==3){
                    ll nd = dist[curr.a][curr.b][curr.s] + g[nx][ny] + t;
                    if(nd < dist[nx][ny][0]){
                        dist[nx][ny][0] = nd;
                        pq.push(edge(nx,ny,nd,0));
                    }
                } else {
                    ll nd = dist[curr.a][curr.b][curr.s] + t;
                    if(nd < dist[nx][ny][curr.s+1]){
                        dist[nx][ny][curr.s+1] = nd;
                        pq.push(edge(nx,ny,nd,curr.s+1));
                    }
                }
            }
        }
    }

    ll ans = *min_element(dist[n-1][n-1].begin(), dist[n-1][n-1].end());
    cout << ans << "\n";
}
