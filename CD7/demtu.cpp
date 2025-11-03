#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string n;
    getline(cin, n);

    stringstream ss(n);
    vector<string> s((istream_iterator<string>(ss)), istream_iterator<string>());

    cout << s.size() << '\n';
    for (const string &word : s) {
        cout << word << '\n';
    }

    return 0;
}
