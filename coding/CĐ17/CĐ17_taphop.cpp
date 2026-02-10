#include <bits/stdc++.h>
using namespace std;
#define filename "taphop"
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
void subset(ll n , ll idx=0 , vect<ll> sub = {}){
    for (const ll &i : sub) cout << i << " ";
    cout << "\n";

    for (int i=idx+1 ; i<=n ; i++){
        sub.pb(i);
        subset(n , i , sub);
        sub.pop_back();
    }
} 
void solve(){
    ll n ; cin >> n;
    subset(n);
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