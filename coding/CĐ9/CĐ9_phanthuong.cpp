#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(ll n, ll k) {
    vector<bool> reward(n+1, true);
    reward[0] = false;
    for (ll i = 2; i <= k; i++) {
        for (ll j = i; j <= n; j += i) {
            reward[j] = false;
        }
    }

    ll res = 0;
    for (ll i = 1; i <= n; i++) {
        if (reward[i]) res++;
    }

    cout << res << "\n";
}

int main() {
    ll n, k;
    cin >> n >> k;
    solve(n, k);
    return 0;
}
