#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,q; 
    cin >> n >> q;
    vect<ll> pref(n+1,0);

    for (int i=1 ; i<=n ; i++){
        ll t; cin >> t;
        pref[i] = pref[i-1] + t;
    }
    while (q--){
        ll t; cin >> t;
        ll contestant = 0;
        ll l=1, r=n;
        while (l<=r){
            ll m = (l+r)/2;
            if (pref[m] >= t){
                contestant = m;
                r = m-1;
            } 
            else l = m+1;
        }
        cout << contestant << " ";
    }
    cout << "\n";
    return 0;
}
