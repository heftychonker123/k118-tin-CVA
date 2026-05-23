#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,m ; cin >> n >> m;
    multiset<ll> h; for (int i = 0 ; i<n ; i++){ll t ; cin >> t ; h.insert(t);}
    for (int tc = 0 ; tc<m ; tc++){
        ll t ; cin >> t;
        auto it = h.upper_bound(t);
        if (it == h.begin()) cout << -1 << "\n";
        else{
            it--;
            cout << *it << "\n";
            h.erase(it);
        }
    }
}