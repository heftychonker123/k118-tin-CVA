#include <bits/stdc++.h>
using namespace std;
#define filename "guess"
#define ll long long
#define vect vector

int main() {
    freopen(filename".inp", "r", stdin);
    freopen(filename".out", "w", stdout);

    int n, m; 
    cin >> n >> m;
    vect<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    set<ll> s;
    ll min_dis = LLONG_MAX;
    ll t=0;
    for (const ll &i : v) {
        if (!s.empty()) {
            auto high_it = s.upper_bound(i);
            auto low_it = s.lower_bound(i);

            if (low_it != s.begin()) {
                auto prev_it = low_it; 
                --prev_it;
                min_dis = min(min_dis, abs(i - *prev_it));
            }
            if (high_it != s.end()) {
                min_dis = min(min_dis, abs(i - *high_it));
            }
        }
        s.insert(i);
        if (min_dis<m){
            cout << t+1;
            return 0;
        }
        t++;
    }
    return 0;
}
