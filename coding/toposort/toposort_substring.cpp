#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector

const ll MAXN = 3e5 + 5;
vect<ll> graph[MAXN];

bool hasCycle = false;
vect<ll> topo;
ll visited[MAXN];
void dfs(ll node){
    visited[node] = 1;
    for (int i : graph[node]){
        if (visited[i] == 1) hasCycle = true;
        else if (visited[i]==0) dfs(i);
    }
    visited[node] = 2;
    topo.push_back(node);
}
void toposort(ll n){
    for (int i = 1 ; i<=n ; i++){
        if (visited[i] == 0) dfs(i);
    }
}

void solve(ll n, vect<ll>& c){
    vect<vect<ll>> dp(n+1, vect<ll>(26, 0));
    for (ll i = 1; i <= n; i++) {
        dp[i][c[i-1]] = 1;
    }
    for (ll i : topo) {
        for (ll j : graph[i]) {
            for (int k = 0; k < 26; k++) {
                int add = ((c[j-1] == k) ? 1 : 0);
                dp[j][k] = max(dp[j][k], dp[i][k] + add);
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0 ; j<26 ; j++) ans = max(ans , dp[i][j]);
    }
    cout << ans << "\n";
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m ; cin >> n >> m;
    string s ; cin >> s;
    vect<ll> c(n); for(int i = 0; i<n ; i++) c[i] = s[i]-'a';
    for (int i=0 ; i<m ; i++){
        ll a,b ; cin >> a >> b;
        graph[a].push_back(b);
    }

    toposort(n);
    reverse(topo.begin() , topo.end());
    if (hasCycle) cout << -1 << "\n";
    else solve(n , c);
}