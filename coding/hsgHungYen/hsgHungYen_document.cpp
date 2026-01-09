#include <bits/stdc++.h>
using namespace std;
#define filename "document"
#define ll long long
#define ld long double
#define str string
#define llmin LLONG_MIN
#define llmax LLONG_MAX
#define pb push_back
#define strri string::reverse_iterator
#define stri string::iterator
#define vect vector
#define sstream stringstream
#define umap unordered_map
void solve(){
    ll n,k,m ; cin >> n >> k >> m;
    unordered_set<ll> s;
    for (int i=0 ; i<k ; i++){
        ll t ; cin >> t; s.insert(t);
    };
    vect<vect<ll>> graph(n);
    vect<vect<ll>> ancestor_graph(n);
    vect<bool> visited(n);
    vect<ll> weight(n);
    for (int i=0 ; i<n ; i++){
        cin >> weight[i];
    }
    //Graph: ancestor graph
    for (int i=0 ; i<m ; i++){
        ll vi,ui ; cin >> vi >> ui;
        ancestor_graph[vi-1].pb(ui-1);
        graph[ui-1].pb(vi-1);
    }
    // Để hiệu quả nhất, ta sẽ chỉ phá một cửa mỗi connected component
    // để đi tới các phần tử 
    for (int i=0 ; i<n ; i++){
        if (!visited[i]){
            // Tìm ancestor xa nhất của i
            vect<bool> ancestor_visited(n,false);
            ll ancestor = 0;
            queue<ll> q;
            q.push(i);
            ll docs=0;
            while (!q.empty()){}
        }
    }
    ll res = 0;
}
void IO(){
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //IO();
    solve();
    return 0;
}