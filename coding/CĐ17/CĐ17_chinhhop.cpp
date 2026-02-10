#include <bits/stdc++.h>
using namespace std;
#define filename "chinhhop"
#define ll long long
#define pb push_back
#define vect vector
void arrange(ll n , ll k , vect<ll> sub = {}){
    if (sub.size() == k){
        for (const ll &i : sub) cout << i << " ";
        cout << "\n"; return;
    }
    for (int i=0 ; i<n ; i++){
        sub.pb(i+1);
        arrange(n,k,sub);
        sub.pop_back();
    }
    return;
}
void solve(){
    ll n,k ; cin >> n >> k;
    arrange(n,k);
}
void IO(){
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    IO();
    solve();
    return 0;
}