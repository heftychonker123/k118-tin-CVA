#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define vect vector

int main() {
    ll n, l; 
    cin >> n >> l;
    vect<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());

    ld res = max((ld)v[0], (ld)(l - v.back()));

    for (int i = 0; i < n - 1; i++) {
        ld gap = v[i+1] - v[i];
        res = max(res, gap / 2.0);
    }

    cout << fixed << setprecision(10) << res;
    return 0;
}
