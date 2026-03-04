#include <bits/stdc++.h>
using namespace std;
#define filename "luythua"
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
const ll MOD = 1e9 + 7;
ll fact(ll a , ll b){
    if (b==0) return 1;
    else{
        ll t = fact(a,b/2)%MOD;
        if (b%2==1) return ((t * t)%MOD * a)%MOD;
        else return (t*t)%MOD;
    }
}
void solve(){
    ll a,b ; cin >> a >> b;
    a%=MOD;
    cout << fact(a,b);
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