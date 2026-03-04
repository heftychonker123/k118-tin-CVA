#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll d;
    cin >> n >> d;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<double> T(n);
    for (int i = 0; i < n; i++) {
        T[i] = (i) + (double)d / v[i];
    }

    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (T[i] < T[j]) cnt++;
        }
    }

    cout << cnt << "\n";
    return 0;
}
