#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector
#define pll pair<ll,ll>
#define f first 
#define s second 
#define mp make_pair
struct DSU{
    vect<ll> par , s;
    ll find(ll a){
        if (a != par[a]) return par[a] = find(par[a]);
        else return a;
    }
    void merge(ll a , ll b){
        a = find(a) ; b = find(b);
        if (s[a] < s[b]) swap(a,b);
        par[b] = a;
        s[a] += s[b];
    }
    DSU(ll n){
        par.resize(n);
        s.resize(n);
        for (int i = 0 ; i<n ; i++){
            par[i] = i ; s[i] = 1;
        }
    }
};

int main(){
    ll n,k ; cin >> n >> k;
    vect<pair<ll,pll>> edges;
    for (int i = 0 ; i<n ; i++){
        for (int j = 0 ; j<n ; j++){
            if (i == j) continue;
            edges.push_back(mp(-84ll*(i+1) - 48ll*(j+1)  , mp(i,j)));
        }
    }
    DSU dsu(n);
    ll comps = n; ll i = 0;
    sort(edges.begin() , edges.end() , [&](auto a , auto b){return a.f > b.f;});
    for (auto [length , edge] : edges){
        if (comps == k) break;
        if (dsu.find(edge.f) != dsu.find(edge.s)){
            comps--;
            dsu.merge(edge.f , edge.s);
        }
        i++;
    }

    cout << 2019201997 + edges[i+1].f;
}