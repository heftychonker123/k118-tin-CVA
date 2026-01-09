#include <bits/stdc++.h>
using namespace std;

#define filename "dayconnguyento"
#define ll long long
#define pb push_back
#define vect vector

// Sieve of Eratosthenes
vect<ll> prime_sieve(ll t) {
    vect<bool> v(t+1, true);
    v[0] = v[1] = false;
    for (ll i = 2; i * i <= t; i++) {
        if (v[i]) {
            for (ll j = i * i; j <= t; j += i) {
                v[j] = false;
            }
        }
    }
    vect<ll> res;
    for (ll i = 2; i <= t; i++) {
        if (v[i]) res.pb(i);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin >> n;
    vect<ll> v(n);
    for (ll i = 0; i < n; i++) cin >> v[i];

    ll t = *max_element(v.begin(), v.end());
    vect<ll> prime = prime_sieve(t);

    ll res = 0, temp = 0;
    for (const ll &i : v) {
        if (binary_search(prime.begin(), prime.end(), i)) {
            temp++;
        } else {
            res = max(res, temp);
            temp = 0;
        }
    }
    res = max(res, temp);

    cout << res << "\n";
    return 0;
}
