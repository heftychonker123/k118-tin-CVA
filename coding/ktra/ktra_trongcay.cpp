#include <bits/stdc++.h>
using namespace std;
#define filename "trongcay"
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
    ll n,m ; cin >> n >> m;
    set<ll> s;
    for (int i=0 ; i<n ; i++){
        ll t ; cin >> t;
        s.insert(t);
        if (s.size()>=m){
            cout << i*10;
            break;
        }
    }
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