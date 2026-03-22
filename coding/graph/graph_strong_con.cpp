#include <bits/stdc++.h>
using namespace std;
#define filename "DTCHLT"
#define ll                  long long
#define llmin               LLONG_MIN
#define llmax               LLONG_MAX
#define pb                  push_back
#define vect                vector
#define FOR(i , m , n)      for (int i=m ; i<n ; i++)
#define FOR_r(i , m , n)    for (int i=m ; i>n ; i--)
void IO(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen(filename".inp" , "r"))
    {
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    }
}

void dfs(vect<vect<ll>> &graph , set<ll> &visited , ll n){
    stack<ll> s; s.push(0) ; visited.insert(0);
    while (!s.empty()){
        ll curr = s.top() ; s.pop();
        for (ll i : graph[curr]){
            if (visited.find(i) == visited.end()){
                s.push(i);
                visited.insert(i);
            }
        }
    }
}
int main(){
    IO();
    ll n,m; cin >> n >> m;
    vect<vect<ll>> graph(n) , transpose(n);
    for (int i=0 ; i<m ; i++){
        ll a,b ; cin >> a >> b;
        graph[a-1].push_back(b-1);
        transpose[b-1].push_back(a-1);
    }
    // Kosajaru's algorithm applied to an entire graph
    set<ll> visited , visited_r;
    dfs(graph , visited , n);
    dfs(transpose , visited_r , n);
    if (visited.size() == n && visited_r.size() == n) cout << '1';
    else if (visited.size() == n || visited_r.size() == n) cout << '2';
    else cout << '0';
    return 0;
}