#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(ll a, ll b , ll x , ll d){
    ll c = x*d / gcd(x,d);
    ll res1 = b/c - (a-1)/c;
    ll res2 = b/x - (a-1)/x;
    ll res3 = b/d - (a-1)/d;
    cout << b-a+1 + res1 - res2 - res3 << "\n";
}

int main(){
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    solve(a,b,c,d);
    return 0;
}
