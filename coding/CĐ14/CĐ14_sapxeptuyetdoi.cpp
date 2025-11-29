#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin >> n;
    vect<pair<ll,ll>> v;
    vect<ll> nums;
    v.reserve(n);

    for (int i = 0; i < n; i++) {
        ll t; cin >> t;
        nums.push_back(t);
        v.push_back({abs(t), i});
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        cout << nums[(v[i]).second];
        if (i != n - 1) cout << " ";
    }
    cout << "\n";
    return 0;
}
