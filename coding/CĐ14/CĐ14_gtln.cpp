#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n, k; 
    cin >> n >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    ll res = v[0];
    vector<ll> rest(v.begin() + 1, v.end());
    sort(rest.rbegin(), rest.rend());
    for (int i = 0; i < k && i < (int)rest.size(); i++) {
        res += rest[i];
    }
    for (int i = k; i < (int)rest.size(); i++) {
        res -= rest[i];
    }

    cout << res;
}
