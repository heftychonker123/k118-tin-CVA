#include <bits/stdc++.h>
using namespace std;
#define filename "Kruskal"
#define ll                  long long
#define llmin               LLONG_MIN
#define llmax               LLONG_MAX
#define pb                  push_back
#define vect                vector
#define FOR(i , m , n)      for (ll i=m ; i<n ; i++)
#define FOR_r(i , m , n)    for (ll i=m ; i>n ; i--)


void IO(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen(filename".inp" , "r"))
    {
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    }
}

bool comp(array<ll,3> a , array<ll,3> b){return a[2] < b[2];}

ll find(ll a , vect<ll> &rep){
    while (a!=rep[a]) a=rep[a];
    return a;
}

void unite(vect<ll> &rep , vect<ll> &size , ll a , ll b){
    a = find(a , rep);
    b = find(b , rep);
    if (size[a] < size[b]) swap(a,b);
    size[a]+=size[b] ; rep[b] = a;
}

ll min_spanning_tree(vect<array<ll,3>> edges , ll n){
    //DSU data structures(i am lazy to implement a class so here we go)
    vect<ll> rep(n) , size(n);
    for (ll i=0 ; i<n ; i++){
        rep[i] = i;
        size[i] = 1;
    }
    sort(edges.begin() , edges.end() , comp);
    ll edgeCount = 0 , treeSize=0;
    for (auto &edge : edges){
        if (find(edge[0] , rep) == find(edge[1] , rep)) continue;
        else{
            unite(rep,size,edge[0] , edge[1]);
            treeSize+=edge[2];
            if (++edgeCount == n-1) break;
        }
    }
    return treeSize;
}
signed main(){
    IO();
    ll n,m ; cin >> n >> m;
    vect<array<ll,3>> v(m);
    for (ll i=0 ; i<m ; i++) cin >> v[i][0] >> v[i][1] >> v[i][2];
    cout << n-1 << " " << min_spanning_tree(v,n);
    return 0;
}