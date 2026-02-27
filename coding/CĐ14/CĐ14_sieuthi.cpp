#include <bits/stdc++.h>
using namespace std;
#define filename "sieuthi"
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
int main(){
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    int n,k ; cin >> n >> k;
    vect<ll> v(n);
    for (int i=0 ; i<n ; i++) cin >> v[i];
    sort(v.rbegin() , v.rend());
    ll res=accumulate(v.begin() , v.end() , 0);
    for (int i=k-1; i<n ; i+=k){
        res-=v[i];
    }
    cout << res << "\n";
    return 0;
}