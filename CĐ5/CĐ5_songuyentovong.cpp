#include <bits/stdc++.h>
using namespace std;

bool check_prime(long long n) {
    if (n < 2) return false;
    if (n == 2) return true;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

bool rot_prime(long long n) {
    string s = to_string(n);
    int len = s.size();
    for (int i = 0; i < len; i++) {
        long long rotated = stoll(s);
        if (!check_prime(rotated)) return false;
        rotate(s.begin(), s.begin() + 1, s.end());  // Rotate left
    }
    return true;
}

int main() {
    long long ans = 0;
    long long n;
    cin >> n;
    for (long long i = 2; i < n; i++) {
        if (rot_prime(i)) ans++;
    }
    cout << ans << endl;
}
