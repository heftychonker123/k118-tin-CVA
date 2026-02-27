#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool isSphenic(ll n) {
    unordered_map<ll, ll> freq;

    // Factor 2
    while (n % 2 == 0) {
        n /= 2;
        freq[2]++;
    }

    // Odd factors
    for (ll i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            n /= i;
            freq[i]++;
        }
    }

    // Remaining prime
    if (n > 2) freq[n]++;

    // Must have exactly 3 distinct primes
    if (freq.size() != 3) return false;

    // Each prime must appear exactly once
    for (auto &p : freq) {
        if (p.second > 1) return false;
    }

    return true;
}

int main() {
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        cout << (isSphenic(n) ? 1 : 0) << "\n";
    }
    return 0;
}
