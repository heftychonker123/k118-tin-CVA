#include <bits/stdc++.h>
using namespace std;
#define filename "timtichlonnhat_"
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
    ll a,b,c; cin >> a >> b >> c;
    cout << max({a*b, b*c, c*a});
    return 0;
}