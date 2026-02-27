#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool check(ll num) {
    string temp = to_string(num);
    for (char ch : temp) {
        switch (ch) {
            case '2': case '3': case '5': case '7':
                continue;
            default:
                return false;
        }
    }
    return true;
}

void solve(ll a, ll b) {
    vector<bool> prime(b+1, true);
    prime[0] = prime[1] = false;

    for (ll i = 2; i * i <= b; i++) {
        if (prime[i]) {
            for (ll j = i * i; j <= b; j += i) {
                prime[j] = false;
            }
        }
    }

    ll res = 0;
    for (ll i = a; i <= b; i++) {
        if (prime[i] && check(i)) {
            res++;
        }
    }
    cout << res << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        solve(a, b);
    }
    return 0;
}
