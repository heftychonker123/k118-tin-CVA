#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll INF = 1e16;
const int MOD = 1e9 + 7;

int n,q;
const int MAXN = 2e5 + 5;
vector<int> tree[MAXN];

const int LOGN = 31;
int par[MAXN][LOGN + 1];
int diff[MAXN], res[MAXN] , depth[MAXN];
void dfs(int u = 1 , int p = 0){
    par[u][0] = p;

    for (int &i : tree[u]){
        if (i != p){
            depth[i] = depth[u] + 1;
            dfs(i , u);
        }
    }
}

void preprocess(){
    dfs();

    for (int j = 1 ; j<32 ; j++){
        for (int i = 1 ; i<=n ; i++){
            par[i][j] = par[par[i][j-1]][j-1];
        }
    }
}

int liftK(int a , int k){
    for (int i = LOGN ; i>=0 ; i--){
        if (k & (1<<i)) a = par[a][i];
    }

    return a;
}

int lca(int a , int b){
    if (depth[a] < depth[b]) swap(a,b);
    a = liftK(a , depth[a] - depth[b]);
    if (a == b) return a;

    for (int i = LOGN ; i>=0 ; i--){
        if (par[a][i] != par[b][i]){
            a = par[a][i]; b = par[b][i];
        }
    }

    return par[a][0];
}

void reverse(int u = 1 , int p = 0){
    for (int &i : tree[u]){
        if (i != p){
            reverse(i , u);
            diff[u] += diff[i];
        }
    }
}

void solve(){
    preprocess();
    while (q--){
        int a,b ; cin >> a >> b;
        int t = lca(a,b);
        diff[t]--;
        diff[par[t][0]]--;

        diff[a]++;
        diff[b]++;
    }
    reverse();
    for (int i = 1 ; i<=n ; i++) cout << diff[i] << " ";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    for (int i = 1 ; i<n ; i++){
        int a,b ; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    solve();
}