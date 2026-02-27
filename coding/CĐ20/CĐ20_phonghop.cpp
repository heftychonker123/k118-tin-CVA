#include <bits/stdc++.h>
using namespace std;
#define filename "phonghop"
#define ll long long
#define vect vector

void IO(){
    if (fopen(filename".inp" , "r")){
        freopen(filename".inp" , "r" , stdin);
        freopen(filename".out" , "w" , stdout);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    IO();
    ll n ; cin >> n;
    vect<pair<ll,ll>> v(n);
    for (int i=0 ; i<n ; i++) cin >> v[i].first >> v[i].second;
    sort(
        v.begin() , v.end() ,  [&](auto a , auto b){
        if (a.first == b.first) return a.second < b.second;
        return a.first < b.first;}
    );
    vect<ll> dp(n);
    for (int i=0 ; i<n ; i++){
        dp[i] = 1;
        for (int j=1 ; j<i ; j++){
            if (v[j].second <= v[i].first && dp[i] < dp[j]+1){
                dp[i] = dp[j] + 1;
            }
        }
    }
    cout << dp[n-1] << "\n";
}