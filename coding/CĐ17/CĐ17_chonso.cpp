#include <bits/stdc++.h>
using namespace std;
#define filename "Chonso"
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
    ll n ; cin >> n;
    vect<vect<ll>> v(n,vect<ll>(n));
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++) cin >> v[i][j];
    }
    vect<ll> per(n);
    ll res = 0;
    for (ll i=0 ; i<n ; i++) per[i]=i;
    do {
        ll temp=0;
        for (int i=0 ; i<n ; i++){
            temp+=v[i][per[i]];
        }
        res = max(res,temp);
    } 
    while (next_permutation(per.begin() , per.end()));
    cout << res;
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