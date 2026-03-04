#include <bits/stdc++.h>
using namespace std;
#define ll long long

long double calc(ll h, ll c, ll cups) {
    return ((cups / 2) * (h + c) + (cups % 2) * h) / (long double)cups;
}

void solve(ll h, ll c, ll t) {
    if (t >= h) {
        cout << 1 << "\n"; 
        return;
    }
    if (t <= (h + c) / 2.0) {
        cout << 2 << "\n"; 
        return;
    }

    ll low = 1, high = 1;
    while (calc(h, c, high) > t) high *= 2;

    ll ans = 1;
    long double bestDiff = fabsl(calc(h, c, 1) - t);

    while (low <= high) {
        ll mid = (low + high) / 2;
        long double avg = calc(h, c, mid);
        long double diff = fabsl(avg - t);

        if (diff < bestDiff || (fabsl(diff - bestDiff) < 1e-12 && mid < ans)) {
            bestDiff = diff;
            ans = mid;
        }

        if (avg >= t) low = mid + 1;
        else high = mid - 1;
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll tc;
    cin >> tc;
    while (tc--) {
        ll h, c, t;
        cin >> h >> c >> t;
        solve(h, c, t);
    }
    return 0;
}
