#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;

    map<char, long long> freq;
    for (char c : S) {
        freq[c]++;
    }

    char maxChar = 'z' + 1, minChar = 'a' - 1;
    long long maxFreq = LLONG_MIN, minFreq = LLONG_MAX;

    for (auto &[ch, cnt] : freq) {
        if (cnt > maxFreq || (cnt == maxFreq && ch < maxChar)) {
            maxFreq = cnt;
            maxChar = ch;
        }
        if (cnt < minFreq || (cnt == minFreq && ch > minChar)) {
            minFreq = cnt;
            minChar = ch;
        }
    }

    cout << maxChar << " " << maxFreq << "\n";
    cout << minChar << " " << minFreq << "\n";
    cout << freq.size() << "\n";

    return 0;
}
