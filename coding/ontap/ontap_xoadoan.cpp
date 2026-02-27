#include <bits/stdc++.h>
using namespace std;
#define filename "XOADOAN"
#define ll long long
#define vect vector
#define str string

void IO(){
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
}

void solve(){
    ll n; cin >> n;
    vect<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    ll m; cin >> m;

    vect<ll> pref(n+1, 0);
    for (int i = 0; i < n; i++) {
        pref[i+1] = v[i] + pref[i];
    }

    ll sum = pref[n];
    ll res = LLONG_MAX; 

    for (int i = 0; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            if (pref[j] - pref[i] >= sum - m) {
                res = min(res, (ll)j - i);
            }
        }
    }

    cout << res << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //IO();
    solve();
    return 0;
}
