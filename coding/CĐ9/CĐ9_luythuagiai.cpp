#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Function to compute exponent of prime p in n!
void solve(ll n, ll p) {
    ll res = 0;
    while (n > 0) {
        n /= p;
        res += n;
    }
    cout << res << "\n";
}

int main() {
    int t; cin >> t;
    for (int tc=0 ; tc<t ; tc++){
        ll n, p;
        cin >> n >> p;
        solve(n, p);
    }
    return 0;
}
