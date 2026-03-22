#include <bits/stdc++.h>
using namespace std;
#define filename "chinhhop"
#define ll long long
#define vect vector

void IO(){
    if (fopen(filename".inp" , "r")) {
        freopen(filename".inp" , "r" , stdin);
        freopen(filename".out" , "w" , stdout);
    }
}

void solve(ll n, ll k, vect<ll>& curr) {
    if ((ll)curr.size() == k) {
        for (ll x : curr) cout << x << " ";
        cout << "\n";
        return;
    }
    for (ll i = 1; i <= n; i++) {
        curr.push_back(i);
        solve(n, k, curr);
        curr.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    IO();
    ll n, k; 
    cin >> n >> k;
    vect<ll> curr;
    solve(n, k, curr);
    return 0;
}
