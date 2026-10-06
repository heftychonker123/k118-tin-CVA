#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll inf = 1e18;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<ll> A(n);
    for (int i = 1; i < n; ++i) {
        cin >> A[i];
    }
    int K_MAX = min(n, 650);
    vector<ll> dp_prev(n + 1, inf);
    vector<ll> dp_curr(n + 1, inf);
    dp_prev[0] = 0; 
    ll ans = inf;
    for (int k = 1; k <= K_MAX; ++k) {
        if (k == 1) {
            dp_curr[0] = 0;
        } else {
            dp_curr[0] = inf; 
        }
        deque<int> dq1; 
        deque<int> dq2; 

        if (dp_curr[0] != inf) dq1.push_back(0);
        if (dp_prev[0] != inf) dq2.push_back(0);

        for (int i = 1; i <= n; ++i) {
            dp_curr[i] = inf;

            
            while (!dq1.empty() && dq1.front() < i - k)  dq1.pop_front();
            while (!dq2.empty() && dq2.front() < i - (k - 1)) dq2.pop_front();
            if (i < n) {
                
                if (!dq1.empty()) {
                    int j = dq1.front();
                    dp_curr[i] = min(dp_curr[i], dp_curr[j] + 1);
                }
                if (k > 1 && !dq2.empty()) {
                    int j = dq2.front();
                    dp_curr[i] = min(dp_curr[i], dp_prev[j] + 1 + A[i]);
                }
            }
            if (i == n) {
                if (!dq1.empty()) ans = min(ans, dp_curr[dq1.front()]);
            }
            if (dp_curr[i] != inf) {
                while (!dq1.empty() && dp_curr[dq1.back()] >= dp_curr[i]) dq1.pop_back();
                dq1.push_back(i);
            }
            if (dp_prev[i] != inf) {
                while (!dq2.empty() && dp_prev[dq2.back()] >= dp_prev[i]) dq2.pop_back();
                dq2.push_back(i);
            }
        }
        dp_prev = dp_curr;
    }

    cout << ans << "\n";

    return 0;
}