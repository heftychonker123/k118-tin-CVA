#include <bits/stdc++.h>
using namespace std;
#define filename "tangmt"
#define ll long long
#define vect vector

void solve() {
    ll n, m, k; 
    cin >> n >> m >> k;
    vect<ll> a(n), b(m);
    for (ll i = 0; i < n; i++) cin >> a[i];
    for (ll i = 0; i < m; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll ptrA = 0, res = 0;
    for (ll ptrB = 0; ptrB < m; ptrB++) {
        while (ptrA < n && a[ptrA] < b[ptrB] - k) {
            ptrA++;
        }
        if (ptrA < n && abs(a[ptrA] - b[ptrB]) <= k) {
            res++;
            ptrA++;
        }
    }
    cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
