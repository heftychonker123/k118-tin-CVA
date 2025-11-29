#include <bits/stdc++.h>
using namespace std;
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
    int n ; cin >> n;
    vect<ll> v(n);
    for (int i=0 ; i<n ; i++){
        cin >> v[i];
    }
    ll res=0;
    for (int i=0 ; i<n-1 ; i++){
        res += gcd(v[i] , v[i+1]);
    }
    cout << res << "\n";
    return 0;
}