#include <bits/stdc++.h>
using namespace std;
#define filename "cpt"
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
    ll n ; cin >> n;
    vect<ll> v(n); for (int i=0 ; i<n ; i++) cin >> v[i];
    sort(v.rbegin() , v.rend());
    if (n==4 && v[0] < v[1]+v[2]+v[3]) cout << -1;
    else if (v[0] >= v[1] + v[2] + v[3]) cout << n-1;
    else if (n==5 && v[0] + v[1] < v[2]+v[3]+v[4]) cout << -1;
    else if (v[0] + v[1] >= v[2]+v[3]+v[4]) cout << n-2;
    else cout << n-3;
    return 0;
}