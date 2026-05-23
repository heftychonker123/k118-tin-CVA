#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vect vector

signed main(){
    freopen("cau3.inp" , "r" , stdin);
    freopen("cau3.out" , "w" , stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n ; cin >> n;
    unordered_map<ll,ll> m; ll sum = 0;
    for (int i = 0 ; i<n*n ; i++){
        ll t ; cin >> t;
        m[t]++; sum += t;
    }
    ll res = 0;
    for (auto [a,b] : m) res = max(res , sum - a*b);

    cout << res;
}
