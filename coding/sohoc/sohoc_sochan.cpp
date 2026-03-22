#include <bits/stdc++.h>
using namespace std;
#define filename "sochan"
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

void IO(){
    if (fopen(filename".inp" , "r"))
    {
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    IO();
    ll l,r ; cin >> l >> r;
    l = (l%2==0? l+2 : l+1);
    r = (r%2==0? r-2 : r-1);
    cout << (r-l)/2 + 1 << "\n";
    return 0;
}