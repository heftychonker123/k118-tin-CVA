#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector
bool run = true;
void sinh(vect<ll> &v , ll n , ll k){
    ll t = k-1;
    while (t>=0 && v[t] > n-k+t) t--;
    if (t<0){
        run = false; return;
    }
    v[t]++;
    for (int i=t+1 ; i<k ; i++){
        v[i] = v[i-1] + 1;
    }
}
void solve(){
    ll n,k ; cin >> n >> k;
    vect<ll> v(k);
    for (int i=0 ; i<k ; i++) v[i] = i+1;
    while (run){
        for (const ll &i : v) cout << i << " ";
        cout << "\n";
        sinh(v,n,k);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}