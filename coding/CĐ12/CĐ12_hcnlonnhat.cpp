#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n; 
    cin >> n;
    vector<ll> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];

    vector<int> left(n), right(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && h[st.top()] >= h[i]) st.pop();
        if (st.empty()) left[i] = -1;
        else left[i] = st.top();
        st.push(i);
    }

    while (!st.empty()) st.pop();

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && h[st.top()] >= h[i]) st.pop();
        if (st.empty()) right[i] = n;
        else right[i] = st.top();
        st.push(i);
    }

    ll maxArea = 0;
    for (int i = 0; i < n; i++) {
        ll width = right[i] - left[i] - 1;
        ll area = h[i] * width;
        maxArea = max(maxArea, area);
    }

    cout << maxArea << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
