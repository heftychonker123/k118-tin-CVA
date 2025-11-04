#include <bits/stdc++.h>
using namespace std;

vector<bool> sieve(long long n) {
    vector<bool> v(n + 1, true);
    v[0] = v[1] = false;
    for (long long i = 2; i * i <= n; i++) {
        if (v[i]) {
            for (long long j = i * i; j <= n; j += i)
                v[j] = false;
        }
    }
    return v;
}

long long calc(long long n) {
    long long ans = 0;
    vector<bool> primes = sieve(n);
    for (long long i = 0; i <= n; i++) {
        if (primes[i]) ans += i;
    }
    return ans;
}

bool check_prime(long long n) {
    if (n < 2) return false;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    long long n;
    cin >> n;
    long long t = calc(n);
    cout << (check_prime(t) ? "YES" : "NO") ;
}
