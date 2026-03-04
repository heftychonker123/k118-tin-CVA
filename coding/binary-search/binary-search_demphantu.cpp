#include <bits/stdc++.h>
using namespace std;
#define filename "dempt"
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
    sort(a.begin() , a.end());
    ll res=0;
    for (const ll &i : b){
        if (binary_search(a.begin() , a.end() , i)){
            res++;
        }
    }
    cout << res << "\n";
    return 0;
}