#include <bits/stdc++.h>
using namespace std;
#define filename "mangcon1"
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
    ll n,s ; cin >> n >> s;
    vect<ll> v(n);
    for (int i=0 ; i<n ; i++) cin >> v[i];
    ll sum = 0;
    ll res = 0;
    for (ll i=0 , j=0 ; j<n ; j++){
        sum+=v[j];
        while (sum>s){
            sum-=v[i];
            i++;
        }
        res += (j-i+1);
    }
    cout << res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}