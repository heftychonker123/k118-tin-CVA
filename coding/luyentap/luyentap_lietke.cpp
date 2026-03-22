#include <bits/stdc++.h>
using namespace std;
#define filename "lietke"
#define ll long long
#define vect vector

void IO(){
    if (fopen(filename".inp" , "r"))
    {
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    }
}
void solve(ll n, vect<ll> curr = {}) {
    if (n == 0) {
        if (curr.size()<2) return;
        for (const ll &i : curr) cout << i << " ";
        cout << "\n";
        return;
    }
    ll start = curr.empty() ? 1 : *curr.rbegin();
    for (ll i = start; i <= n; i++) {
        curr.push_back(i);
        solve(n - i, curr);
        curr.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    IO();
    ll n ; cin >> n;
    solve(n);
    return 0;
}