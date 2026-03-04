#include <bits/stdc++.h>
using namespace std;
#define filename "truyvandoan"
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

vect<ll> prefix_sum(vect<ll> v){
    vect<ll> res = {0};
    ll sum=0;
    for (const ll &i : v){
        sum+=i ; res.pb(sum);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,q ; cin >> n >> q;
    vect<ll> v(n);
    for (int i=0 ; i<n ; i++) cin >> v[i];
    vect<ll> sumto = prefix_sum(v);
    while (q--){
        ll x,y ; cin >> x >> y;
        cout << sumto[y+1]- sumto[x] << "\n";
    }
    return 0;
}