#include <bits/stdc++.h>
using namespace std;
#define filename "divisor"
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
const ll MOD = 123456789;
void factor(ll n , umap<ll,ll> &factors){
    while (n%2 == 0){
        n/=2;
        factors[2]++;
    }
    for (int i=3 ; i*i <= n ; i++){
        while (n%i == 0){
            n/=i;
            factors[i]++;
        }
    }
    if (n>1) factors[n]++;
}
void solve(){
    ll n ; cin >> n;
    vect<ll> v(n);
    for (ll i=0 ; i<n ; i++) cin >> v[i];
    umap<ll,ll> factors;
    for (const ll &i : v) factor(i , factors);
    ll res = 1;
    for (const auto &[prime,power] : factors){
        res =  (res*(power+1))%MOD;
    }
    cout << res;
}
void IO(){
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    IO();
    solve();
    return 0;
}