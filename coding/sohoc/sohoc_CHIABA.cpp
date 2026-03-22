#include <bits/stdc++.h>
using namespace std;
#define filename "CHIABA"
#define ll long long

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
    ll a,b ; cin >> a >> b;
    if ((b-a)%3!=0) cout << -1 << "\n";
    else{
        ll x = (b-a)/3 + a;
        ll y = b - (b-a)/3;
        cout << x << " " << y << "\n";
    }
    return 0;
}