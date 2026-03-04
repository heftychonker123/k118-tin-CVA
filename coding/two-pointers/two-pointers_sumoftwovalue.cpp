#include <bits/stdc++.h>
using namespace std;
#define filename "sumoftwovalue"
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
    vect<pair<ll,ll>> v(n);
    for (int i=0 ; i<n ; i++){
        ll t ; cin >> t ; v[i] = {t,i+1};
    }
    sort(v.begin() , v.end());
    ll l=0 , r=n-1;
    while (l<r){
        if ((v[l].first + v[r].first)==x){
            cout << v[l].second << " " << v[r].second;
            return;
        }
        else if ((v[l].first + v[r].first)>x) r--;
        else l++;
    }
    cout << "IMPOSSIBLE";
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