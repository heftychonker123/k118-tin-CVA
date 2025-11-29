#include <bits/stdc++.h>
using namespace std;
#define filename "chusocuoicung2"
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

void solve(ll n , ll m , ll k){
    ll t=1;
    while(k--){
        t*=10;
    }
    ll res=1;
    while (m--){
        res *= n%t;
        res%=t;
    }
    cout << res;
    return;
}

int main(){
    //freopen(filename".inp" , "r" , stdin);
    //freopen(filename".out" , "w" , stdout);
    ll m , n , k; cin >> n >> m >> k;
    solve(n,m,k);
    return 0;
}