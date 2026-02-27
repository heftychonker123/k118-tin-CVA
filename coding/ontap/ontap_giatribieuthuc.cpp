#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<long double> number;
    stack<string> operation;

    string t;
    while (getline(cin, t)) {
        if (t.empty()) break; // nếu dòng trống thì thoát vòng lặp

        if (t=="+"||t=="-"||t=="*"||t=="/") {
            operation.push(t);
        } else {
            number.push(stold(t));
        }
    }


    while (number.size() > 1 && !operation.empty()) {
        long double a = number.top(); number.pop();
        long double b = number.top(); number.pop();
        string op = operation.top(); operation.pop();

        long double res = 0;
        if (op == "+") res = b + a;
        else if (op == "-") res = b - a;
        else if (op == "*") res = b * a;
        else if (op == "/") {
            res = b / a;
        }
        cout <<"last operation results:" << res << "\n";
        number.push(res);
    }

    if (!number.empty()) cout << number.top() << "\n";
    else cout << "Error: No result\n";

    return 0;
}
