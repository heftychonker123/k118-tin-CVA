#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define db long double
#define str string
#define llmin LLONG_MIN
#define llmax LLONG_MAX
#define pb push_back
#define vect vector
int main(){

    ll n, m;
    cin >> n;
    m = n;

    vect<vect<ll>> v(n, vect<ll>(n));
    for (ll i = 0; i < n; i++){
        for (ll j = 0; j < m; j++) cin >> v[j][i];
    }
    for (vect<ll> &temp : v){
        sort(temp.begin(), temp.end()); 
    }
    for (ll i=0 ; i<n ; i++){
        for (ll j=0 ; j<n ; j++){
            cout << v[j][i] << " ";
        }
        cout << endl;
    }
    return 0;
}
