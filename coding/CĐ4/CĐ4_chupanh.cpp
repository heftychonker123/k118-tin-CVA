#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n, m;
    cin >> n >> m;

    map<ll, vector<ll>> athlete;

    // Initialize linear neighbors
    for (int i = 1; i <= n; i++) {
        ll left = (i == 1) ? 0 : i - 1;
        ll right = (i == n) ? 0 : i + 1;
        athlete[i] = {left, right};
    }

    for (int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;

        // Detach athlete a from current position
        ll a_left = athlete[a][0];
        ll a_right = athlete[a][1];
        if (a_left != 0) athlete[a_left][1] = a_right;
        if (a_right != 0) athlete[a_right][0] = a_left;

        // Insert athlete a to the left of athlete b
        ll b_left = athlete[b][0];
        athlete[a][0] = b_left;
        athlete[a][1] = b;
        athlete[b][0] = a;
        if (b_left != 0) athlete[b_left][1] = a;
    }

    // Print final state
    for (auto &[id, neighbors] : athlete) {
        cout << neighbors[0]<< " " << neighbors[1] << endl;
    }

    return 0;
}
