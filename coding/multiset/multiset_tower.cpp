#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n ; cin >> n;
    vect<ll> v;
    for (int i = 0 ; i<n ; i++){
        ll t ; cin >> t;
        ll pos = upper_bound(v.begin(), v.end(), t) - v.begin();
        if (pos == v.size()) v.push_back(t);
        else v[pos] = t;
    }
    cout << v.size();
}