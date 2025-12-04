#include <bits/stdc++.h>
using namespace std;
#define filename "khachhang"
#define ll long long
#define vect vector

int main(){
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    ll n ; cin >> n;
    multiset<pair<ll,ll>> a;
    vect<ll> b(n);
    for (int i=0 ; i<n ; i++){
        ll t ; cin >> t;
        a.insert({t,i+1});
    }
    for (int i=0 ; i<n ; i++) cin >> b[i];
    set<ll> indices;
    for (int i=1 ; i<=n ; i++) indices.insert(i);

    for (int i=0 ; i<n ; i++){
        ll t = b[i];
        auto it = a.lower_bound({t, -1});
        ll serve;
        if (it==a.end()){
            serve = *indices.begin();
            auto it2 = a.begin();
            while (it2!=a.end() && it2->second!=serve) ++it2;
            a.erase(it2);
        }
        else{
            serve = it->second;
            a.erase(it);
        }
        indices.erase(serve);
        cout << serve << " ";
    }
}
