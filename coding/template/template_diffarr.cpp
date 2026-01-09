#include <bits/stdc++.h>
using namespace std;
#define filename "diffarr"
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

vect<ll> diff_arr(vect<ll> v){
    vect<ll> diff={v[0]};
    for (int i=1 ; i<v.size() ; i++){
        diff.pb(v[i] - v[i-1]);
    }
    return diff;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen(filename".inp" , "r" , stdin);
    //freopen(filename".out" , "w" , stdout);
    ll n ; cin >> n;
    vect<ll> v(n);
    for (int i=0 ; i<n ; i++) cin >> v[i];
    vect<ll> diff = diff_arr(v);
    for (const ll &i : diff) cout << i << " ";
    return 0;
}