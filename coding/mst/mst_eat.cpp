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

ll binary_expo(ll base, ll MODULO, ll exp){
    ll res = 1;
    base %= MODULO;
    while (exp > 0){
        if (exp % 2 == 1) {
            res = (res * base) % MODULO;
        }
        base = (base * base) % MODULO; // bình phương cơ số
        exp /= 2;
    }
    return res;
}

ll calc_weight(ll x , ll y , ll m){
    return (binary_expo(x,m,y) + binary_expo(y,m,x))%m;
}
int main(){
    ll n,M ; cin >> n >> M;
    vect<ll> v(n); for (int i = 0 ; i<n ; i++) cin >> v[i];
    vect<pair<ll,pll>> edges; 
    for (int i = 0 ; i<n ; i++){
        for (int j = 0 ; j<n ; j++){
            if (i == j) continue;
            else{
                edges.push_back(mp(calc_weight(v[i] , v[j] , M) , mp(i,j)));
            }
        }
    }
    DSU dsu(n);
    ll res = 0;
    sort(edges.begin() , edges.end() , [&](auto a , auto b){return a.first > b.first;});
    for (auto [length , edge] : edges){
        if (dsu.find(edge.f) != dsu.find(edge.s)){
            res += length;
            dsu.merge(edge.f , edge.s);
        }
    }
    cout << res;
}