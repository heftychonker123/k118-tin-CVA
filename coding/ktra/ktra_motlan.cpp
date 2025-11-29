#include <bits/stdc++.h>
using namespace std;
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

void solve(vect<ll> v ){
    map<ll , ll> freq;
    for (const ll &i : v){
        freq[i]++;
    }
    vect<ll> ans;
    for (auto &i : freq){
        if(i.second==1){
            ans.pb(i.first);
        }
    }
    cout << ans.size() << "\n";
    if (ans.size()==0){
        cout << 0;
        return;
    }
    for (const ll &i : ans) cout << i << " ";
    return;
}
int main(){
    freopen("motlan.inp" , "r" , stdin);
    freopen("motlan.out" , "w" , stdout);
    int n; cin >> n;
    vect<ll> v(n);
    for (int i=0 ; i<n ; i++) cin >> v[i];
    solve(v);
    return 0;
}