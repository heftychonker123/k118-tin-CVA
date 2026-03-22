#include <bits/stdc++.h>
using namespace std;
#define filename "cseq"
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
    vect<ll> prefix(n+1,0);
    for (int i=1 ; i<=n ; i++) prefix[i] = prefix[i-1] + v[i-1];
    //Maintain a running minimium
    ll maximium = prefix[0];
    ll res = LLONG_MIN;
    for (int i=1 ; i<=n ; i++){
        res = max(res , prefix[n] - 2*(prefix[i] - maximium));
        maximium = max(prefix[i] , maximium);
    }
    cout << res << "\n";
    return 0;
}