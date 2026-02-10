#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, k; 
    cin >> n >> m >> k;

    vect<vect<ll>> diff(n+2, vect<ll>(m+2, 0));

    while (k--) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        diff[x1][y1] += 1;
        diff[x1][y2+1] -= 1;
        diff[x2+1][y1] -= 1;
        diff[x2+1][y2+1] += 1;
    }

    vect<vect<ll>> v(n+1, vect<ll>(m+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            v[i][j] = diff[i][j] + v[i-1][j] + v[i][j-1] - v[i-1][j-1];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}
