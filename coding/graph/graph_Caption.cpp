#include <bits/stdc++.h>
using namespace std;

#define filename "Caption"
#define ll                  long long
#define llmin               LLONG_MIN
#define llmax               LLONG_MAX
#define pb                  push_back
#define vect                vector
#define FOR(i , m , n)      for (int i=m ; i<n ; i++)
#define FOR_r(i , m , n)    for (int i=m ; i>n ; i--)
#define first fi
#define second se

const ll MAXN = 1000;
ll n, s, t, m;
vect<pair<ll,ll>> adj[MAXN];   
ll detonate[MAXN];

vect<ll> solve() {
    vect<ll> dist(n, 1e9);
    vect<bool> visited(n, false);
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    dist[s] = 0;
    pq.push({dist[s], s});

    while (!pq.empty()) {
        auto [weight, curr] = pq.top(); 
        pq.pop();

        if (visited[curr]) continue;

        
        if (weight > detonate[curr]) {
            dist[curr] = 1e9;
            continue;
        }

        visited[curr] = true;

        for (auto [w, nxt] : adj[curr]) {
            if (!visited[nxt]) {
                dist[nxt] = min(dist[nxt], dist[curr] + w);
                pq.push({dist[nxt], nxt});
            }
        }
    }
    return dist;
}

void IO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen(filename".inp", "r")) {
        freopen(filename".inp", "r", stdin);
        freopen(filename".out", "w", stdout);
    }
}

int main() {
    IO();
    fill(detonate , detonate + MAXN , llmax);

    cin >> n >> m >> s >> t;
    s--; t--;
    FOR(i, 0, n){
        ll d ; cin >> d;
        if (d!=0) detonate[i] = d;
    }

    FOR(i, 0, m) {
        ll a, b, y; 
        cin >> a >> b >> y;
        a--; b--;
        adj[a].pb({y, b});   
        adj[b].pb({y, a});
    }

    vect<ll> dist = solve();
    if (dist[t] >= 1e9) cout << -1;   
    else cout << dist[t];

    return 0;
}