#include <bits/stdc++.h>
using namespace std;
#define filename "ucln"
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
ll gcd(ll a, ll b){
    if (a==0 || b==0) return max(a,b);
    else{
        if (a>b) return gcd(a%b,b);
        else return gcd(a,b%a);
    }
}
void solve(){
    ll a,b ; cin >> a >> b;
    cout << gcd(a,b) << " " << a/gcd(a,b) * b/gcd(a,b) * gcd(a,b);
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