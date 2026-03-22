#include <bits/stdc++.h>
using namespace std;
#define filename "xt"
#define ll long long
#define vect vector

void IO(){
    if (fopen(filename".inp" , "r"))
    {
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    }
}
bool prime(ll n){
    if (n==1 || n==0) return false;
    if (n==2) return true;
    for (int i=2 ; i*i <= n ; i++){
        if (n%i==0) return false;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    IO();
    ll n ; cin >> n;
    vect<ll> v(n); for (int i=0 ; i<n ; i++) cin >> v[i];
    vect<ll> dp(n+1 , 1);
    for (int i=1 ; i<=n ; i++){
        for (int j=1 ; j<=6 ; j++){
            if (i-j-1 >= 0 && prime(abs(v[i-1] - v[i-j-1]))){
                dp[i] = max(dp[i] , dp[i-j] + 1);
            }
        }
    }
    cout << *max_element(dp.begin() , dp.end());
    return 0;
}