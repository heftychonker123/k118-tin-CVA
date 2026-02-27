#include <bits/stdc++.h>
using namespace std;
#define filename "mining"
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
    ll n , S ; cin >> n >> S;
    vect<ll> v(n);
    for (int i=0 ; i<n ; i++) cin >> v[i];
    ll l = 1 , r = *max_element(v.begin()  , v.end());
    ll res=0;
    while (r>=l){
        ll m = (l+r)/2;
        ll cnt=0;
        for (const ll &i : v) cnt+=max(0ll, i-m);
        if (cnt>=S){
            res = m;
            l = m+1;
        }
        else r = m-1;
    }
    cout << res << "\n";
    return;
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