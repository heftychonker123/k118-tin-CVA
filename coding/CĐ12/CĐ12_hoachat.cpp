#include <bits/stdc++.h>
using namespace std;

long long solve(const string &n) {
    stack<long long> st;
    for (int i = 0; i < (int)n.size(); i++) {
        char c = n[i];
        if (c == 'C') st.push(12);
        else if (c == 'H') st.push(1);
        else if (c == 'O') st.push(16);
        else if (c == '(') st.push(-1);
        else if (c == ')') {
            long long sum = 0;
            while (!st.empty() && st.top() != -1) {
                sum += st.top();
                st.pop();
            }
            if (!st.empty() && st.top() == -1) st.pop();
            st.push(sum);
        }
        else if (isdigit(c)) {
            int d = c - '0';
            long long val = st.top(); st.pop();
            st.push(val * d);
        }
    }
    long long res = 0;
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    cout << solve(s) << "\n";
    return 0;
}
