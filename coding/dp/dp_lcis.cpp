#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int j = 0; j < m; j++) cin >> b[j];

    vector<ll> dp(m, 0); // dp[j] = length of LCIS ending at b[j]

    for (int i = 0; i < n; i++) {
        ll current = 0;
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j]) {
                dp[j] = max(dp[j], current + 1);
            }
            if (a[i] > b[j]) {
                current = max(current, dp[j]);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << "\n";
    return 0;
}
