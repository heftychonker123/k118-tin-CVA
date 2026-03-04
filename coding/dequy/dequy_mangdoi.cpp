#include <bits/stdc++.h>
using namespace std;
#define filename "mangdoi"
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
bool check(vect<ll> v , ll left , ll right){
    if (left>right) return true;
    else{
        if (v[left] != v[right]) return false;
        return check(v,left+1,right-1);
    }
}
void solve(){
    ll n ; cin >> n;
    vect<ll> v(n);
    for (int i=0 ; i<n ; i++) cin >> v[i];
    if (check(v,0,n-1)) cout << "YES";
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