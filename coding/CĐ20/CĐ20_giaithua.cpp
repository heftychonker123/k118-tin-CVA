#include <bits/stdc++.h>
using namespace std;
#define filename "giaithua"
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
const ll MODULO = 1e9 + 7;
ll a[(ll)1e6+1];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    a[0] = 1;
    for (int i = 1 ; i<=1e6 ; i++){
        a[i] = (a[i-1]*i) % (MODULO);
    }
    ll n ; cin >> n; 
    for (int i=0 ; i<n ; i++){
        ll t ; cin >> t;
        cout << a[t] << " ";
    }
    return 0;
}