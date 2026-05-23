#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll f[93]; // Fibonacci lengths

char findinstr(ll n, ll k) {
    if (n == 1) return 'A';
    if (n == 2) return 'B';
    if (k <= f[n-2]) return findinstr(n-2, k);
    else return findinstr(n-1, k - f[n-2]);
}

int main() {
    ll n, k;
    cin >> n >> k;
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= n; i++) f[i] = f[i-1] + f[i-2];
    cout << findinstr(n, k) << "\n";
}
