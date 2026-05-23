#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll c[50];
ll findnum(ll n , ll k){
    if (k == (c[n]+1)/2) return n;
    else if (k < (c[n]+1)/2) return findnum(n-1 , k);
    else return findnum(n-1 , k - (c[n]+1)/2);
}
signed main(){
    ll n,k ; cin >> n >> k;
    c[0] = 0;
    for (int i = 1 ; i<=n ; i++) c[i] = c[i-1]*2 + 1;
    cout << findnum(n , k);
}