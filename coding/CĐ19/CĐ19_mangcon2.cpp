#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector

void solve() {
    ll n, s;
    cin >> n >> s;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll sum = 0;
    ll j = 0;
    ll res = 0;

    for (ll i = 0; i < n; i++) {
        if (i > 0) sum -= a[i-1];

        while (j < n && sum < s) {
            sum += a[j];
            j++;
        }

        if (sum >= s) {
            res += (n - j + 1);
        }
    }
    cout << res << "\n";
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}