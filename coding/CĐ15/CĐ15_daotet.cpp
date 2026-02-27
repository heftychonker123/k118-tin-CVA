#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector

vect<vect<ll>> prefix_sum_2d(vect<vect<ll>> v , ll height , ll width){
    vect<vect<ll>> res(height+1 , vect<ll>(width+1,0));
    for (int i=1 ; i<=height ; i++){
        for (int j=1 ; j<=width ; j++){
            res[i][j] = v[i-1][j-1] 
                      + res[i-1][j] 
                      + res[i][j-1] 
                      - res[i-1][j-1];
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m ; cin >> n >> m;
    vect<vect<ll>> v(n , vect<ll>(m));
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cin >> v[i][j];
        }
    }
    vect<vect<ll>> presum = prefix_sum_2d(v , n , m);

    ll q; cin >> q;
    while (q--){
        ll x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);

        ll ans = presum[x2][y2]
               - presum[x1-1][y2]
               - presum[x2][y1-1]
               + presum[x1-1][y1-1];

        cout << ans << "\n";
    }
    return 0;
}
