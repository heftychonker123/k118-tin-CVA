#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define str string
#define llmin LLONG_MIN
#define llmax LLONG_MAX

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    str n;
    getline(cin, n);

    map<char, int> freq;

    for (const char &i : n) {
        if (i != ' ') {
            freq[i]++;
        }
    }

    ll max_freq = llmin, min_freq = llmax;
    char max_letter='a', min_letter='a';

    for (const auto &i : freq) {
        if (i.second >= max_freq) {
            max_letter = i.first;
            max_freq = i.second;
        }
        if (i.second <= min_freq) {
            min_letter = i.first;
            min_freq = i.second;
        }
    }

    cout << max_letter << " " << max_freq << "\n";
    cout << min_letter << " " << min_freq << "\n";

    return 0;
}
