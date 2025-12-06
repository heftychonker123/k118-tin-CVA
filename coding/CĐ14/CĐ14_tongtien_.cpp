#include <bits/stdc++.h>
using namespace std;
#define filename "tongtien_"
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
    ll n ; cin >> n;
    vect<ll> v(n);
    for (int i=0 ; i<n ; i++) cin >> v[i];
    sort(v.begin() , v.end());
    ll max_change=1;
    for (const ll &i : v){
        if (i>max_change) break;
        else max_change+=i;
    }
    cout << max_change;
    return 0;
}