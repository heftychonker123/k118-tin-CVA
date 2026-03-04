#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n, x; cin >> n >> x;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    int i = 0, j = 1;
    while (i < n && j < n) {
        ll diff = v[j] - v[i];
        if (diff == x) {
            cout << 1;
            return 0;
        }
        if (diff < x) {
            j++;
        } else {
            i++;
            if (i == j) j++;
        }
    }
    cout << 0;
    return 0;
}
