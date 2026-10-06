#include <bits/stdc++.h>
using namespace std;
#define ll long long

int log2_floor(int n){
    if (n == 0) return -1;
    return __builtin_clz(1) - __builtin_clz(n);
}

template <typename T> struct SparseTable{
    int length;
    vector<vector<T>> sparse;
    SparseTable(){}
    SparseTable(vector<T>& a){
        length = a.size();
        sparse.resize(n + 1);
        for (int i = 1 ; i <= n ; i++) sparse[i].resize(log2(n) + 1);
        for (int i = 1 ; i<=n ; i++) sparse[i][0] = a[i];
        for (int j = 1 ; j < log2(n) ; j++){
            for (int i = 1 ; i + (1 << j) - 1 <= n ; i++){
                sparse[i][j] = min(sparse[i][j-1] , sparse[i + (1 << (j-1))][j-1]);
            }
        }
    }

    T query(int l , int r){
        int log = log2_floor(r - l + 1);
        return min(sparse[l][log] , sparse[r - (1 << log) + 1][log]);
    }
};

struct LCA{
    vector<vector<int>> tree;
    vector<int> tin , depth; vector<pair<int,int>> euler_tour;
    SparseTable<pair<int,int>> rmq;
    int timer = 0;
    void dfs(int u , int p = 0){
        tin[u] = ++timer;
        for (int &v : tree[u]) if (v != p){
            depth[v] = depth[u] + 1;
            dfs(v , u);
            euler_tour.push_back({u , depth[u]});
            timer++;
        }
    }

    LCA(int n , vector<vector<int>>&graph){
        tin.resize(n+1);
        depth.resize(n+1);
        tree = graph;
        dfs(1);

        rmq = SparseTable<pair<int,int>> (euler_tour);
    }

    int query(int a , int b){
        if (tin[a] > tin[b]) swap(a,b);
        return rmq.query(tin[a] , tin[b]).second;
    }
};

