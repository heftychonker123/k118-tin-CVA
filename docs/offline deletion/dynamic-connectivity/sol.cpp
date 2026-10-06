#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define solvrad ios::sync_with_stdio(0); cin.tie(0)

struct DSU{
    vector<int> par , sz; int components;

    vector<pair<int, int*>> hist;

    int find(int a){
        while (a != par[a]) a = par[a];
        return a;
    }

    void merge(int a , int b){
        a = find(a) ; b = find(b);
        if (a != b){
            if (sz[a] < sz[b]) swap(a,b);
            hist.push_back({sz[a] , &sz[a]});
            hist.push_back({par[b] , &par[b]});
            hist.push_back({components , &components});
            par[b] = a; sz[a] += sz[b]; components--;
        }
    }

    int snapshot(){return hist.size();}
    void rollback(int time){
        while (snapshot() > time){
            *hist.back().second = hist.back().first;
            hist.pop_back();
        }       
    }

    DSU(int n){
        par.resize(n+1) ; sz.resize(n+1); components = n;
        for (int i = 1 ; i<=n ; i++){par[i] = i ; sz[i] = 1;}
    }

    DSU(){}
};

const int MAXN = 1e5 + 1;

#define fi first 
#define se second 

struct segmentTree{
    vector<vector<pair<int,int>>> st;
    DSU d;
    void addEdge(pair<int,int> edge , int l , int r , int cl , int cr , int ci){
        if (l > cr || r < cl) return;
        if (l <= cl && cr <= r){
            st[ci].push_back(edge);
            return;
        }

        int cm = (cl + cr)/2;
        addEdge(edge , l , r , cl , cm , ci * 2);
        addEdge(edge , l , r , cm + 1 , cr , ci * 2 + 1);
    }

    void dfs(vector<int>& ans , int cl , int cr , int ci){
        int baseTime = d.snapshot(); // Lưu thời gian trước khi cho các cạnh
        for (auto &edge : st[ci]) d.merge(edge.fi , edge.se); // Thêm cạnh cho node này

        int cm = (cl + cr)/2;
        // Xuống 2 con
        if (cl != cr){
            dfs(ans , cl , cm , ci * 2);
            dfs(ans , cm + 1 , cr , ci * 2 + 1);
        }
        else ans[cl] = d.components;
        // Xóa các cạnh đã thêm lúc trước
        d.rollback(baseTime);
    }

    segmentTree(int time , int nodes){
        d = DSU(nodes);
        st.resize((time + 1) * 4);
    }
};

signed main(){
    solvrad;

    int n , m , k; cin >> n >> m >> k;

    map<pair<int,int> , pair<int,int>> edges;
    for (int i = 0 ; i < m ; i++){
        int a,b ; cin >> a >> b;
        if (a > b) swap(a,b);
        edges[make_pair(a,b)] = {0 , k};
    }

    segmentTree st(k , n);
    for (int i = 1 ; i<=k ; i++){
        int t,a,b ; cin >> t >> a >> b;
        if (a > b) swap(a,b);
        
        if (t == 1) edges[make_pair(a,b)] = {i,k}; // cạnh này chưa tồn tại -> thêm vào
        if (t == 2){
            // Đóng cạnh lại
            edges[make_pair(a,b)] = {edges[make_pair(a,b)].first , i - 1};
            st.addEdge(make_pair(a,b) , edges[make_pair(a,b)].first , edges[make_pair(a,b)].second , 0 , k , 1);
            edges.erase(make_pair(a,b));
        } 
    }

    for (auto [edge , time] : edges) st.addEdge(edge , time.first , time.second , 0 , k , 1);

    vector<int> ans(k + 1);
    st.dfs(ans , 0 , k , 1);

    for (int i = 0 ; i<=k ; i++) cout << ans[i] << ' ';
}