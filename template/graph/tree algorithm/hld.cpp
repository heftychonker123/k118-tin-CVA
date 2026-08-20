#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Bài toán tổng trên 1 đoạn
int n;
const int MAXN = 2e5 + 5;
vector<int> tree[MAXN]; int a[MAXN];


ll st[4 * MAXN];

void update(int pos , ll x , int cl , int cr , int ci){
    if (cl == cr){
        st[ci] = x;
        return;
    }

    int cm = (cl + cr)/2;
    if (pos <= cm) update(pos , x , cl , cm , ci*2);
    else update(pos , x , cm + 1 , cr , ci * 2 + 1);
    st[ci] = st[ci * 2] + st[ci * 2 + 1];
}

ll query(int l , int r , int cl , int cr , int ci){
    if (l > r) return 0LL;
    if (l == cl && r == cr) return st[ci];

    int cm = (cl + cr)/2;
    ll left = query(l , min(cm,r) , cl , cm , ci * 2);
    ll right = query(max(l , cm + 1) , r , cl , cr , ci * 2 + 1);
    return left + right;
}




int par[MAXN] , sz[MAXN];
int label[MAXN]; int timer = 0; // Nhãn để query
int bigChild[MAXN]; // Lưu con "lớn" của node i
int chain[MAXN] , chainVal[MAXN]; // Lưu đỉnh của chuỗi "lớn" , chainVal lưu value của chuỗi

void dfs_par(int u){
    sz[u] = 1;
    for (int &i : tree[u]) if (i != par[u]){
        par[i] = u;
        dfs_par(i);
        sz[u] += sz[i];
    }
}

void dfs_label(int u){
    label[u] = ++timer;
    update(label[u] , a[u] , 1 , n , 1);
    for (int &i : tree[u]) if (i != par[u]){
        if (bigChild[u] == 0 || sz[i] >= sz[bigChild[u]]) 
            bigChild[u] = i;
    }

    if (bigChild[u] != 0) dfs_label(bigChild[u]);
    for (int &i : tree[u]) if (i != par[u] && i != bigChild[u]) dfs_label(i);
}

void dfs_chain(int u){
    for (int &i : tree[u]) if (i != par[u]){
        if (i == bigChild[u]) chain[i] = chain[u];
        else chain[i] = i;
        dfs_chain(i);
    }
}
// Query từ 1 đỉnh u -> v (v thuộc subtree của u)
ll sumPath(int u , int v){
    int res = 0;
    // Nhảy từ v cho đến khi ta đến đoạn "lớn" chứa v
    while (chain[u] != chain[v]){
        res += query(label[chain[v]] , label[v] , 1  , n , 1);
        v = par[chain[v]]; // Nhảy lên chain tiếp theo
    }

    // Giờ ta có v và u chung chain rồi
    // Ta sẽ lấy tổng từ label u -> v
    res += query(label[u] , label[v] , 1 , n , 1);
    return res;
}

// LCA
int jump[MAXN][32];
 
void preprocess(int n){
    for (int i = 1 ; i<=n ; i++) jump[i][0] = par[i];
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
    if (sz[a] < sz[b]) swap(a,b);
    a = lift(a , sz[a] - sz[b]);
 
    if (a == b) return a;
    for (int i = 31 ; i>=0 ; i--){
        if (jump[a][i] != jump[b][i]){
            a = jump[a][i];
            b = jump[b][i];
        }
    }
 
    return jump[a][0];
}

ll updateNode(int u , ll x){
    update(label[u] , x , 1 , n , 1);
    a[u] = x;
}

ll solveQuery(int u , int v){
    int node = lca(u , v);
    return sumPath(node , u) + sumPath(node , v) - a[node];
}

