#include <bits/stdc++.h>
using namespace std;
#define filename "restore"
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
bool bfs(ll n , ll k,
    vect<vect<ll>> &neighbor , vect<pair<ll,ll>> &ans , 
    map<ll,vect<ll>> dist , vect<ll> d){
    for (int i=0 ; i<n ; i++){
        vect<ll> nxt = dist[d[i] - 1];
        if (nxt.empty()) return false;
        else{
            ll minDeg = llmax;
            ll select;
            for (const ll &i : nxt){
                if (neighbor[i].size() < minDeg){
                    select = i;
                    minDeg = neighbor[i].size();
                }
            }
            if (minDeg > k) return false;
            else{
                neighbor[select].pb(i);
                ans.pb({select,i});
            }
        }
    }
    return true;
}

void solve(){
    ll n,k ; cin >> n >> k;
    map<ll,vect<ll>> dist;
    vect<ll> d(n);
    for (int i=0 ; i<n ; i++){
        ll t ; cin >> t;
        d[i] = t;
        dist[t].pb(i);
    }
    vect<vect<ll>> neighbor(n);
    vect<pair<ll,ll>> ans;
    if (!bfs(n , k , neighbor , ans, dist , d)) cout << -1;
    else{
        for (const auto [a,b] : ans){
            cout << a+1 << " " << b+1 << "\n";
        }
    } 
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}