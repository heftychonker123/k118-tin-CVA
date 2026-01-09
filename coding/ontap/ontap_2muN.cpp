#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define pb push_back
str mult2(str t) {
    reverse(t.begin(), t.end());
    str res = "";
    ll carry = 0;
    for (char c : t) {
        ll digit = (c - '0') * 2 + carry;
        res.pb(char(digit % 10 + '0'));
        carry = digit / 10;
    }
    if (carry) res.pb(char(carry + '0'));
    reverse(res.begin(), res.end());
    return res;
}

void solve(ll n) {
    str t = "1";
    for (ll i = 0; i < n; i++) {
        t = mult2(t);
    }
    cout << t << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    solve(n);
    return 0;
}