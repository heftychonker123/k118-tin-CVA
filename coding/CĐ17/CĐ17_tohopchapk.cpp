#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector
void solve(ll n , ll k , vect<ll> sub = {} , ll idx = 0){
    if (sub.size() == k){
        for (const ll &i : sub) cout << i << " ";
        cout << "\n"; return;
    }
    else if (idx==n) return;
    for (int i=idx+1 ; i<=n ; i++){
        sub.push_back(i);
        solve(n , k , sub , i);
        sub.pop_back();
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n , k ; cin >> n >> k;
    solve(n , k);
    return 0;
}