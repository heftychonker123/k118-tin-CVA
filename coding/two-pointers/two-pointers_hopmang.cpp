#include <bits/stdc++.h>
using namespace std;
#define filename "hopmang"
#define ll long long
#define ld long double
#define str string
#define llmin LLONG_MIN
#define llmax LLONG_MAX
#define pb push_back
#define strri string::reverse_iterator
#define stri string::iterator
#define vect vector
#define sstream stringstream
#define umap unordered_map
void solve(){
    ll n,m ; cin >> n >> m;
    vect<ll> a(n); for (int i=0 ; i<n ; i++) cin >> a[i];
    vect<ll> b(m); for (int i=0 ; i<m ; i++) cin >> b[i];
    sort(a.begin() , a.end());
    sort(b.begin() , b.end());
    vect<ll> c;

    ll ptrA = 0 , ptrB = 0;
    while (ptrA<n && ptrB<m){
        if (a[ptrA] <b[ptrB]){
            c.pb(a[ptrA]);
            ptrA++;
        }
        else if (a[ptrA] > b[ptrB]){
            c.pb(b[ptrB]);
            ptrB++;
        }
        else{
            c.pb(a[ptrA]);
            ptrA++;
            ptrB++;
        }
    }
    while (ptrA<n){
        c.pb(a[ptrA]);
        ptrA++;
    }
    while (ptrB<m){
        c.pb(b[ptrB]);
        ptrB++;
    }


    for (const ll &i : c) cout << i << " ";
    return;

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}