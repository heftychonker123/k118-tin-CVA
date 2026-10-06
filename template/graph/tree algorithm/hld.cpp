#include <bits/stdc++.h>
using namespace std;
#define ll long long 

// Do HLD có độ phức tạp O(nlog^2(n)) nên thường n <= 1e5
const int MAXN = 1e5;
int n; vector<int> graph[MAXN+1];

int sz[MAXN + 1] , depth[MAXN + 1];
void calc_sz(int u , int p = 0){
    sz[u] = 1;
    for (int& v : graph[u]) if (v != p){
        depth[v] = depth[u] + 1;
        calc_sz(v , u);
        sz[u] += sz[v];
    }
}

int label[MAXN + 1] , chain[MAXN + 1] , timer = 0;
int parent[MAXN + 1];

void dfs(int u , int p = 0){
    parent[u] = p;
    label[u] = timer++;
    int bigChild = 0;
    for (int &v : graph[u]) if (v != p && sz[v] > sz[bigChild]) bigChild = v;
    
    if (bigChild != 0){
        chain[bigChild] = chain[u];
        dfs(bigChild , u);
    }
    for (int &v : graph[u]) if (v != p && v != bigChild){
        chain[v] = v;
        dfs(v , u);
    }
}

int st[MAXN * 4 + 1];
void update(int pos , int x , int cl , int cr , int ci){
    if (cl == cr){
        st[ci] = x;
        return;
    }

    int cm = (cl + cr)/2;
    if (pos <= cm) update(pos , x , cl , cm , ci * 2);
    else update(pos , x , cm + 1 , cr , ci * 2 + 1);
    st[ci] = max(st[ci * 2] , st[ci * 2 + 1]);
}

int query(int l , int r , int cl , int cr , int ci){
    if (l > cr || r < cl) return 0;
    if (l <= cl && cr <= r) return st[ci];

    int cm = (cl + cr)/2;
    return max(query(l , r , cl , cm , ci * 2) , query(l , r , cm + 1 , cr , ci * 2 + 1));
}

int lca(int a , int b){
    while (chain[a] != chain[b]){
        if (depth[chain[a]] < depth[chain[b]]) swap(a,b);
        a = parent[chain[a]]; // Nhảy qua cái chain này
    }

    return (depth[a] < depth[b]? a : b);
}


// Giả sử u là tổ tiên của v
int getMaxPath(int u , int v){
    int res = 0;
    while (chain[u] != chain[v]){
        res = max(res , query(label[chain[v]] , label[v] , 0 , timer , 1));
        v = parent[chain[v]];
    }

    res = max(res , query(label[u] , label[v] , 0 , timer , 1));
    return res;
}


int solveQuery(int a , int b){
    int ances = lca(a,b);
    return max(getMaxPath(ances , a) , getMaxPath(ances , b));
}

void updateNode(int u , int x){
    update(label[u] , x , 0 , timer , 1);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,q ; cin >> n >> q;
    vector<int> v(n+1) ; for (int i = 1 ; i<=n ; i++) cin >> v[i];
    for (int i = 1 ; i<n ; i++){
        int a,b ; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    calc_sz(1);
    dfs(1);
    for (int i = 1 ; i<=n ; i++) update(label[i] , v[i] , 0 , timer , 1);
    while (q--){
        int t ; cin >> t;
        if (t == 1){
            int s,x ; cin >> s >> x;
            updateNode(s , x);
        }
        else if (t == 2){
            int a,b ; cin >> a >> b;
            cout << solveQuery(a,b) << '\n';
        }
    }
}