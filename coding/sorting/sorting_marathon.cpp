#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<ll,ll>> v(n);
    for (auto &p : v) cin >> p.first >> p.second;

    // Sắp xếp theo thời điểm hoàn tất sớm nhất, rồi theo thời gian đến, rồi theo thời gian chạy
    sort(v.begin(), v.end(), [](auto &a, auto &b) {
        ll fa = a.first + a.second;
        ll fb = b.first + b.second;
        if (fa != fb) return fa < fb;
        if (a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    });

    ll curr = 0;
    for (auto &[start, dur] : v) {
        if (curr > start) curr += dur;
        else curr = start + dur;
    }

    cout << curr << "\n";
    return 0;
}
