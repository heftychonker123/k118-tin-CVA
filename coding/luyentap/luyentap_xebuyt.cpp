#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector
#define FOR(i,m,n) for(int i=m;i<n;i++)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m,p; cin >> n >> m >> p;
    vect<vect<ll>> stations(p);

    FOR(i,0,n){
        ll a,b; cin >> a >> b;
        stations[a-1].push_back(b);
    }

    FOR(i,0,p) sort(stations[i].begin(), stations[i].end());

    ll res=-1;
    ll l=0, r=1e9+1;
    while(l<=r){
        ll mid = l+(r-l)/2;
        ll pass=0;
        FOR(i,0,p){
            ll arrival = mid+i;
            ll pos = upper_bound(stations[i].begin(), stations[i].end(), arrival) - stations[i].begin();
            pass += pos;
        }
        if(pass>=m){
            res=mid;
            r=mid-1;
        } else {
            l=mid+1;
        }
    }
    cout << res << "\n";
    return 0;
}
