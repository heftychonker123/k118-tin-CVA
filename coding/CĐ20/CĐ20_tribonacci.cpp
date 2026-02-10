#include <bits/stdc++.h>
using namespace std;
#define filename "tribonacci"
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
ll a[(ll)(1e6) + 1];
const ll MODULO = 1e9+7;
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


    a[0] = 0;
    a[1] = 1;
    for (int i=2 ; i<1e6+1 ; i++){
        a[i] = (a[i-1]+a[i-2])%MODULO;
    }
    ll n ; cin >> n;
    for (int i = 0 ; i<n ; i++){
        ll t ; cin >> t; cout << a[t] << " ";
    }
    return 0;
}