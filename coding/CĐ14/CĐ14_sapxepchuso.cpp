#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define vect vector

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; 
    cin >> n;
    vect<pair<str,ll>> v;

    for (int i = 0; i < n; i++) {
        str a; 
        cin >> a;
        ll countOdd = 0;
        for (const char &ch : a) {
            ll digit = ch - '0';
            if (digit % 2 == 1) {
                countOdd++;
            }
        }
        v.push_back({a, countOdd});
    }

    sort(v.begin(), v.end(), [&](auto &a, auto &b) {
        if (a.second == b.second) return stoll(a.first) < stoll(b.first);
        return a.second > b.second;
    });

    for (const auto &p : v) {
        cout << p.first << " ";
    }
    cout << "\n";

    return 0;
}
