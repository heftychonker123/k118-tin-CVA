#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());

    ll groups = 0;
    ll i = 0, j = n - 1;

    while (i <= j) {
        if (v[i] + v[j] <= k) {
            groups++;
            i++;
            j--;
        } else {
            groups++;
            j--;
        }
    }

    cout << groups;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
