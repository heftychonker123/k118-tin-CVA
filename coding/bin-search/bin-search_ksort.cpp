#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll kthElement(const vector<ll>& a, const vector<ll>& b, ll k) {
    ll n = a.size(), m = b.size();
    assert(k >= 1 && k <= n + m);  // catch bad input early

    ll l = max(0LL, k - m), r = min(k, n);

    while (l <= r) {
        ll mid1 = l + (r - l) / 2;
        ll mid2 = k - mid1;

        ll l1 = (mid1 == 0) ? LLONG_MIN : a[mid1 - 1];
        ll l2 = (mid2 == 0) ? LLONG_MIN : b[mid2 - 1];
        ll r1 = (mid1 == n) ? LLONG_MAX : a[mid1];
        ll r2 = (mid2 == m) ? LLONG_MAX : b[mid2];

        if (l1 <= r2 && l2 <= r1) return max(l1, l2);
        else if (l1 > r2)         r = mid1 - 1;
        else                      l = mid1 + 1;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    //cout << kthElement(a, b, k) << "\n";
}
