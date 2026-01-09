#include <bits/stdc++.h>
using namespace std;
#define filename "numjoin"
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
    vect<str> v(n);
    for (int i=0 ; i<n ; i++) cin >> v[i];
    sort(v.begin(), v.end(), [](const str &a, const str &b) {
    return a + b > b + a;
    });

    for (const str &i : v) cout << i;
    return 0;
}