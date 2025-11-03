#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<int> v;

    if (n == 0) {
        v.push_back(0);
    } else {
        while (n > 0) {
            v.push_back(n % 2);
            n /= 2;
        }
    }

    // Print binary in correct order
    for (int i = v.size() - 1; i >= 0; i--) {
        cout << v[i];
    }
    cout << endl;

    return 0;
}
