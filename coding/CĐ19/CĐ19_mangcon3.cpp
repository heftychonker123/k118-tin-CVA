#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector

void solve() {
    ll n, k;
    cin >> n >> k;
    vect<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    map<ll, ll> freq;
    ll cnt = 0;
    ll i = 0;

    for (ll j = 0; j < n; j++) {
        freq[v[j]]++;
        while (freq.size() > k) {
            if (--freq[v[i]] == 0) {
                freq.erase(v[i]);
            }
            i++;
        }
        cnt += (j - i + 1);
    }

    cout << cnt << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
