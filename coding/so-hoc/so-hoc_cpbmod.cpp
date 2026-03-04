#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll m,n,k ; cin >> m >> n >> k;
    ll MOD=1;
    ll res = 1;
    for (int i=0 ; i<k ; i++) MOD*=10;
    for (int i=0 ; i<n ; i++){
        res *= m;
        res %= MOD;
    }
    string s = to_string(res);
    while (s.size() < k) s = '0' + s;
    cout << s;
    return 0;
}