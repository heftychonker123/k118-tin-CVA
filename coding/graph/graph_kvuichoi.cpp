#include <bits/stdc++.h>
using namespace std;
#define filename "kvuichoi"
#define ll long long
#define pb push_back
#define vect vector
#define FOR(i , m , n) for (int i=m ; i<n ; i++)
#define FOR_r(i , m , n) for (int i=m ; i>n ; i--)

const ll MAXN = 200;
vect<ll> tree[MAXN];
ll parent[MAXN];
ll depth[MAXN];

void dfsDepth(ll node , ll p = -1){
    if (p != -1) depth[node] = depth[p] + 1;
    parent[node] = p;
    for (ll i : tree[node]){
        if (i != p) dfsDepth(i , node);
    }
}

ll lca(ll a , ll b){
    if (depth[a] < depth[b]) swap(a,b);
    while (depth[a] > depth[b]) a = parent[a];
    while (a != b){
        a = parent[a]; 
        b = parent[b];
    }
    return a;
}

void IO(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen(filename".inp" , "r")){
        freopen(filename".inp" , "r" , stdin);
        freopen(filename".out" , "w" , stdout);
    }
}

int main(){
    IO();
    ll n; cin >> n;
    FOR(i , 0 , n-1){
        ll a,b; cin >> a >> b;
        a--; b--;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    ll m; cin >> m;
    vect<ll> v(m);
    FOR(i , 0 , m) cin >> v[i];
    FOR(i , 0 , m) v[i]--;

    depth[v[0]] = 0;
    dfsDepth(v[0]);

    ll res = 0;
    FOR(i , 0 , m-1){
        ll comNode = lca(v[i] , v[i+1]);
        res += depth[v[i]] + depth[v[i+1]] - 2 * depth[comNode];
    }
    cout << res;
    return 0;
}
