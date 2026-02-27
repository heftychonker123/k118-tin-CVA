#include <bits/stdc++.h>
using namespace std;
#define filename "nhaybac"
#define ll long long
#define ld long double
#define str string
#define pb push_back
#define vect vector
const ll MODULO = 1e9 + 7;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,k ; cin >> n >> k;
    vect<ll> dp(n+1 , 0);
    set<ll> broken;
    while (k--){
        ll t ; cin >> t;
        broken.insert(t);
    }
    dp[1] = 1;
    for (int i=2 ; i<=n ; i++){
        if (broken.find(i) != broken.end()){
            dp[i] = 0;
            continue;
        }
        ll once = dp[i-1] , twice = dp[i-2];
        dp[i] = (once + twice)%MODULO;
    }
    cout << dp[n]%MODULO;
    return 0;
}