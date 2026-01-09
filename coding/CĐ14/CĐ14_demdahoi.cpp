#include <bits/stdc++.h>
using namespace std;
#define filename "demdahoi"
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
    //freopen(filename".inp" , "r" , stdin);
    //freopen(filename".out" , "w" , stdout);
    ll n,d ; cin >> n >> d;
    vect<ll> v(n);
    ll res=0;
    for (int i=0 ; i<n ; i++) {
        cin >> v[i];
    }
    sort(v.begin() , v.end());
    for (int i=0 ; i<n ; i++){
        auto lowit = lower_bound(v.begin()+i+1 , v.end(), v[i] - d);
        auto highit = upper_bound(v.begin()+i+1 , v.end(),v[i] - d);
        res+=highit-lowit;
        lowit = lower_bound(v.begin()+i+1 , v.end(), v[i] + d);
        highit = upper_bound(v.begin()+i+1 , v.end(),v[i] + d);
        res+=highit-lowit;
    }
    cout << res << "\n";
    return 0;
}