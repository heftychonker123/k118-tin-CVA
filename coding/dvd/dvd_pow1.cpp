#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1000000007;

ll powmod(ll n, ll k) {
    if (k == 0) return 1;
    ll half = powmod(n, k / 2);
    ll res = (half * half) % mod;
    if (k % 2) res = (res * n) % mod;
    return res % mod;
}

signed main(){
    long long n,k ; cin >> n;
    k = n-1;
    cout << powmod(2LL,k);
}
