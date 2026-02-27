#include <bits/stdc++.h>
using namespace std;
#define filename "dayconsocong"
#define ll long long
#define ld long double
#define llmin LLONG_MIN
#define pb push_back
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
    vect<ll> v(n);
    for (int i=0 ; i<n ; i++) cin >> v[i];
    ll dp[n][(ll)5e3];
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<5e3 ; j++) dp[i][j] = 1;
    }

    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<i ; j++){
            if (v[i] > v[j]) dp[i][v[i] - v[j]] = max(dp[i][v[i] - v[j]] , dp[j][v[i] - v[j]] + 1);
        }
    }
    
    ll res = llmin;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<5e3 ; j++) res = max(res , dp[i][j]);
    }
    cout << (res > 1 ? res : 0) << "\n";
    return 0;
}
