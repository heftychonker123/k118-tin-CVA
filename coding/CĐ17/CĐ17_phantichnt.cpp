#include <bits/stdc++.h>
using namespace std;
#define filename "phantichnt"
#define ll long long
#define vect vector

vect<ll> sieve(int limit) {
    vect<bool> isPrime(limit+1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i*i <= limit; i++) {
        if (isPrime[i]) {
            for (int j = i*i; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }
    vect<ll> primes;
    for (int i = 2; i <= limit; i++) {
        if (isPrime[i]) primes.push_back(i);
    }
    return primes;
}

void factor(ll n, const vect<ll> &prime, vect<ll> &ans, int idx=0) {
    if (n == 1) return;
    if (idx == (int)prime.size()) {
        ans.push_back(n);
        return;
    }
    if (n % prime[idx] == 0) {
        ans.push_back(prime[idx]);
        factor(n/prime[idx], prime, ans, idx);
    } else {
        factor(n, prime, ans, idx+1);
    }
}

void solve() {
    ll n; cin >> n;
    vect<ll> prime = sieve(1000);
    vect<ll> res;
    factor(n, prime, res);
    for (ll p : res) cout << p << " ";
    cout << "\n" << accumulate(res.begin() , res.end() , 0);
    cout << "\n";
}

void IO() {
    freopen(filename".inp", "r", stdin);
    freopen(filename".out", "w", stdout);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    IO();
    solve();
    return 0;
}
