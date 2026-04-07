#include <bits/stdc++.h>
using namespace std;
#define filename "tongsnt"
#define ll                  long long
#define llmin               LLONG_MIN
#define llmax               LLONG_MAX
#define pb                  push_back
#define vect                vector
#define FOR(i , m , n)      for (ll i=m ; i<n ; i++)
#define FOR_r(i , m , n)    for (ll i=m ; i>n ; i--)
const ll MODULO  = 1e9 + 7;
vect<ll> sieve(ll n){
    vect<bool> primality(n+1 , true);
    vect<ll> prime;
    FOR(i , 2 , n+1){
        if (primality[i]){
            prime.push_back(i);
            for (ll j=i*i ; j<=n ; j+=i) primality[j] = false;
        }
    }
    return prime;
}

vect<ll> prefix_sum(vect<ll> v){
    vect<ll> pref(v.size()+1 , 0);
    FOR(i , 1 , v.size()+1) pref[i] = pref[i-1] + v[i-1];
    return pref;
}
void IO(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen(filename".inp" , "r"))
    {
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    }
}
signed main(){
    IO();
    vect<ll> prime = sieve(1e6);
    vect<ll> pref1 = prefix_sum(prime);
    vect<ll> coef(prime.size());
    FOR(i , 0 , prime.size()) coef[i] = prime[i] * (i+1);
    vect<ll> pref2 = prefix_sum(coef);

    ll t ; cin >> t;
    FOR(i , 0 , t){
        ll l,r ; cin >> l >> r;
        ll left = lower_bound(prime.begin(), prime.end(), min(l,r)) - prime.begin();
        ll right = upper_bound(prime.begin(), prime.end(), max(l,r)) - prime.begin();
        cout << (pref2[right] - pref2[left] - left * (pref1[right] - pref1[left]))%MODULO << "\n";
    }
    return 0;
}