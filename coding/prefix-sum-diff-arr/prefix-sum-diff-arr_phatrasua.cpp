#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector

const int MAX = 200005; // giới hạn tối đa

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,k,q; 
    cin >> n >> k >> q;

    vect<ll> diff(MAX+2,0);

    for (ll i=0; i<n; i++){
        ll l,r; cin >> l >> r;
        diff[l-1] += 1;
        if (r <= MAX) diff[r] -= 1;
    }

    vect<ll> res(MAX+1,0);
    res[0] = diff[0];
    for (int i=1; i<=MAX; i++) res[i] = res[i-1] + diff[i];

    vect<ll> pref(MAX+2,0);
    for (int i=0; i<=MAX; i++){
        pref[i+1] = pref[i] + (res[i] >= k);
    }

    while (q--){
        ll l,r; cin >> l >> r;
        cout << pref[r] - pref[l-1] << "\n";
    }

    return 0;
}
