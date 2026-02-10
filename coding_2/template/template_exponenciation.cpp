#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;

// Calculate a^n % MOD
ll binary_exp(ll a, ll n) {
    ll res = 1;
    a %= MOD;
    while (n > 0) {
        if (n %2 == 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        n /= 2;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; 
    cin >> n;
    ll res = binary_exp(2, n);
    cout << res;
    return 0;
}
