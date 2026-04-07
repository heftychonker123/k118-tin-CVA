#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, p;
    cin >> n >> m >> p;
    vector<ll> g;

    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        g.push_back(b - (a - 1));
    }

    sort(g.begin(), g.end());

    
    ll ans = g[m - 1];
    if (ans < 0) ans = 0; 
    cout << ans;
    return 0;
}
