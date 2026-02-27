#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    freopen("glass.inp" , "r" , stdin);
    freopen("glass.out" , "w" , stdout);
    ll w, h, n;
    cin >> h >> w >> n;

    set<ll> w_num = {0, w};
    set<ll> h_num = {0, h};
    multiset<ll> w_diff = {w};
    multiset<ll> h_diff = {h};

    while (n--) {
        char qtype;
        ll t;
        cin >> qtype >> t;

        if (qtype == 'V') {
            auto it = w_num.insert(t).first;
            auto prev = it; prev--;
            auto next = it; next++;

            // remove old difference
            w_diff.erase(w_diff.find(*next - *prev));
            // add new differences
            w_diff.insert(*it - *prev);
            w_diff.insert(*next - *it);
        } 
        else if (qtype == 'H') {
            auto it = h_num.insert(t).first;
            auto prev = it; prev--;
            auto next = it; next++;

            h_diff.erase(h_diff.find(*next - *prev));
            h_diff.insert(*it - *prev);
            h_diff.insert(*next - *it);
        }

        ll max_w = *w_diff.rbegin();
        ll max_h = *h_diff.rbegin();
        cout << max_w * max_h << "\n";
    }
}
