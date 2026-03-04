#include <bits/stdc++.h>
using namespace std;
#define filename "thuemay"
#define ll long long
#define pb push_back
#define vect vector
struct Mac{
    ll a , b , c;
};
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
    vect<Mac> v(n);
    for (int i=0 ; i<n ; i++){
        cin >> v[i].a >> v[i].b >> v[i].c;
    }
    sort(v.begin() , v.end() , [&](auto x , auto y){
        if (x.a == y.a && y.a == y.b) return x.c < y.c;
        else if (x.a == y.a) return x.b < y.b;
        return x.a < y.a;
    });

    vect<ll> dp(n);
    vect<ll> trace(n);
    for (int i = 0 ; i<n ; i++){
        trace[i] = -1;
        dp[i] = v[i].c;
        for (int j = 0 ; j<i ; j++){
            if (v[i].a > v[j].b && dp[j] + v[i].c > dp[i]){
                dp[i] = dp[j] + v[i].c;
                trace[i] = j;
            }
        }
    }
    
    auto it = max_element(dp.begin() , dp.end());
    ll maxPos = it - dp.begin();
    ll cnt = 0;
    while (maxPos != -1) {
        cnt++;
        maxPos = trace[maxPos];
    }
    cout << cnt << " " << *it;
}