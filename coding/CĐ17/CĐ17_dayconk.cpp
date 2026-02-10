#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector

void in_kq(vect<ll> &sub) {
    cout << "[";
    for (int i = 0; i < sub.size(); i++) {
        cout << sub[i];
        if (i + 1 < sub.size()) cout << " ";
    }
    cout << "]\n";
}

void solve(ll n, ll s, vect<ll> &v, ll idx = 0, vect<ll> sub = {}) {
    if (s == 0) {
        in_kq(sub);
        return;
    }
    if (idx == n) return; 

    if (s - v[idx] >= 0) {
        sub.push_back(v[idx]);
        solve(n, s - v[idx], v, idx + 1, sub);
        sub.pop_back();
    }

    solve(n, s, v, idx + 1, sub);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, s;
    cin >> n >> s;
    vect<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin() , v.end());
    solve(n, s, v);
    return 0;
}
