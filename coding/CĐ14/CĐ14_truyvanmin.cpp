#include <bits/stdc++.h>
using namespace std;
#define filename "truyvanmin"
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
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,q ; cin >> n >> q;
    vect<ll> v(n);
    for (int i=0 ; i<n ; i++) cin >> v[i];
    while (q--){
        ll l,r,x ; cin >> l >> r >> x;
        auto it = lower_bound(v.begin() + l - 1, v.begin() + r, x);
        if (it == v.begin() + r) cout << -1 << "\n";
        else cout << *it << "\n";
    }
    return 0;
}