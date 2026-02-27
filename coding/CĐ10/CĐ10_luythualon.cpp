#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
const ll MODULO = 1e9 + 7;
ll powerMod(ll a, ll b) {
    ll result = 1;
    a %= MODULO;
    while (b > 0) {
        if (b & 1) result = (result * a) % MODULO;
        a = (a * a) % MODULO;
        b /= 2;
    }
    return result;
}

int main() {
    str a; ll b;
    cin >> a >> b;
    ll re = 0;
    for (char c : a) {
        re = (re * 10 + (c - '0')) % MODULO;
    }
    ll p = b % (MODULO - 1);
    cout << powerMod(re, p) << "\n";
    return 0;
}
