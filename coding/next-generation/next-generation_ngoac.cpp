#include <bits/stdc++.h>
using namespace std;

void solve() {
    int m; 
    cin >> m;          // total length of the Dyck word

    int pairs = m / 2; // number of pairs
    string s(pairs, '(');   // start with (((...)))
    s += string(pairs, ')'); // then )))

    while (true) {
        cout << s << "\n";

        // Step 1: find rightmost '(' that can be flipped
        int opens = 0, closes = 0;
        int pos = -1;
        for (int i = m - 1; i >= 0; i--) {
            if (s[i] == '(') {
                opens++;
                if (closes > opens) { // safe to flip here
                    pos = i;
                    break;
                }
            } else {
                closes++;
            }
        }
        if (pos == -1) break; // no more Dyck words

        // Step 2: flip '(' to ')'
        s[pos] = ')';

        // Step 3: rebuild suffix after pos
        int usedOpens = count(s.begin(), s.begin() + pos + 1, '(');
        int usedCloses = count(s.begin(), s.begin() + pos + 1, ')');
        int remainingOpens = pairs - usedOpens;
        int remainingCloses = pairs - usedCloses;

        string suffix(remainingOpens, '(');
        suffix += string(remainingCloses, ')');
        s.replace(pos + 1, m - pos - 1, suffix);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
