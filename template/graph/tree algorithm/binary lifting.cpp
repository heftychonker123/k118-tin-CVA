#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
const bool debug = false;
const string filename = "";
 
const ll INF = 1e16;
const int MOD = 1e9 + 7;
 
const int MAXN = 2e5 + 5;
vector<int> tree[MAXN];
 
// Binary jumping
int jump[MAXN][32];
ll depth[MAXN];
void dfs(int u = 1 , int p = 0){
 
    for (int &i : tree[u]){
        if (i != p){
            depth[i] = depth[u] + 1;
            jump[i][0] = u;
            dfs(i , u);
        }
    }
}
 
void preprocess(int n){
    dfs();
    for (int j = 1; j < 32; j++){ // Note: j loop on outside is safer
        for (int i = 1; i <= n; i++){
            if (jump[i][j-1] != 0)
                jump[i][j] = jump[jump[i][j-1]][j-1];
            else
                jump[i][j] = 0; // Explicitly set to 0 if parent is 0
        }
    }
}
 
int lift(int u, long long k){
    for (int i = 0; i < 32; i++){
        if (k & (1LL << i)) u = jump[u][i];
    }
    return u;
}
 
int lca(int a , int b){
    if (depth[a] < depth[b]) swap(a,b);
    a = lift(a , depth[a] - depth[b]);
 
    if (a == b) return a;
    for (int i = 31 ; i>=0 ; i--){
        if (jump[a][i] != jump[b][i]){
            a = jump[a][i];
            b = jump[b][i];
        }
    }
 
    return jump[a][0];
}
 
ll calcDist(int a , int b){return depth[a] + depth[b] - 2 * depth[lca(a,b)];}
 
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    if (fopen((filename + ".inp").c_str() , "r")){
        freopen((filename + ".inp").c_str() , "r" , stdin);
        freopen((filename + ".out").c_str() , "w" , stdout);
    }
 
    int n,q ; cin >> n >> q;
    for (int i = 2 ; i<=n ; i++){
        int a ; cin >> a;
        tree[a].push_back(i);
        tree[i].push_back(a);
    }
 
    preprocess(n);
    while (q--){
        int a,b ; cin >> a >> b;
        cout << lca(a,b) << "\n";
    }
