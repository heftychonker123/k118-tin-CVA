#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define filename "seq"
int main() {
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    int N; cin >> N;
    map<ll,ll> freq;
    for (int i = 0; i < N; i++) {
        ll t; cin >> t;
        freq[t]++;
    }

    int q; cin >> q;
    while (q--) {
        int type; cin >> type;

        if (type == 1) {
            ll x; cin >> x;
            freq[x]++;
        }
        else if (type == 2) {
            ll x; cin >> x;
            freq.erase(x);
        }
        else if (type == 3) {
            ll x; cin >> x;
            auto it = freq.upper_bound(x);
            if (it != freq.end()) cout << it->first << endl;
            else cout << "No" << endl;
        }
        else if (type == 4) {
            ll x; cin >> x;
            auto it = freq.lower_bound(x);
            if (it != freq.begin()) {
                --it;
                cout << it->first << endl;
            } else {
                cout << "No" << endl;
            }
        }
        else if (type == 5) {
            if (freq.empty()) {
                cout << "No" << endl;
            } else {
                cout << freq.begin()->first << " " << freq.rbegin()->first << endl;
            }
        }
    }

    return 0;
}
