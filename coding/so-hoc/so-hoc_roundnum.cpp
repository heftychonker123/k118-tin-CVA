#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vect vector
int v[(ll)1e7+1];
vect<vect<ll>> pre((ll)1e7+1);


ll func(ll n){
    ll res = 0;
    while (n!=0){
        res += (n%10) * (n%10);
        n/=10;
    }
    return res;
}
void solve(){
    for (int i=2 ; i <= 1e7 ; i++){
        pre[func(i)].pb(i);
    }
    stack<ll> s;
    s.push(1);
    v[1] = 1;
    while (!s.empty()){
        ll curr = s.top() ; s.pop();
        for (const ll &i : pre[curr]){
            v[i] = true;
            s.push(i);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a,b ; cin >> a >> b;
    solve();
    ll cnt = 0;
    for (int i=a ; i<=b ; i++){
        if (v[i]) cnt++;
    }
    cout << cnt;
    return 0;

}