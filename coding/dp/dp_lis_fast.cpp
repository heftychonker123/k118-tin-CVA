#include <bits/stdc++.h>
using namespace std;
#define ll long long

int find_lis(vector<ll> &v){
    vector<ll> dp;
    for (const ll &i : v){
        int pos = lower_bound(dp.begin() , dp.end() , i) - dp.begin();
        if (pos == dp.size()){
            dp.push_back(i);
        }
        else dp[pos] = i;
    }
    return dp.size();
}

int main(){
    ll n ; cin >> n;
    vector<ll> v(n); for (int i=0 ; i<n ; i++) cin >> v[i];
    cout << find_lis(v);
}