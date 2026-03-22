#include <bits/stdc++.h>
using namespace std;
#define filename "tapdem"
#define ll long long
#define vect vector
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,q ; cin >> n >> q;

    vect<ll> v(n); for (int i=0 ; i<n ; i++) cin >> v[i];
    map<ll , vect<ll>> pos;
    for (int i=0 ; i<n ; i++) pos[v[i]].push_back(i+1); 
    while (q--){
        ll l,r,x ; cin >> l >> r >> x;
        if (pos.find(x) == pos.end()) cout << 0 << "\n";
        else{
            vect<ll> curr = pos[x];
            auto left = lower_bound(curr.begin() , curr.end() , l);
            auto right = upper_bound(curr.begin() , curr.end() , r);
            cout << (right-left) << "\n";
        }
    }
    return 0;
}