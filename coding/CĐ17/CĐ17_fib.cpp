#include <bits/stdc++.h>
using namespace std;
#define filename "fib"
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
ll fib(ll n){
    if (n==1) return 0;
    if (n==2) return 1;
    else return fib(n-1) + fib(n-2);
}
void solve(){
    ll n ; cin >> n;
    cout << fib(n);
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