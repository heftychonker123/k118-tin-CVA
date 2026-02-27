#include <bits/stdc++.h>
using namespace std;
#define filename "canbang"
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
    ll n , k ; cin >> n >> k;
    vect<ll> v(n); for (int i=0 ; i<n ; i++) cin >> v[i];
    ll cnt=0;
    sort(v.begin() , v.end());
    for (int i=0 ; i<n ; i++){
        ll curr = v[i];
        bool before = binary_search(v.begin() , v.begin()+i , curr-k);
        bool after = binary_search(v.begin() + i + 1, v.end() , curr+k);
        if (before && after) cnt++;
    }
    cout << cnt;
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