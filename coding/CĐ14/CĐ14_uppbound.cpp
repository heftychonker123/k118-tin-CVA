#include <bits/stdc++.h>
using namespace std;
#define filename "uppbound_"
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
    ll n,x ; cin >> n >> x;
    vect<ll> v(n);
    for (int i=0 ; i<n ; i++) cin >> v[i];
    auto it = upper_bound(v.begin() , v.end() , x);
    if (it==v.begin()) cout << "NOT FOUND";
    else{
        it--;
        cout << *it;
    }
    return 0;
}