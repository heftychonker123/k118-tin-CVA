#include <bits/stdc++.h>
using namespace std;
#define filename "cophieu"
#define ll                  long long
#define llmin               LLONG_MIN
#define llmax               LLONG_MAX
#define pb                  push_back
#define vect                vector
#define FOR(i , m , n)      for (int i=m ; i<n ; i++)
#define FOR_r(i , m , n)    for (int i=m ; i>n ; i--)
void IO(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen(filename".inp" , "r"))
    {
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    }
}
int main(){
    IO();
    ll n ; cin >> n;
    vect<ll> v(n) ; FOR(i , 0 , n) cin >> v[i];
    vect<ll> p(n); p[n-1] = 0;
    ll runningMax = v[n-1] , profit = 0;
    FOR_r(i , n-2 , -1){
        if (v[i] < runningMax) profit += runningMax - v[i];
        runningMax = max(runningMax , v[i]);
        p[i] = profit;
    }
    ll q ; cin >> q;
    while (q--){
        ll t ; cin >> t; cout << p[t-1] << "\n";
    }
    return 0;
}