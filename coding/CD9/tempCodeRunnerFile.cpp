#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define llmin LLONG_MIN
#define llmax LLONG_MAX
#define vect vector
void dp(ll n , vect<ll> &t , vect<ll> &r , vect<ll> &table){
    vect<bool> skipped(n , false);
    for (int i=1 ; i<=n ; i++){
        ll normal = table[i-1] + t[i-1];
        ll skip = llmax;
        if (i-2>=0){
            skip = table[i-2] + r[i-2];
        }
        if (skip < normal){
            skipped[i-1] = true;
            table[i] = skip;
        }
        else table[i] = normal;
        
    }
    cout << table[n] << "\n";
    ll counters = 0;
    for (int i=1 ; i<=n ; i++){
        if (skipped[i-1]){ 
            cout << i << " ";
            counters++;
        }
    }
    cout << (counters == 0 ? 0 : "");
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ticket.inp" , "r" , stdin);
    //freopen("ticket.out" , "w" , stdout);
    ll n ; cin >> n;
    vect<ll> v(n) , r(n-1);
    for (int i=0 ; i<n ; i++) cin >> v[i];
    for (int i=0 ; i<n-1 ; i++) cin >> r[i];
    vect<ll> table(n+1 , 0);
    dp(n , v , r , table);
    return 0;
}