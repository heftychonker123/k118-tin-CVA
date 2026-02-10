#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vect vector

vect<ll> preprocess(ll limit){
    const ll blockSize = 1e6;
    vect<ll> prime;
    vect<bool> pre_primality(blockSize+1, true);

    for (ll i = 2; i <= blockSize; i++) {
        if (pre_primality[i]) {
            prime.pb(i);
            for (ll j = i*i; j <= blockSize; j += i) {
                pre_primality[j] = false;
            }
        }
    }

    ll k = 1;
    while (prime.back() < limit) {
        ll curr = k * blockSize;
        vect<bool> primality(blockSize, true);

        for (ll p : prime) {
            ll start = max(p*p, ((curr + p - 1)/p) * p);
            for (ll j = start; j < curr + blockSize; j += p) {
                primality[j - curr] = false;
            }
        }

        for (int i = 0; i < blockSize; i++) {
            if (primality[i]) {
                prime.pb(curr + i);
            }
        }
        k++;
    }
    return prime;
}

void solve(){
    ll t; cin >> t;
    vect<ll> queries(t);
    ll maxN = 0;
    for (int i=0; i<t; i++){
        cin >> queries[i];
        maxN = max(maxN, queries[i]);
    }

    vect<ll> prime = preprocess(cbrt(maxN) * 5);

    vect<ll> product;
    for (int i = 2; i < prime.size(); i++) {
        __int128 val = (__int128)prime[i] * prime[i-1] * prime[i-2];
        if (val > maxN) break;
        product.pb((ll)val);
    }

    for (ll n : queries) {
        auto it = upper_bound(product.begin(), product.end(), n);
        if (it == product.begin()) {
            cout << -1 << "\n";
        } else {
            --it;
            cout << *it << "\n";
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
