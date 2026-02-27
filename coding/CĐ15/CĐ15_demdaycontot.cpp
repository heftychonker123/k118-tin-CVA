#include <bits/stdc++.h>
using namespace std;
#define filename "demdaycontot"
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
vect<ll> prefix_sum(vect<ll> n){
    vect<ll> res;
    ll sum=0;
    for (const ll &i : n){
        sum+=i;res.pb(sum);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen(filename".inp" , "r" , stdin);
    //freopen(filename".out" , "w" , stdout);
    ll t ; cin >> t;
    while (t--){
        ll n; cin >> n;
        str a ; cin >> a;
        vect<ll> v;
        for (const char &i : a){
            v.pb(i-'0' - 1);
        }
        vect<ll> pref = prefix_sum(v);
        map<ll,ll> freq;
        freq[0] = 1;
        ll res = 0;
        for (ll x : pref){
            res += freq[x];
            freq[x]++;
        }
        cout << res << "\n";
    }
    return 0;
}