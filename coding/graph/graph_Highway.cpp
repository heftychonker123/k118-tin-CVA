#include <bits/stdc++.h>
using namespace std;
#define filename "Highway"
#define ll                  long long
#define llmin               LLONG_MIN
#define llmax               LLONG_MAX
#define pb                  push_back
#define vect                vector
#define FOR(i , m , n)      for (int i=m ; i<n ; i++)
#define FOR_r(i , m , n)    for (int i=m ; i>n ; i--)

struct Node{
    ll x, y, idx;
};
struct Edge{
    Node a, b;
    Edge(Node a, Node b) : a(a), b(b){}
};

vect<Edge> unused_edges;


vect<ll> dsu, dsize;

ll find(ll node){
    if (node == dsu[node]) return node;
    return dsu[node] = find(dsu[node]);
}
void merge(ll a, ll b){
    if (dsize[a] < dsize[b]) swap(a, b);
    dsu[b] = a; dsize[a] += dsize[b];
}

long double Kruskal(){
    sort(unused_edges.begin(), unused_edges.end(), [&](const Edge& m, const Edge& n) {
        
        ll dist_m = (ll)(m.a.x - m.b.x) * (m.a.x - m.b.x)
                  + (ll)(m.a.y - m.b.y) * (m.a.y - m.b.y);
        ll dist_n = (ll)(n.a.x - n.b.x) * (n.a.x - n.b.x)
                  + (ll)(n.a.y - n.b.y) * (n.a.y - n.b.y);
        return dist_m < dist_n;
    });
    
    long double total = 0;
    for (auto& edge : unused_edges){
        auto a = edge.a, b = edge.b;
        ll pA = find(a.idx), pB = find(b.idx);
        if (pA == pB) continue;
        else{
            merge(pA, pB);
            long double length = sqrtl((ll)(a.x-b.x)*(a.x-b.x) + (ll)(a.y-b.y)*(a.y-b.y));
            total += length;
        }
    }
    return total;
}

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
    ll n; cin >> n;

    
    dsu.resize(n);
    iota(dsu.begin(), dsu.end(), 0);
    dsize.assign(n, 1);

    vect<
Node> v(n);
    FOR(i, 0, n){
        cin >> v[i].x >> v[i].y;
        v[i].idx = i;
    }

    ll m; cin >> m;
    vect<unordered_set<ll>> used_edges(n);
    FOR(i, 0, m){
        ll a, b; cin >> a >> b;
        a--; b--;
        used_edges[a].insert(b);
        used_edges[b].insert(a);
        ll pA = find(a), pB = find(b);
        if (pA != pB) merge(pA, pB);
    }

    
    FOR(i, 0, n){
        FOR(j, i+1, n){
            if (used_edges[i].count(j)) continue;
            unused_edges.push_back(Edge(v[i], v[j]));
        }
    }

    
    long double res = Kruskal();
    cout << fixed << setprecision(5) << res;
    return 0;
}