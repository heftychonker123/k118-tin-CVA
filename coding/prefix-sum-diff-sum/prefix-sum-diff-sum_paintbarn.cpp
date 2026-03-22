#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 1005;
ll a[MAXN][MAXN];
ll grid[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;

    while (n--) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        a[x1][y1]++;
        a[x2][y1]--;
        a[x1][y2]--;
        a[x2][y2]++;
    }

    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            if (i > 0) a[i][j] += a[i-1][j];
            if (j > 0) a[i][j] += a[i][j-1];
            if (i > 0 && j > 0) a[i][j] -= a[i-1][j-1];
            grid[i][j] = a[i][j];
        }
    }

    ll ans = 0;
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            if (grid[i][j] == k) ans++;
        }
    }

    cout << ans << "\n";
    return 0;
}
