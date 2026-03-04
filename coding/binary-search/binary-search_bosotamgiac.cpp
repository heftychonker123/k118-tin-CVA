#include <bits/stdc++.h>
using namespace std;
#define filename "bstg"
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    ll n; cin >> n;
    vect<ll> v(n);
    for (int i=0 ; i<n ; i++) cin >> v[i];
    sort(v.begin() , v.end());
    ll res=0;
    for (int i=0 ; i<n ; i++){
        for (int j=i+1 ; j<n ; j++){
            ll left=j+1 , right=n-1;
            auto low_int = lower_bound(v.begin()+j+1,v.end(),abs(v[i]-v[j])+1);
            auto up_int = upper_bound(v.begin()+j+1,v.end(),v[i]+v[j]-1);
            res += (up_int-low_int);
        }
    }
    cout << res << "\n";
    return 0;
}