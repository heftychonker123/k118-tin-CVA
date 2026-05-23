#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll MAXN = 2e5 + 5;

bool added[MAXN];
vector<bool> res;
vector<ll> graph[MAXN];
ll currcomps = 0;


// DSU data structures
ll dsu[MAXN] , s[MAXN];
ll find(ll node){
    if (node!=dsu[node]) return dsu[node] = find(dsu[node]);
    else return node;
}
void merge(ll a , ll b){
    a = find(a); b = find(b);
    if (s[a] < s[b]) swap(a,b);
    dsu[b] = a;
    s[a] += s[b];
}

void solve(vector<ll>& order){
    for (ll &i : order){
        added[i] = true;// Add node i to the graph
        currcomps ++; // When we add node i, we add another components
        for (ll t : graph[i]){
            if (added[t]){ // Check if this node has been added
                if (find(t) != find(i)){ // Check if they are in the same component
                    merge(t , i);// If not, merge and reduce the number of components
                    currcomps--;
                }
            }
        }
        res.push_back(currcomps == 1);
    }
}
int main(){
    fill(&added[0] , &added[0] + MAXN , false);
    ll n,m ; cin >> n >> m;
    for(int i = 1 ; i<=n ; i++){
        dsu[i] = i ; s[i] = 1;
    }
    for(int i = 0;i<m;i++){
        ll a,b ; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<ll> order(n);
    for (int i = 0 ; i<n ; i++) cin >> order[n-i-1];
    solve(order);
    for (int i = n-1 ; i>=0 ; i--) cout << (res[i]? "YES" : "NO") << "\n";
}