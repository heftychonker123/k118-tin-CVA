#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector

ll dp(ll x, vect<ll> &coins, vect<ll> &memo, vect<ll> &choice) {
    if (x == 0) return 0;
    if (x < 0) return LLONG_MAX/2;
    if (memo[x] != -1) return memo[x];

    ll res = LLONG_MAX/2;
    for (int i = 0; i < coins.size(); i++) {
        ll sub = dp(x - coins[i], coins, memo, choice);
        if (sub + 1 < res) {
            res = sub + 1;
            choice[x] = i;
        }
    }
    return memo[x] = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("tratien.inp" , "r" , stdin);
    freopen("tratien.out" , "w" , stdout);
    ll n, x; 
    cin >> n >> x;
    vect<ll> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    vect<ll> memo(x+1, -1);
    vect<ll> choice(x+1, -1);

    ll res = dp(x, coins, memo, choice);
    if (res >= LLONG_MAX/2) {
        cout << -1 << "\n";
        return 0;
    }

    cout << res << "\n";

    vect<ll> ans(n, 0);
    ll cur = x;
    while (cur > 0 && choice[cur] != -1) {
        int coinIdx = choice[cur];
        ans[coinIdx]++;
        cur -= coins[coinIdx];
    }

    for (ll c : ans) cout << c << " ";
    cout << "\n";
}
