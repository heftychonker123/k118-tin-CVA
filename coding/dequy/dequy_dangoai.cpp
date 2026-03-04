#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define llmin LLONG_MIN
#define vect vector

ll n, w;
ll memo[20][1000];

ll knapsack(vect<ll> &weight, vect<ll> &price, ll currW = 0, ll idx = 0) {
    if (currW > w) return llmin;
    if (idx == n) return 0;
    if (memo[idx][currW] != -1) return memo[idx][currW];
    
    ll exclude = knapsack(weight, price, currW, idx + 1);
    
    ll include = llmin;
    if (currW + weight[idx] <= w) {
        include = price[idx] + knapsack(weight, price, currW + weight[idx], idx + 1);
    }
    
    return memo[idx][currW] = max(include, exclude);
}

void solve() {
    cin >> n >> w;
    memset(memo, -1, sizeof(memo));
    vect<ll> weight(n); for (int i = 0; i < n; i++) cin >> weight[i];
    vect<ll> price(n);  for (int i = 0; i < n; i++) cin >> price[i];
    cout << knapsack(weight, price);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
