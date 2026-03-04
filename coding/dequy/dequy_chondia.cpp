#include <bits/stdc++.h>
using namespace std;
#define filename "disk"
#define ll long long
#define str string
#define llmin LLONG_MIN
#define llmax LLONG_MAX
#define pb push_back
#define vect vector
#define umap unordered_map
ll best = llmax;
pair<ll,str> minCost(ll n, ll m, const vector<vector<ll>>& disks, 
                     const vector<ll>& cost, ll subCost, 
                     unordered_map<ll,ll>& freq , str sub , ll idx=0) {
    if (subCost >= best){
        return {llmax , sub};
    }
    if (freq.size() == m) {
        best = min(subCost , best);
        return {subCost, sub};
    }
    else if (idx == n){
        return {llmax , sub};
    }
    unordered_set<ll> remaining;
    for (int i = idx; i < n; i++)
        for (ll t : disks[i])
            if (1 <= t && t <= m) remaining.insert(t);

    if (freq.size() + remaining.size() < m) {
        return {llmax, sub}; 
    }

    for (ll i : disks[idx]) {
        if (1 <= i && i <= m) freq[i]++;   
    }
    sub[idx] = '1';
    auto include = minCost(n, m, disks, cost, subCost + cost[idx], freq, sub , idx+1);

    for (ll i : disks[idx]) {
        if (1 <= i && i <= m && --freq[i] == 0) freq.erase(i);
    }
    sub[idx] = '0';
    auto exclude = minCost(n, m, disks, cost, subCost, freq, sub , idx+1);

    if (include.first < exclude.first) return include;
    else if (include.first > exclude.first) return exclude;
    else {
        if (include.second > exclude.second) return include;
        else return exclude;
    }
}

void solve(){
    ll n,m ; cin >> n >> m;
    vect<ll> costs(n);
    vect<vect<ll>> disks(n);

    for (ll i=0 ; i<n ; i++){
        ll cost ; cin >> cost;
        costs[i] = cost;
        ll number; cin >> number;
        for (ll j=0 ; j<number ; j++){
            ll t ; cin >> t;
            disks[i].pb(t);
        }
    }

    umap<ll,ll> freq;
    str sub="";
    for (int i=0; i<n ; i++) sub+="0";
    pair<ll,str> res = minCost(n , m , disks , costs , 0 , freq , sub);

    if (res.first == llmax) cout << -1 << "\n";
    else {
        cout << res.first << "\n";
        for (int i=0 ; i<res.second.size() ; i++){
            if (res.second[i] == '1'){
                cout << i+1 << " ";
            }
        }
    }
}

void IO(){
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    IO();
    solve();
    return 0;
}
