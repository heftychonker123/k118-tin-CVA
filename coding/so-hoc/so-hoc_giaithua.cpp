#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(ll n, ll t) {
    ll res = 1 % t;
    for (ll i = 2; i <= n; i++) {
        res = (res * (i % t)) % t;
    }
    cout << res;

}

int main() {
    ll n, t;
    cin >> n >> t;
    solve(n, t);
    return 0;
}
