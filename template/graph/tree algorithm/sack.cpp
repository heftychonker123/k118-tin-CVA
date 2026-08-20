#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 2e5 + 5;
int c[MAXN] , sort_c[MAXN] , comp_c[MAXN];
vector<int> tree[MAXN];

int sz[MAXN];
void calc(int u = 1 , int p = 0){
    sz[u] = 1;
    for (int &i : tree[u]) if (i != p){
        calc(i , u);
        sz[u] += sz[i];
    }
}

int cnt[MAXN] , distinct = 0;
void add(int u , int p){
    if (cnt[comp_c[u]]++ == 0) distinct++;
    for (int &i : tree[u]) if (i != p) add(i , u);
}

void remove(int u , int p){
    if (--cnt[comp_c[u]] == 0) distinct--;
    for (int &i : tree[u]) if (i != p) remove(i , u);
}

int res[MAXN];
void solve(int u = 1 , int p = 0){
    int bigChild = 0;
    for (int &i : tree[u]) if (i != p){
        if (sz[bigChild] < sz[i]) bigChild = i;
    }

    for (int &i : tree[u]) if (i != p && i != bigChild){
        solve(i , u);
        remove(i , u);
    }

    if (bigChild != 0) solve(bigChild , u);
    for (int &i : tree[u]) if (i != p && i != bigChild) add(i , u);

    if (cnt[comp_c[u]]++ == 0) distinct++;
    res[u] = distinct;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n ; cin >> n;
    for (int i = 1 ; i<=n ; i++){
        cin >> c[i];
        sort_c[i] = c[i];
    }
    sort(sort_c + 1 , sort_c + n + 1);
    for (int i = 1 ; i<=n ; i++){
        int pos = lower_bound(sort_c , sort_c + n , c[i]) - sort_c;
        comp_c[i] = pos;
    }
    for (int i = 0 ; i<n-1 ; i++){
        int a,b ; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    calc();
    solve();
    for (int i = 1 ; i<=n ; i++) cout << res[i] << " ";
}
