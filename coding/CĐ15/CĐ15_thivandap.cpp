#include <bits/stdc++.h>
using namespace std;
#define filename "thivandap"
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
vect<ll> prefix_sum(multiset<ll> ms){
    ll length = ms.size();
    vect<ll> v(length+1 , 0);
    vect<ll> t(ms.begin() , ms.end());
    for (int i=1 ; i<=length ; i++){
        v[i] = v[i-1] + t[i-1];
    }
    t.clear();
    return v;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen(filename".inp" , "r" , stdin);
    //freopen(filename".out" , "w" , stdout);
    ll n,m ; cin >> n >> m;
    multiset<ll> ms;
    vect<ll> pref;
    for (int i=0 ; i<n ; i++){
        ll t ; cin >> t;
        pref = prefix_sum(ms);
        auto it = lower_bound(pref.begin(),pref.end(),m-t+1);
        cout << pref.end() - it << " ";
        ms.insert(t);
    }
    cout << "\n";
    return 0;
}