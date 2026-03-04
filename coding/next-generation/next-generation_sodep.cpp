#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string

str sinh(str s) {
    ll i = s.size() - 1;
    while (i > -1 && s[i] == '8') {
        s[i] = '6';
        i--;
    }
    if (i == -1) {
        s = "6" + s;
        return s;
    }
    s[i] = '8';
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    str s = "6";
    ll n; 
    cin >> n;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < s.size(); i++) cout << s[i];
        for (int i = s.size() - 1; i > -1; i--) cout << s[i];
        cout << " ";
        s = sinh(s);
    }
    return 0;
}
