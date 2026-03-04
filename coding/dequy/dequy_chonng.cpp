#include <bits/stdc++.h>
using namespace std;
#define filename "chonng"
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
ll t = 0;
void solve(ll n , ll k , vect<ll> sub = {} , ll idx = 0){
    if (sub.size() == k){
        cout << "(";
        for (int i=0 ; i<k-1 ; i++) cout << sub[i] << ",";
        cout << sub[k-1] << ")";
        t++;
        cout << "\n"; return;
    }
    else if (idx==n) return;
    for (int i=idx+1 ; i<=n ; i++){
        sub.push_back(i);
        solve(n , k , sub , i);
        sub.pop_back();
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,k ; cin >> n >> k;
    solve(n , k);
    cout << t << "\n";
    return 0;
}