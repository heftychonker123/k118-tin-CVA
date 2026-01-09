#include <bits/stdc++.h>
using namespace std;
#define filename "seqgame"
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
    ll n ; cin >> n;
    vect<ll> a(n) , b(n);
    for (int i=0 ; i<n ; i++) cin >> a[i];
    for (int i=0 ; i<n ; i++) cin >> b[i];
    sort(b.begin() , b.end());
    ll res = llmax;
    for (const ll &i : a){
        auto it = lower_bound(b.begin() , b.end() , -i);
        if (it != b.end()){
            res = min(res , abs(*it + i));
        }
        if (it != b.begin()){
            it --;
            res = min(res , abs(*it + i));
        }
    }
    cout << res << "\n";
    return 0;
}