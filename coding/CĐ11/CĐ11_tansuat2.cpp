#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; 
    cin >> n;
    unordered_map<ll,ll> freq;
    vector<ll> order;

    for (ll i = 0; i < n; i++) {
        ll t; 
        cin >> t;
        if (freq.find(t) == freq.end()) {
            order.push_back(t);
        }
        freq[t]++;
    }

    for (ll x : order) {
        cout << x << " " << freq[x] << "\n";
    }

    return 0;
}
