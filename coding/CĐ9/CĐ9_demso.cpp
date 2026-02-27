#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(ll a, ll b , ll c){
    ll res = b/c - (a-1)/c;
    cout << b-a+1 - res << "\n";
}

int main(){
    ll a,b,c;
    cin >> a >> b >> c;
    solve(a,b,c);
    return 0;
}
