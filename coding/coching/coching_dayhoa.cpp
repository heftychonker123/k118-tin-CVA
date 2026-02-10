#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n, x;
    cin >> n >> x;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<ll> l(n+1), r(n+2), s(n+1);

    for (int i = 1; i <= n; i++) {
        l[i] = max(l[i-1] + v[i-1], v[i-1]);
    }

    for (int j = n-1; j >= 0; j--) {
        r[j] = max(r[j+1] + v[j], v[j]);
    }

    for (int i = 1; i <= n; i++) {
        s[i] = s[i-1] + v[i-1];
    }

    ll res = LLONG_MIN;
    ll i = 1, j = 1;

    while (j <= n) {
        j++;
        ll temp = LLONG_MIN;
        while (i <= n && (l[i-1] - s[i-1]*x) + (s[j]*x + r[j]) > temp) {
            temp = (l[i-1] - s[i-1]*x) + (s[j]*x + r[j]);
            i++;
        }
        res = max(res, temp);
    }

    cout << res;
}
