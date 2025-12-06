#include <bits/stdc++.h>
using namespace std;
#define ll long long

set<ll> difference(const vector<ll>& a, const vector<ll>& b) {
    unordered_set<ll> s(b.begin(), b.end());
    set<ll> res;
    for (const ll &i : a) {
        if (s.find(i) == s.end()) {
            res.insert(i);
        }
    }
    return res;
}
set<ll> set_union(set<ll> a , set<ll> b){
    set<ll> res;
    for (const ll &i : a) res.insert(i);
    for (const ll &i : b) res.insert(i);
    return res;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    set<ll> diffAB = difference(a, b);
    set<ll> diffBA = difference(b, a);
    set<ll> res = set_union(diffAB,diffBA);
    for (const ll &i : res) cout << i << " ";
    cout << "\n";
    return 0;
}
