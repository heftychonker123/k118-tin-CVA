#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void solve() {
    string eval;
    cin >> eval;
    stack<string> st;

    for (int i = eval.size() - 1; i >= 0; i--) {
        char c = eval[i];
        if (isOperator(c)) {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();    
            string expr = op1 + op2 + c ;
            st.push(expr);
        } else {
            st.push(string(1, c));
        }
    }
    cout << st.top();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
