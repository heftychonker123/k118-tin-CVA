#include <bits/stdc++.h>
using namespace std;
#define filename "binsearch"
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
bool binsearch(vect<ll> v , ll l , ll r , ll x){
    if (l>r) return false;
    ll m = (r+l)/2;
    if (v[m] == x) return true;
    else if (v[m]>x) return binsearch(v , m+1 , r , x);
    else return binsearch(v,l,m-1,x); 
}
void solve(){
    ll n,x ; cin >> n >> x;
    vect<ll> v(n);
    for (int i=0 ; i<n ; i++) cin >> v[i];
    if(binsearch(v,0,n-1,x)) cout << "YES";
    else cout << "NO";
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