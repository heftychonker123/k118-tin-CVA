#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(ll n){
    vector<bool> prime(n+1 , true);
    vector<ll> v;
    for (int i=2 ; i<=n ; i++){
        if (prime[i]){
            for (int j=i*i ; j<= n ; j+=i){
                prime[j] = false;
            }
            v.push_back(i);
        }
    }
    ll res=0;
    for (int i=0 ; i<v.size() ; i++){
        auto it = upper_bound(v.begin() , v.end() , n/v[i]);
        if (it==v.begin()) continue;
        else{
            it--;
            res = max(res , *it * v[i]);
        }
    }
    cout << res;
    return;
}
int main(){
    //freopen("bai2.inp" , "r" , stdin);
    //freopen("bai2.out" , "w" , stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; 
    cin >> n;
    solve(n);
    return 0;
}
