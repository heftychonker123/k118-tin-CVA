#include <bits/stdc++.h>
using namespace std;
#define filename "ODien"
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
    ll n,m ; cin >> n >> m;
    vect<ll> v(n); for (int i=0 ; i<n ; i++) cin >> v[i];
    sort(v.rbegin() , v.rend());
    ll res = 0;
    ll sum = 0;
    for (int i=0 ; i<n ; i++){
        sum += v[i];
        res++;
        if (sum >= m) break;
        sum --;
    }
    if (sum < m) cout << -1 << "\n";
    else cout << res;
    return 0;
}