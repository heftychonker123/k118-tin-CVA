#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    freopen("dif.inp" , "r" , stdin);
    freopen("dif.out" , "w" , stdout);
    ll n; cin >> n;
    set<ll> num;
    multiset<ll> diff;

    while (n--) {
        ll t; cin >> t;

        auto it = num.insert(t).first; // insert and get iterator

        auto prev = it, next = it;
        bool hasPrev = false, hasNext = false;

        if (it != num.begin()) {
            prev--;
            hasPrev = true;
        }
        next++;
        if (next != num.end()) {
            hasNext = true;
        }

        // remove old difference if both neighbors existed
        if (hasPrev && hasNext) {
            diff.erase(diff.find(*next - *prev));
        }

        // add new differences
        if (hasPrev) diff.insert(*it - *prev);
        if (hasNext) diff.insert(*next - *it);

        // print current maximum difference
        if (!diff.empty()) {
            cout << *diff.rbegin() << "\n";
        } else {
            cout << 0 << "\n"; // only one element
        }
    }
}
