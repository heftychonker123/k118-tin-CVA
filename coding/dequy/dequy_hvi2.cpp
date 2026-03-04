#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector

void solve() {
    ll n; cin >> n;
    vect<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    ll cnt = 0;
    while (true) {
        cnt++;

        ll i = n - 1;
        while (i > 0 && v[i-1] <= v[i]) i--;

        if (i == 0) break; 

        ll j = n - 1;
        while (v[j] >= v[i-1]) j--;

        swap(v[i-1], v[j]);

        reverse(v.begin() + i, v.end());
    }

    cout << cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
