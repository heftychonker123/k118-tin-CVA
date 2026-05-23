#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<ll> score(n+1, 0);
    vector<bool> active(n+1, true); 
    multiset<ll> ms;
    for (int i = 1; i <= n; i++) ms.insert(0);

    while (m--) {
        int q; cin >> q;
        if (q == 1) {
            int i; cin >> i;
            if (!active[i]) {
                active[i] = true;
                score[i] = 0;
                ms.insert(0);
            }
        } else if (q == 2) {
            int i; cin >> i;
            if (active[i]) {
                ms.erase(ms.find(score[i]));
                active[i] = false;
            }
        } else if (q == 3) {
            int i; ll delta; cin >> i >> delta;
            if (active[i]) {
                ms.erase(ms.find(score[i]));
                score[i] += delta;
                ms.insert(score[i]);
            }
        } else if (q == 4) {
            if (ms.empty()) {
                cout << "EMPTY\n";
            } else {
                int cnt = 0;
                for (auto it = ms.rbegin(); it != ms.rend() && cnt < 3; ++it, ++cnt) {
                    cout << *it << " ";
                }
                cout << "\n";
            }
        }
    }
    return 0;
}
