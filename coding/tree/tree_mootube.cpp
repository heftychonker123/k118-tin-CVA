#include <bits/stdc++.h>
using namespace std;
#define filename "mootube"
#define ll long long
#define pb push_back
#define vect vector

void dfs(ll root , ll k , vect<vect<pair<ll,ll>>> &rev , vect<bool> &visited){
    visited[root] = true;
    for (auto [video , r] : rev[root]){
        if (!visited[video] && r >= k){   // condition fixed
            dfs(video , k , rev , visited);
        }
    }
}

void solve(){
    ll n,q ; cin >> n >> q;
    vect<vect<pair<ll,ll>>> rev(n);
    for (int i=0 ; i<n-1 ; i++){
        ll a,b,r ; cin >> a >> b >> r;
        rev[a-1].pb({b-1,r});
        rev[b-1].pb({a-1,r});
    }
    while (q--){
        ll k , root ; cin >> k >> root;
        vect<bool> visited(n,false);
        dfs(root-1 , k , rev , visited);
        ll cnt=0;
        for (int i=0 ; i<n ; i++){
            if (visited[i] && i != root-1) cnt++;  
        }
        cout << cnt << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
