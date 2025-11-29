#include <bits/stdc++.h>
using namespace std;
#define str string

void solve(str a, str b) {
    int length = max(a.size(), b.size());
    while (a.size() < length) a = "0" + a;
    while (b.size() < length) b = "0" + b;

    int carry = 0;
    str res = "";

    for (int i = length - 1; i >= 0; i--) {
        int x = a[i] - '0';
        int y = b[i] - '0';
        int temp = x + y + carry;

        carry = temp / 10;
        res = char('0' + (temp % 10)) + res;
    }

    if (carry) res = char('0' + carry) + res;

    int start = 0;
    while (start < res.size() - 1 && res[start] == '0') start++;
    cout << res.substr(start) << endl;
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        str a, b;
        cin >> a >> b;
        solve(a, b);
    }
    return 0;
}
