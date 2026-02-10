#include <bits/stdc++.h>
using namespace std;

bool check(const vector<int>& v) {
    for (int i = 0; i < (int)v.size() - 1; i++) {
        if (abs(v[i+1] - v[i]) == 1) return false;
    }
    return true;
}

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    iota(v.begin(), v.end(), 1); // fill with 1..n

    do {
        if (check(v)) {
            for (int x : v) cout << x;
            cout << "\n";
        }
    } while (next_permutation(v.begin(), v.end()));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
