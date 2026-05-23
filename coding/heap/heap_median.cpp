#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin >> n;
    priority_queue<ll> left; // max-heap
    priority_queue<ll, vector<ll>, greater<ll>> right; // min-heap

    for (int i = 0; i < n; i++) {
        string query; cin >> query;
        if (query == "push") {
            ll t; cin >> t;
            if (left.empty() || t <= left.top()) left.push(t);
            else right.push(t);

            // balance
            if (left.size() > right.size() + 1) {
                right.push(left.top());
                left.pop();
            } else if (right.size() > left.size()) {
                left.push(right.top());
                right.pop();
            }
        }
        if (query == "median") {
            if (left.size() == right.size()) {
                cout << left.top() << " " << right.top() << "\n";
            } else {
                cout << left.top() << "\n";
            }
        }
    }
    return 0;
}
