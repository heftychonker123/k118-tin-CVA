#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int BASE = 31;
const ll MOD = 1000000007LL;
const int MAXN = 1e6 + 5;

ll p[MAXN];

vector<ll> buildHash(const string &s) {
    int n = s.size();
    vector<ll> h(n);
    h[0] = s[0] - 'A' + 1;
    for (int i = 1; i < n; i++) {
        h[i] = (h[i-1] * BASE + (s[i] - 'A' + 1)) % MOD;
    }
    return h;
}
ll getSubHash(const vector<ll> &h, int l, int r) {
    if (l == 0) return h[r];
    return (h[r] - h[l-1] * p[r-l+1] % MOD + MOD) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string pattern, text;
    cin >> pattern >> text;

    int m = pattern.size();
    int n = text.size();
    p[0] = 1;
    for (int i = 1; i < MAXN; i++) p[i] = p[i-1] * BASE % MOD;
    vector<ll> hashPattern = buildHash(pattern);
    ll hP = hashPattern.back();
    vector<ll> hashText = buildHash(text);

    vector<int> pos;
    for (int i = 0; i <= n - m; i++) {
        ll curr = getSubHash(hashText, i, i+m-1);
        if (curr == hP) pos.push_back(i);
    }

    cout << pos.size() << "\n";
    for (int x : pos) cout << x << " ";

    return 0;
}
