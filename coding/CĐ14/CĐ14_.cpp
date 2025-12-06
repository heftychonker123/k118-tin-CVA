#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, x; cin >> n >> x;
    vector<ll> a(n), b(x);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < x; i++) cin >> b[i];

    sort(b.begin(), b.end()); // sort b for binary search

    for (const ll &val : a) {
        auto it = upper_bound(b.begin(), b.end(), val);
        cout << (b.end() - it) << " ";
    }
    cout << "\n";
    return 0;
}
