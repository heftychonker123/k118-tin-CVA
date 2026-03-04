#include <bits/stdc++.h>
using namespace std;
#define filename "tohop"
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
void comb(ll n , ll k , vect<ll> sub = {}){
    if (sub.size() == k){
        for (const ll &i : sub) cout << i << " ";
        cout << "\n";
        return;
    }
    ll start=1;
    if (!sub.empty()) start = sub.back()+1;
    for (int i=start ; i<=n ; i++){
        sub.pb(i);
        comb(n,k,sub);
        sub.pop_back();
    }
    return;
}
void solve(){
    ll n,k ; cin >> n >> k;
    comb(n,k);
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