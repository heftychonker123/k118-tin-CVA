#include <bits/stdc++.h>
using namespace std;
#define filename "merge"
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

vect<ll> merge(vect<ll> a , vect<ll> b){
    vect<ll> res;
    ll i=0 , j=0;
    while (i<a.size() && j<b.size()){
        if (a[i]<b[j]){
            res.pb(a[i]);i++;
        }
        else{
            res.pb(b[j]);j++;
        }
    }
    while (i<a.size()){
        res.pb(a[i]);i++;
    }
    while (j<b.size()){
        res.pb(b[j]);j++;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen(filename".inp" , "r" , stdin);
    //freopen(filename".out" , "w" , stdout);
    ll n ; cin >> n;
    vect<ll> a(n);
    for (int i=0 ; i<n ; i++) cin >> a[i];
    ll m ; cin >> m;
    vect<ll> b(m);
    for (int i=0 ; i<m ; i++) cin >> b[i];
    vect<ll> res = merge(a,b);
    for (const ll &i : res) cout << i << " ";
    cout << "\n";
    return 0;
}