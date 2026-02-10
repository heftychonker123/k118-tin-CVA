#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vect vector
void solve(ll n , vect<bool> &chosen ,  vect<ll> sub = {}){
    if (sub.size() == n){
        for (const ll &i : sub) cout << i << " ";
        cout << "\n";
    }
    for (int i=n ; i>=1 ; i--){
        if (!chosen[i]){
            sub.pb(i);
            chosen[i] = true;
            solve(n , chosen , sub);
            sub.pop_back();
            chosen[i] = false;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n ; cin >> n;


    vect<ll> v(n);
    vect<bool> chosen(n , false);
    for (int i=0 ; i<n ; i++) v[i] = i+1;


    solve(n , chosen);
    return 0;
}