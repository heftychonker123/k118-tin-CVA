#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 2e5;
int n; vector<int> tree[MAXN + 1];
bool is_removed[MAXN + 1]; int sz[MAXN + 1];

int dfs_sz(int u , int p = 0){
    sz[u] = 1;
    for (int &v : tree[u]) if (v != p && !is_removed[v]){
        sz[u] += dfs_sz(v , u);
    }
}

int find_centroid(int u , int tree_sz , int p = 0){
    for (int &v : tree[u]) if (v != p && !is_removed[v]){
        if (sz[v] > tree_sz / 2) return find_centroid(v , u);
    }

    return u; // Đây chắc chẵn là centroid
}

int centroid_decompose(int u){
    int centroid = find_centroid(u , dfs_sz(u));

    // Giải bài toán ở subgraph này

    is_removed[centroid] = true;
    // Xây dựng các subgraph 
    for (int &v : tree[centroid]) if (!is_removed[v]){
        centroid_decompose(v);
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

}