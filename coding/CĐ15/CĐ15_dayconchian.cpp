#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin >> n;
    vector<ll> v(n);
    for (int i=0; i<n; i++) cin >> v[i];

    ll sum = 0, res = 0;
    map<ll,ll> freq;
    freq[0] = 1;
    for (int i=0; i<n; i++){
        sum += v[i];
        ll r = ((sum % n) + n) % n;
        res += freq[r];
        freq[r]++;
    }

    cout << res << "\n";
    return 0;
}
