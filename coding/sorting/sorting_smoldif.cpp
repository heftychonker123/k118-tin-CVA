#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector

int main() {
    ll n; cin >> n;
    vect<ll> s;
    for (int i = 0; i < n; i++) {
        ll t; cin >> t;
        s.push_back(t);
    }
    sort(s.begin() , s.end());
    ll res = LLONG_MAX;
    for (int i=0 ; i<n-1 ; i++){
        res = min(abs(s[i]-s[i+1]) , res); 
    }
    if (res == LLONG_MAX) cout << 0;
    else cout << res;
    return 0;
}
