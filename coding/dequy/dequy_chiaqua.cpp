#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
int i, j, n, h, d, a[101], t[4], tt[4], t1, t2, t3, mx, mn, kc, tong;

void chiaqua(int i)
{
    for (int j = 1; j <= 3; j++)
    {
        if (j == 1)
        {
            t1 = t1 + a[i];
        }
        else if (j == 2)
            t2 = t2 + a[i];
        else if (j == 3)
            t3 = t3 + a[i];

        if (i == n)
        {
            mx = max({t1, t2, t3});
            mn = min({t1, t2, t3});
            if (mx - mn < kc)
            {
                kc = mx - mn;
                t[1] = t1;
                t[2] = t2;
                t[3] = t3;
                if (kc == 0)
                    return;
            }
        }
        else if (t1 <= mx && t2 <= mx && t3 <= mx)
            chiaqua(i + 1);

        if (j == 1)
            t1 = t1 - a[i];
        else if (j == 2)
            t2 = t2 - a[i];
        else
            t3 = t3 - a[i];
    }
}

void solve()
{
    cin >> n;
    tong = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        tong = tong + a[i];
        mx = max(mx, a[i]);
    }
    mx = max(mx, tong / 2);
    kc = mx;
    chiaqua(1);
    sort(t + 1, t + 1 + 3);
    cout << t[1] << " " << t[2] << " " << t[3];
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("chiaqua.inp", "r", stdin);
    freopen("chiaqua.out", "w", stdout);
    solve();
    return 0;
}

