#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector

void solve(ll n){
    ll original = n;
    vect<ll> v;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            v.push_back(i);
            n /= i;
        }
    }
    if (n > 1) v.push_back(n);

    cout << original << "=";
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i + 1 < v.size()) cout << "*";
    }
    cout << "\n";

    cout << accumulate(v.begin(), v.end(), 0LL) << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; 
    cin >> n;
    solve(n);
    return 0;
}
