#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector
vect<ll> graph[26]; ll visited[26]; bool SORT = true;
vect<ll> topo;
void dfs(ll node){
    visited[node] = 1;
    for (int i : graph[node]){
        if (visited[i] == 1) SORT = false;
        else if (visited[i] == 0) dfs(i);
    }
    visited[node] = 2;
    topo.push_back(node);
}

void toposort(ll n = 26){
    for (int i = 0 ; i<26 ; i++){
        if (visited[i] == 0) dfs(i);
    }
}
// Assuming string a is smaller than string b
void order(string a , string b){
    for (int i = 0 ; i < min(a.size(),b.size()) ; i++){
        if (a[i] != b[i]){
            // => b[i] > a[i];
            graph[b[i] - 'a'].push_back(a[i]-'a');
            return;
        }
    }
    if (a.size() > b.size()) SORT = false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n ; cin >> n;
    vect<string> v(n); for (int i = 0 ; i<n ; i++) cin >> v[i];
    for (int i = 0 ; i<n ; i++){
        for (int j = 0 ; j<i ; j++) order(v[j] , v[i]);
    }
    toposort();
    if (!SORT) cout << "Impossible";
    else for (ll i : topo) cout << (char)('a' + i);
}