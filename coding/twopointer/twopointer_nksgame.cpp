#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll i = 0, j = n - 1;
    ll res = LLONG_MAX;

    while (i < n && j >= 0) {
        ll sum = a[i] + b[j];
        res = min(res, abs(sum));

        if (sum > 0) j--;
        else i++;
    }

    cout << res;
    return 0;
}
