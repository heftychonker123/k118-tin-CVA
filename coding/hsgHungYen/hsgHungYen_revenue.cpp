#include <bits/stdc++.h>
using namespace std;
#define filename "revenue"
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

void solve(){
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    ll x,y,n ; cin >> x >> y >> n;
    ll res = y;
    n--;
    ll weeks = (n)/7;
    res += weeks*(5*x + 2*y);
    ll days = n%7;
    if (days<=5) res+= days*x;
    else res+=(days-5)*y + 5*x;
    cout << res;
}