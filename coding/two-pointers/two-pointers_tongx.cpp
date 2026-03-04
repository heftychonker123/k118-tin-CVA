#include <bits/stdc++.h>
using namespace std;
#define filename "tongx"
#define ll long long
#define vect vector
void solve(){
    ll n, k ; cin >> n >> k;
    vect<ll> v(n); for(int i=0 ; i<n ; i++) cin >> v[i];
    ll sum=0;
    ll res=0;
    for (int i=0 , j=0 ; j<n ; j++){
        sum+=v[j];
        while (sum > k){
            sum -= v[i];
            i++;
        }
        if (sum==k) res++;
    }
    cout << res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}