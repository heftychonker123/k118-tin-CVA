#include <bits/stdc++.h>
using namespace std;
#define filename "datngoac"
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
void backtrack(ll n , ll idx=0 , str sub="" , ll t=0 , ll open=0){
    if (idx == 2*n){
        cout << sub << "\n";
        return;
    }
    
    if (open<n) backtrack(n , idx+1 , sub+"(" , t+1 , open+1);
    if (t>0) backtrack(n , idx+1 , sub + ")" , t-1 , open);
    return;
}
void solve(){
    ll n ; cin >> n;
    backtrack(n);
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