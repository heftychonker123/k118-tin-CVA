#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,t ; cin >> n >> t;
    vector<ll> v(n);
    for (ll i=0 ; i<n ; i++) cin >> v[i];
    ll l=0 , r=*max_element(v.begin() , v.end());
    ll res=0;
    while (l<=r){
        ll cnt=0;
        ll m=(l+r)/2;
        for (const ll &i : v) cnt += max(0ll , i-m);
        if (cnt>=t){
            res = m;
            l=m+1;
        }
        else r=m-1;
    }
    cout << res << "\n";
    return 0;
}