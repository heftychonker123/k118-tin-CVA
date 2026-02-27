#include <bits/stdc++.h>
using namespace std;
#define filename "muave"
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
    ll sum = 0;
    for (int i=0 ; i<n ; i++){
        ll t ; cin >> t;
        if (15<=t && t<24) sum+=15000;
        if (24<=t && t<=60) sum+=30000;
    }
    cout << sum;
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