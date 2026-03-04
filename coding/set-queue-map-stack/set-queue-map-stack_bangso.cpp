#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll largestRectangle(vector<ll>& h) {
    int n = h.size();
    stack<int> st;
    vector<int> left(n), right(n);

    for (int i = 0; i < n; i++) {
        while (!st.empty() && h[st.top()] >= h[i]) st.pop();
        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    while (!st.empty()) st.pop();

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && h[st.top()] >= h[i]) st.pop();
        right[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    ll ma = 0;
    for (int i = 0; i < n; i++) {
        ll area = (right[i] - left[i] - 1) * h[i];
        ma = max(ma, area);
    }
    return ma;
}

void solve() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> v(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) cin >> v[i][j];
    }

    vector<ll> h(n, 0);
    ll ans = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] == 1) h[j] += 1;
            else h[j] = 0;
        }
        ans = max(ans, largestRectangle(h));
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
