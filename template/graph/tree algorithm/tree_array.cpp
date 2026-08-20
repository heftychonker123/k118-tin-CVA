#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 2e5 + 5;
int n;
vector<int> tree[MAXN];

int timer = 0;
int tin[MAXN] , tout[MAXN];
int euler_tour[2*MAXN];

void dfs(int u = 1 , int p = 0){
    tin[u] = timer;
    euler_tour[timer++] = u;
    for (int &i : tree[u]){
        if (i != p){
            dfs(i , u);
            euler_tour[timer++] = u;
        }
    }
}

// Example : Lowest Common Ancestor
ll sparse[MAXN][32];

void buildSparse(int a[] , ll len){
    for (int i = 1 ; i<=len ; i++){
        sparse[i][0] = a[i];
    }

    for (int j = 1 ; j<32 ; j++){
        for (ll i = 1 ; i<=len ; i++){
            if (i + (1LL << j) <= len) 
                sparse[i][j] = min(sparse[i][j-1] , sparse[i + (1LL << j)][j-1]);
        }
    }
}
int log2(int x){
    return (x ? __builtin_clz(1) - __builtin_clz(x) : -1);
}

ll minQuery(int l , int r){
    int log = log2(r-l+1);
    return min(sparse[l][log] , sparse[r - (1<<log) + 1][log]);
}


void lca(int a , int b){
    if (tin[a] > tin[b]) swap(a,b);
    cout << minQuery(tin[a] , tin[b]) << "\n";
}

signed main(){
    int n ; cin >> n;
    for (int i = 0 ; i<n-1 ; i++){
        int a,b ; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs();
    buildSparse(euler_tour , 2 * n);
    lca(3 , 2);
}

