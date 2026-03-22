#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<int>& curr, int start) {
    for (int j = start; j <= n; j++) {
        curr.push_back(j);
        for (int k = 0; k < curr.size(); k++) {
            if (k > 0) cout << " ";
            cout << curr[k];
        }
        cout << "\n";
        solve(n, curr, j + 1);
        curr.pop_back();
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> curr;
    solve(n, curr, 1);
    return 0;
}
