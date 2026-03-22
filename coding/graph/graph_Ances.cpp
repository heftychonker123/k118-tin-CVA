#include <bits/stdc++.h>
using namespace std;
#define filename "Ances"
#define ll                  long long
#define llmin               LLONG_MIN
#define llmax               LLONG_MAX
#define pb                  push_back
#define vect                vector
#define FOR(i , m , n)      for (int i=m ; i<n ; i++)
#define FOR_r(i , m , n)    for (int i=m ; i>n ; i--)
const ll MAXN =             10000;
ll parents[MAXN][20]; 
void preprocess(vect<ll> &reverse_tree, ll nodes) {
    ll LOG = log2(nodes) + 1;
    for (ll i = 0; i < nodes; i++) {
        parents[i][0] = reverse_tree[i];
    }

    for (ll j = 1; j < LOG; j++) {
        for (ll i = 0; i < nodes; i++) {
            if (parents[i][j-1] != -1) {
                parents[i][j] = parents[ parents[i][j-1] ][j-1];
            }
        }
    }
}
ll kthAncestor(ll node , ll k , ll n){
    while (k>0){
        
        ll powCnt = 0;
        while ((1LL<<powCnt) <= k) powCnt++; 
        powCnt--;
        node = parents[node][powCnt];
        k -= (1LL << powCnt);
    }
    return node;
}
vect<ll> dfs_depth(ll root , vect<vect<ll>> &tree , ll n){
    vect<ll> depth(n); depth[root]=0;
    stack<ll> st; st.push(root);
    while (!st.empty()){
        ll curr = st.top() ; st.pop();
        for (ll neighbor : tree[curr]){
            depth[neighbor] = depth[curr]+1;
            st.push(neighbor);
        }
    }
    return depth;
}
ll lca(ll root , ll a, ll b , vect<vect<ll>> &tree, ll n){
    vect<ll> depth = dfs_depth(root , tree , n);
    if (depth[a] > depth[b]) swap(a,b);
    ll k = depth[b] - depth[a];
    b = kthAncestor(b , k , n);

    if (a==b) return a;
    ll LOG = log2(n) + 1;
    for (int j = LOG - 1; j >= 0; j--) {
        if (parents[a][j] != parents[b][j]) {
            a = parents[a][j];
            b = parents[b][j];
        }
    }
    return parents[a][0];
}
void IO(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen(filename".inp" , "r"))
    {
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    }
}
int main() {
    IO();
    ll n, root;
    cin >> n >> root; 
    root--; 
    vect<vect<ll>> tree(n);
    vect<ll> reverse_tree(n, -1);
    for (int i = 0; i < n - 1; i++) {
        ll a, b;
        cin >> a >> b;
        a--; b--; 
        tree[a].push_back(b);
        reverse_tree[b] = a; 
    }
    memset(parents, -1, sizeof(parents));
    preprocess(reverse_tree, n);
    ll u, v;
    cin >> u >> v;
    u--; v--; 
    ll ans = lca(root, u, v, tree, n);
    cout << ans + 1 << "\n"; 
    return 0;
}