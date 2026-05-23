#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Cow {
    ll A, B;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;
    vector<ll> chickens(m);
    for (int i = 0; i < m; i++) cin >> chickens[i];
    vector<Cow> cows(n);
    for (int j = 0; j < n; j++) cin >> cows[j].A >> cows[j].B;

    sort(chickens.begin(), chickens.end());
    sort(cows.begin(), cows.end(), [](const Cow& x, const Cow& y){
        return x.B < y.B; 
    });

    multiset<ll> available(chickens.begin(), chickens.end());
    int res = 0;
    for (auto &cow : cows) {
        auto it = available.lower_bound(cow.A); 
        if (it != available.end() && *it <= cow.B) {
            res++;
            available.erase(it); 
        }
    }
    cout << res << "\n";
    return 0;
}
