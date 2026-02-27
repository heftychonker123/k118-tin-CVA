#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vect vector


void solve(){
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m,q;cin >> n >> m >> q;
    vect<vect<ll>> v(n , vect<ll>(m));
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++) cin >> v[i][j];
    }
    vect<vect<ll>> pref(n+1 , vect<ll>(m+1,0));
    for (int i=1 ; i<=n ; i++){
        for (int j=1 ; j<=m ; j++) pref[i][j] = v[i-1][j-1] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
    }
    while (q--){
        ll x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
        ll res=pref[x2][y2];
        res += pref[x1-1][y1-1];
        res -= pref[x1-1][y2];
        res -= pref[x2][y1-1];
        cout << res << "\n";
    }
    return 0;
}