#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, x; 
    cin >> n >> x;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    unordered_map<ll,ll> freq;
    freq[0] = 1;
    ll sum = 0, res = 0;

    for (int i = 0; i < n; i++) {
        sum += v[i];
        res += freq[sum - x];
        freq[sum]++;
    }

    cout << res << "\n";
    return 0;
}
