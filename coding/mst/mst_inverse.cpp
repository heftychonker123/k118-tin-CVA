#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector
#pragma GCC optimize -03
using pil = pair<int,ll>;
const ll MAXN = 2005;
vect<pair<int,ll>> tree[MAXN];
ll v[MAXN][MAXN];


ll addedEdge = 0;
int dsu[MAXN] , s[MAXN];
ll find(ll node){
    if (node != dsu[node]) return dsu[node] = find(dsu[node]);
    else return node;
}
void merge(ll a , ll b){
    a = find(a) ; b = find(b);
    if (s[a] < s[b]) swap(a,b);
    s[a] += s[b];
    dsu[b] = a;
}
bool comp(pair<int,pil>& a , pair<int,pil>& b){
    return a.second.second < b.second.second;
}
void kruskal(vect<pair<int,pil>>& edges){
    sort(edges.begin() , edges.end() , comp);
    for (auto [i , t] : edges){
        auto [j,d] = t;
        if (find(j) != find(i)){
            tree[i].push_back({j , d});
            tree[j].push_back({i,d});
            merge(i,j);
            addedEdge++;
        }
    }
}

bool dfs(int u, int p, int src, int d) {
	if (v[src][u] != d || (src != u && v[src][u] == 0)) return false;
	bool ans = 1;
	for (const auto &e : tree[u]) {
		if (e.first == p) continue;
		ans &= dfs(e.first, u, src, d + e.second);
	}
	return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n ; cin >> n;
    for (int i = 0  ; i<n ; i++){
        dsu[i] = i  ; s[i] = 1;
    }
    vect<pair<int,pil>> edges;
    for (int i = 0 ; i<n ; i++){
        for (int j = 0 ; j<n ; j++){
            cin >> v[i][j];
            if (i == j){
                if (v[i][j] != 0){
                    cout << "NO";
                    return 0;
                }
            }
            else {
                if (i > j) if (v[i][j] != v[j][i]){
                    cout << "NO";
                    return 0;
                }
                if (i < j) edges.push_back(make_pair(i , make_pair(j , v[i][j])));
            }
        }
    }
    kruskal(edges);
    for (int i = 0 ; i < n ; i++){
        if (!dfs(i , -1 , i , 0)){
            cout << "NO";
            return 0;
        }
    }
    if (addedEdge == n-1) cout << "YES";
    else cout << "NO";
    return 0;
}