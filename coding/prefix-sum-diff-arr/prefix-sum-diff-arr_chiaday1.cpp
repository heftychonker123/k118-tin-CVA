#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector

vect<ll> prefix_sum(const vect<ll>& v){
    vect<ll> res;
    ll sum=0;
    for (ll x : v){
        sum += x;
        res.push_back(sum);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin >> n;
    vect<ll> z(n);
    for (int i=0; i<n; i++) cin >> z[i];

    vect<ll> pref = prefix_sum(z);
    ll total = pref.back();
    if (n == 0) {
        cout << "-1\n";
        return 0;
    }

    if (total%2!=0){
        cout << "-1\n";
        return 0;
    }
    for (int i=0 ; i<n ; i++){
        if (pref[i] == total/2){
            cout << i+1 << "\n";
            return 0;
        }
    }
    cout << "-1\n";
    return 0;
}
