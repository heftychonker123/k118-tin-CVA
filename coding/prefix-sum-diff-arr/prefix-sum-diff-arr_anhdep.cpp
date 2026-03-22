#include <bits/stdc++.h>
using namespace std;
#define filename "anhdep"
#define ll long long
#define vect vector

void IO(){
    if (fopen(filename".inp" , "r"))
    {
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    IO();
    ll n ; cin >> n;
    vect<ll> v(n); for (int i=0 ; i<n ; i++) cin >> v[i];
    vect<ll> p(n+1,0); for (int i=1 ; i<=n ; i++) p[i] = p[i-1]+v[i-1];
    vect<ll> mn(n+1);
    mn[0]=p[0] ; mn[1] = p[1];
    for (int i=2 ; i<=n ; i++) mn[i] = min(p[i] , mn[i-2]);
    ll res = LLONG_MIN;
    for (int i=4 ; i<=n ; i++){
        res = max(res , p[i] - mn[i-4]);
    } 
    cout << res << "\n";
    return 0;
}   