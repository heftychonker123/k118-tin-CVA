#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector

void solve(ll l, ll r) {
    ll res=0;
    vector<ll> sigma(r+1, 0);
    for (ll i=1; i<=r; i++) {
        for (ll j=i; j<=r; j+=i) {
            sigma[j] += i;
        }
    }
    for (int i=l ; i<=r ; i++){
        if (sigma[i]>2*i){
            res++;
        }
    }
    cout << res ; return;
}

int main() {
    ll l, r;
    cin >> l >> r;
    solve(l, r);
    return 0;
}
