#include <bits/stdc++.h>
using namespace std;
#define filename "subarraySum"
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
    ll n,x ; cin >> n >> x;
    vect<ll> pref(n+1,0);
    for (int i=1 ; i<=n ; i++){
        ll t ; cin >> t;
        pref[i] = pref[i-1]+t;
    }
    ll res=0;
    map<ll,ll> freq;
    for (const ll &i : pref){
        res+=freq[i-x];
        freq[i]++;
    }
    cout << res;
    return;
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