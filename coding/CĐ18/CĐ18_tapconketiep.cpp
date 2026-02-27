#include <bits/stdc++.h>
using namespace std;
#define filename "tapconketiep"
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
void sinh(vect<ll> &v , ll n , ll k){
    ll t = k-1;
    while (t>=0 && v[t] > n-k+t) t--;
    if (t<0){
        for (int i=0 ; i<k ; i++) v[i] = i+1;
        return;
    }
    v[t]++;
    for (int i=t+1 ; i<k ; i++){
        v[i] = v[i-1] + 1;
    }
}
void solve(){
    ll n,k ; cin >> n >> k;
    vect<ll> v(k); for (int i=0 ; i<k ; i++) cin >> v[i];
    sinh(v,n,k);
    for (const ll &i : v) cout << i << " ";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}