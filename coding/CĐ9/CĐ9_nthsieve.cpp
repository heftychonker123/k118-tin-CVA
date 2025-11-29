#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector

void solve(ll n) {
    // Upper bound estimate for nth prime ~ n log n
    ll limit = max(15LL, (ll)(n * log2(n) + 10));
    vect<bool> v(limit, true);

    v[0] = false; // 1 is not prime
    v[1] = false; // 2nd element (number 2) is prime, so keep true

    for (ll i = 2; i * i <= limit; i++) {
        if (v[i]) {
            for (ll j = i * i; j < limit; j += i) {
                v[j] = false;
            }
        }
    }

    vect<ll> primes;
    for (ll i = 2; i < limit && primes.size() < n; i++) {
        if (v[i]) primes.push_back(i);
    }

    for (ll p : primes) {
        cout << p << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    solve(n);
    return 0;
}
