#include <bits/stdc++.h>
using namespace std;

int check(string t, string n) {
    return (t.size() > n.size() || (t.size() == n.size() && t > n));
}

int main() {
    string n;
    getline(cin, n);

    if (n.empty()) {
        cout << "" << endl;
        return 0;
    }

    string t(1, n[0]);
    string ans = "";

    for (int i = 1; i < n.size(); i++) {
        if (n[i - 1] != n[i]) {
            t += n[i];
        } else {
            if (check(t, ans)) ans = t;
            t = string(1, n[i]);
        }
    }
    if (check(t, ans)) ans = t;

    cout << ans << endl;
}
