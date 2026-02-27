#include <bits/stdc++.h>
using namespace std;
#define filename "tower"
#define ll long long
#define pb push_back
void IO() {
    if (fopen(filename".inp", "r")) {
        freopen(filename".inp", "r", stdin);
        freopen(filename".out", "w", stdout);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    IO();
    ll n; cin >> n;
    vector<array<ll,3>> v;
    for (int i = 0; i < n; i++) {
        ll a, b, c; cin >> a >> b >> c;
        ll h = min({a,b,c});
        ll l = max({a,b,c});
        ll w = a+b+c - h - l;
        v.pb({h, w, l});
    }
    sort(v.begin(), v.end(), [&](auto &a, auto &b){
        if (a[2] != b[2]) return a[2] < b[2];
        if (a[1] != b[1]) return a[1] < b[1];
        return a[0] < b[0];
    });
    
    vector<ll> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i] = v[i][0];
        for (int j = 0; j < i; j++) {
            if (v[j][1] < v[i][1] && v[j][2] < v[i][2]) {
                dp[i] = max(dp[i], dp[j] + v[i][0]);
            }
        }
    }
    cout << *max_element(dp.begin(), dp.end());
    return 0;
}