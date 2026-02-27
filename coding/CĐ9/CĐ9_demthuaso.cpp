#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(ll n){
    ll res = 0;

    // Check factor 2
    if (n % 2 == 0) {
        res++;
        while (n % 2 == 0) {
            n /= 2;
        }
    }

    // Check odd factors
    for (ll i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            res++;
            while (n % i == 0) {
                n /= i;
            }
        }
    }

    // If n is still > 2, it's prime
    if (n > 2) res++;

    cout << res << "\n";
}

int main(){
    int t; cin >> t;
    while (t--){
        ll n; cin >> n;
        solve(n);
    }
    return 0;
}
