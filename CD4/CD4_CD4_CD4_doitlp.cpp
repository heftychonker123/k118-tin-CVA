#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<char> hex;

    if (n == 0) {
        hex.push_back('0');
    } else {
        while (n > 0) {
            int remainder = n % 16;
            if (remainder < 10)
                hex.push_back('0' + remainder); // 0–9
            else
                hex.push_back('A' + remainder - 10); // A–F
            n /= 16;
        }
    }

    for (int i = hex.size() - 1; i >= 0; i--) {
        cout << hex[i];
    }
    cout << endl;

    return 0;
}
