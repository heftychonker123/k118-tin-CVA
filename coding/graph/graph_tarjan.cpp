#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector

const ll MAXN = 1e5 + 5;

ll num[MAXN],low[MAXN],timer = 0;
vect<ll> graph[MAXN];

void tarjan(ll node , ll p){
    num[node] = low[node] = ++timer;
    for (ll i : graph[node]){
        if (i == p) return;
        if (num[i] == -1){
            tarjan(i , node);
            low[node] = min(low[node] , low[i]);
        }
        else low[node] = min(low[node] , num[i]);
    }
}

int main(){
    fill(&num[0] , &num[0] + MAXN , -1);
    ll n ; cin >> n;
    ll m ; cin >> m;
    for (int i = 0 ; i<m ; i++){
        ll a,b ; cin >> a >> b;
        graph[a].push_back(b);
    }
    tarjan(1,0);
    for (int i = 1 ; i<=n ; i++){
        if (low[n] == num[n]) cout << i << "\n";
    }
}