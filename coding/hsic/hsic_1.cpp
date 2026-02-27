#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n ; cin >> n;
    vector<pair<ll,ll>> v(n);
    for (int i=0 ; i<n ; i++){
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin() , v.end());
    set<pair<ll,ll>> s;
    for (int i=0 ; i<n-1 ; i++){
        
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}