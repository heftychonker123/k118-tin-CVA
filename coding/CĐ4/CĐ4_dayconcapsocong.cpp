#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("DCCSC.INP", "r", stdin);
    //freopen("DCCSC.OUT", "w", stdout);
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; ++i) cin >> a[i];
    vector<unordered_map<long long, pair<long long, long long>>> dp(n);
    long long max_len = 0, end_index = -1;
    long long best_diff = 0;

    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < i; ++j) {
            long long d = a[i] - a[j];
            if (dp[j].count(d)) {
                long long len = dp[j][d].first;
                dp[i][d] = {len + 1, j};
            } else {
                dp[i][d] = {2, j};
            }

            if (dp[i][d].first > max_len) {
                max_len = dp[i][d].first;
                end_index = i;
                best_diff = d;
            }
        }
    }

    if (max_len < 2) {
        cout << "0\n";
        return 0;
    }

    // Reconstruct the sequence of indices
    vector<long long> indices;
    long long curr = end_index;
    while (true) {
        indices.push_back(curr + 1); // 1-based index
        long long len = dp[curr][best_diff].first;
        long long prev = dp[curr][best_diff].second;
        if (len == 2) {
            indices.push_back(prev + 1);
            break;
        }
        curr = prev;
    }

    cout << indices.size() << " ";
    cout << a[indices[0] - 1] - a[indices[1] - 1];
    return 0;
}
