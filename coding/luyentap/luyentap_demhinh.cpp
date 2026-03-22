#include <bits/stdc++.h>
using namespace std;
#define filename "DEMHINH"
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
    ll n ; cin >> n;
    map<ll,ll> freq;
    for (int i=0 ; i<n ; i++){
        ll t ; cin >> t ; freq[t]++;
    }
    ll cnt = 0;
    for (const auto [i, frequency] : freq){
        cnt += frequency/4;
    }
    cout << cnt << "\n";
    return 0;
}