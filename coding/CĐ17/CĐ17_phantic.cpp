#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define filename "PHANTICH"
vector<ll> prime;

ll ways(ll n, ll idx, ll currsum, vector<vector<ll>> &memo) {
    if (currsum == n) return 1;
    if (currsum > n || idx == prime.size()) return 0;

    if (memo[idx][currsum] != -1) return memo[idx][currsum];

    ll include = ways(n, idx + 1, currsum + prime[idx], memo);
    ll exclude = ways(n, idx + 1, currsum, memo);

    return memo[idx][currsum] = include + exclude;
}
ll largestProduct(ll n, ll idx, ll currsum, vector<vector<ll>> &memo, ll currpro) {
    if (currsum == n) return currpro;
    if (currsum > n || idx == prime.size()) return 0; 

    if (memo[idx][currsum] != -1) return memo[idx][currsum];

    ll include = largestProduct(n, idx + 1, currsum + prime[idx], memo, currpro * prime[idx]);
    ll exclude = largestProduct(n, idx + 1, currsum, memo, currpro);

    return memo[idx][currsum] = max(include, exclude);
}

void solve() {
    ll n; cin >> n;

    vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;
    for (ll i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (ll j = i*i; j <= n; j += i) isPrime[j] = false;
        }
    }
    for (ll i = 2; i <= n; i++) if (isPrime[i]) prime.push_back(i);

    vector<vector<ll>> memo1(prime.size(), vector<ll>(n+1, -1));
    vector<vector<ll>> memo2(prime.size(), vector<ll>(n+1, -1));
    ll t = ways(n, 0, 0, memo1) ;
    cout << t;
    if (t>0){
    cout << "\n" << largestProduct(n,0,0,memo2,1);}
}
void IO(){
    freopen(filename".INP" , "r" , stdin);
    freopen(filename".OUT" , "w" , stdout);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    IO();
    solve();
    return 0;
}
