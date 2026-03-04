#include <bits/stdc++.h>
using namespace std;
#define filename "vongtayketnoi"
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
    ll n ; cin >> n;
    vect<ll> a(n) , b(n);
    for (int i=0 ; i<n ; i++) cin >> a[i];
    for (int i=0 ; i<n ; i++) cin >> b[i];
    sort(b.begin() , b.end());
    ll res=0;
    for (const ll &i : a){
        auto low_it = lower_bound(b.begin() , b.end() , i);
        auto high_it = upper_bound(b.begin() , b.end() , i);
        res+=(high_it - low_it);
    }
    cout << res << "\n";
    return 0;
}