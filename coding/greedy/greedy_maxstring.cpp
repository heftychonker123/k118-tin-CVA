#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll K;
    string S;
    cin >> K >> S;

    
    vector<ll> freq(256, 0);
    for (char c : S) freq[(unsigned char)c]++;

    
    priority_queue<ll> pq;
    for (ll f : freq) if (f > 0) pq.push(f);

    
    while (K > 0 && !pq.empty()) {
        ll top = pq.top(); pq.pop();
        top--; K--;
        if (top > 0) pq.push(top);
    }

    ll res = 0;
    while (!pq.empty()) {
        ll f = pq.top(); pq.pop();
        res += f * f;
    }

    cout << res << "\n";
    return 0;
}
