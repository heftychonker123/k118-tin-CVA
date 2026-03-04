#include <bits/stdc++.h>
using namespace std;
#define filename "Chiakeo"
#define ll long long
#define str string
#define pb push_back
#define vect vector
pair<ll , str> low_diff(ll n , ll sum , vect<ll> v , ll idx , ll currsum , str permute=""){
    if (idx == n) return {currsum , permute};
    pair<ll,str> include = low_diff(n , sum , v, idx+1 , currsum + v[idx] , permute + "1");
    pair<ll,str> exclude = low_diff(n , sum , v, idx+1 , currsum , permute + "0");
    if (abs(sum - include.first*2) > abs(sum-exclude.first*2)) return exclude;
    else if (abs(sum - include.first*2) < abs(sum-exclude.first*2)) return include;
    else{
        if (include.first > exclude.first) return include;
        else return exclude;
    }
}
void solve(){
    ll n ; cin >> n;
    vect<ll> v(n);
    for (int i=0 ; i<n ; i++) cin >> v[i];
    ll sum = accumulate(v.begin() , v.end() , 0);
    auto res = low_diff(n , sum , v, 0 , 0);
    vect<ll> first,second;
    for (int i=0 ; i<n ; i++){
        if (res.second[i]=='0') second.pb(i);
        else first.pb(i);
    }
    cout << sum - res.first << "\n";
    for (const ll &i : second) cout << i+1 << " ";
    cout << "\n" << res.first << "\n";
    for (const ll &i : first) cout << i+1 << " ";
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