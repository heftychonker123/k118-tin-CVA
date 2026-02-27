#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll mulmod(ll a, ll b, ll t) {
    return ((a%t)*(b%t))%t;
}

int main(){
    ll n, t;
    cin >> n >> t;
    
    ll res = 1;
    
    while(n--){
        ll temp;
        cin >> temp;
        res = mulmod(res,temp,t);
    }
    
    cout << res << "\n";
    
    return 0;
}