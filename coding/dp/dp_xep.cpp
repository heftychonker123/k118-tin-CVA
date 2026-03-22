#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define llmin LLONG_MIN
#define llmax LLONG_MAX
#define vect vector
void dp(ll n , vect<ll> &t , vect<ll> &r , vect<ll> &table){
    for (int i=1 ; i<=n ; i++){
        ll normal = table[i-1] + t[i-1];
        ll skip = llmax;
        if (i-2>=0){
            skip = table[i-2] + r[i-2];
        }
        table[i] = min(normal , skip);
    }

    cout << table[n] << "\n";

    ll trace = n;
    vect<ll> skipped;
    while (trace > 0){
        ll normal = table[trace-1] + t[trace-1];
        ll skip = llmax;
        if (trace-2 >= 0){
            skip = table[trace-2] + r[trace-2];
        }
        if (table[trace] == skip){
            skipped.push_back(trace);
            trace -= 2;
        } else {
            trace -= 1;
        }
    }

    for (int i = skipped.size()-1 ; i>=0 ; i--) cout << skipped[i] << " ";
    cout << (skipped.size() == 0 ? 0 : "");
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("ticket.inp" , "r" , stdin);
    freopen("ticket.out" , "w" , stdout);
    ll n ; cin >> n;
    vect<ll> v(n) , r(n);
    for (int i=0 ; i<n ; i++) cin >> v[i];
    for (int i=0 ; i<n ; i++) cin >> r[i];
    vect<ll> table(n+1 , 0);
    dp(n , v , r , table);
    return 0;
}