#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<ll,ll> normalize(ll num, ll den) {
    ll g = gcd(num, den);
    num /= g;
    den /= g;
    if (den < 0) {
        num = -num;
        den = -den;
    }
    return {num, den};
}

int main() {
    freopen("SXPS.inp" , "r" , stdin);
    freopen("SXPS.out" , "w" , stdout);
    ll n, k;
    cin >> n >> k;

    set<pair<ll,ll>> s;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            s.insert(normalize(j, i));
        }
    }

    vector<pair<ll,ll>> v(s.begin(), s.end());
    sort(v.begin(), v.end(), [&](auto a, auto b){
        return a.first * b.second < b.first * a.second;
    });

    cout << v[k-1].first << "/" << v[k-1].second;
    return 0;
}
