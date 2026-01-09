#include <bits/stdc++.h>
using namespace std;

void solve(string n) {
    string res = "";
    int len = n.size();

    while (len % 3 != 0) {
        n = "0" + n;
        len++;
    }

    for (int i = 0; i < len; i += 3) {
        int val = (n[i]-'0')*4 + (n[i+1]-'0')*2 + (n[i+2]-'0');
        res += to_string(val);
    }

    while (res.size() > 1 && res[0] == '0') res.erase(res.begin());

    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string n;
    cin >> n;
    solve(n);
}
