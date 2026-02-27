#include <bits/stdc++.h>
using namespace std;
#define filename "ktnt"
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
bool check(ll n , ll base){
    if (base*base > n) return true;
    else{
        if (n%base == 0) return false;
        return (n , base+1);
    }
}
void solve(){
    ll n ; cin >> n;
    cout << check(n,2);
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