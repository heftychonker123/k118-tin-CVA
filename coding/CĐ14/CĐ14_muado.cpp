#include <bits/stdc++.h>
using namespace std;
#define filename "tknp_muado"
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
    ll n,c ; cin >> n >> c;
    vect<ll> v(n);
    for (int i=0 ; i<n ; i++) cin >> v[i];
    sort(v.begin() , v.end());
    ll res=llmin;
    for (int i=0 ; i<n ; i++){
        ll t=v[i];
        auto it = upper_bound(v.begin()+i+1 , v.end() , c-t);
        if (it != v.begin() + i + 1) {
            --it;
            res = max(res, t + *it);
        }
    }
    cout << res << "\n";
    return 0;
}