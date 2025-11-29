#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool check(ll num, ll height) {
    string temp = to_string(num);
    ll res=0;
    for (const char &ch : temp) {
        res += ch-'0';
    }
    return (res==height);
}

void solve(ll a, ll b , ll height) {
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
        if (prime[i] && check(i,height)) {
            cout << i << "\n";
            res++;
        }
    }
    cout << res << "\n";
}

int main() {
    int t=1;
    while (t--) {
        ll b;
        cin >> b;
        ll height;
        cin >> height;
        solve(0, b, height);
    }
    return 0;
}
