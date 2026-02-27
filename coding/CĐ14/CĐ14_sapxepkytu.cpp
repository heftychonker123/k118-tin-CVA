#include <bits/stdc++.h>
using namespace std;
#define filename "sapxepkytu"
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
    //freopen(filename".inp" , "r" , stdin);
    //freopen(filename".out" , "w" , stdout);
    ll n ; cin >> n ; 
    vect<char> v(n);
    for (int i=0 ; i<n ; i++) cin >> v[i];
    sort(v.begin() , v.end());
    for (const char &i : v) cout << i << " ";
    cout << "\n";
    sort(v.rbegin() , v.rend());
    for (const char &i : v) cout << i << " ";
    cout << "\n";
}