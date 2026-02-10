#include <bits/stdc++.h>
using namespace std;
#define filename "tkkb"
#define ll long long
#define vect vector
void solve(){
    ll n,m ; cin >> n >> m;
    vect<ll> a(n); for (int i=0 ; i<n ; i++) cin >> a[i];
    vect<ll> b(m); for (int i=0 ; i<m ; i++) cin >> b[i];
    sort(a.begin() , a.end());
    sort(b.begin() , b.end());

    ll ptrB = 0;
    ll res = 0;
    for (ll ptrA = 0 ; ptrA<n ; ptrA++){
        if (a[ptrA] > b[ptrB]){
            res++; ptrB++;
        }
    }
    cout << res; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}