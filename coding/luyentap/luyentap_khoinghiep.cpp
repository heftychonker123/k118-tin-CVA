#include <bits/stdc++.h>
using namespace std;
#define filename "khoinghiep"
#define ll long long
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
    vect<pair<ll,ll>> v(n); for (int i=0 ; i<n ; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin() , v.end());
    ll cnt = 0;
    ll cost = 0;
    for (const auto [a,b] : v){
        if (cnt < a) cost += b;
        cnt++;
    }
    cout << cost << "\n";
    return 0;
}