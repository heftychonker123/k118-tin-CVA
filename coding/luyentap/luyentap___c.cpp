#include <bits/stdc++.h>
using namespace std;
#define filename "ddc"
#define ll                  long long
#define llmin               LLONG_MIN
#define llmax               LLONG_MAX
#define pb                  push_back
#define vect                vector
#define FOR(i , m , n)      for (int i=m ; i<n ; i++)
#define FOR_r(i , m , n)    for (int i=m ; i>n ; i--)
void IO(){
    if (fopen(filename".inp" , "r"))
    {
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    }
}
bool prime(ll n){
    if (n<2) return false;
    if (n==2) return true;
    for  (int i=2 ; i*i <= n ; i++){
        if (n%i==0) return false;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    IO();
    ll n,s ; cin >> n >> s;
    ll dp[2][n];
    FOR(i , 0 , n){
        ll t ; cin >> t;
        dp[0][i]=0 ; dp[1][i] = 0;
        if (i>=s){
            if (prime(t)) dp[1][i] = dp[0][i-s] + 1;
            else if (t==1){
                dp[0][i] = dp[0][i-s];
                dp[1][i] = dp[1][i-s];
            }
        }
    }
    cout << *max_element(dp[1] , dp[1]+n);
    return 0;
} 