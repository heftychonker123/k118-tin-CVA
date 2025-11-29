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

void solve(ll n){
    ll res=0;
    for (int i=5 ; i<n ; i*=5){
        res += n/i;
    }
    cout << res << "\n";
    return;
}

int main(){
    int t ; cin >> t;
    while (t--){
        ll n ; cin >> n;
        solve(n);
    }
}