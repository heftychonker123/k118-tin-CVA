#include <bits/stdc++.h>
using namespace std;
#define filename "mct"
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

void IO(){
    if (fopen(filename".inp" , "r"))
    {
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    IO();
    ll t ; cin >> t;
    while (t--){
        ll n ; cin >> n;
        vect<ll> v(n); for (int i=0 ; i<n ; i++) cin >> v[i];
    }
    return 0;
}