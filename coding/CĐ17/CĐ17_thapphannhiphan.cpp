#include <bits/stdc++.h>
using namespace std;
#define filename "tpnp"
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
str dectobin(ll n , str sub = ""){
    if (n==0){
        if (!sub.empty()) return sub;
        else return "0";
    }
    return dectobin(n/2 , to_string(n%2)+sub);
}
void solve(){
    ll n ; cin >> n;
    cout << dectobin(n);
}
void IO(){
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //IO();
    solve();
    return 0;
}