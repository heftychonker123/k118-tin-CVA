#include <bits/stdc++.h>
using namespace std;
#define filename "vitridautien"
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
    ll n,x ; cin >> n >> x;
    vect<ll> v(n);
    for (int i=0 ; i<n ; i++) cin >> v[i];
    sort(v.begin() , v.end());
    auto it = lower_bound(v.begin() , v.end() , x);
    if (it!=v.end()&& *it == x){
        cout << it - v.begin();
    }
    else cout << -1;
    cout << "\n";
    return 0;
}
