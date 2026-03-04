#include <bits/stdc++.h>
using namespace std;
#define filename "llgc2m"
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

ll calctime(vect<pair<ll,ll>>& n){
    ll time_a = 0, time_b = 0;
    for (const pair<ll,ll>& i : n){
        time_a += i.first;
        time_b = max(time_a, time_b) + i.second;
    }
    return time_b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(filename".inp", "r", stdin);
    freopen(filename".out", "w", stdout);
    
    int n; 
    cin >> n;
    
    vect<pair<ll,ll>> group1, group2;
    
    while (n--){
        ll x, y; 
        cin >> x >> y;
        if (x < y){
            group1.pb({x, y});
        }
        else {
            group2.pb({x, y});
        }
    }
    
    sort(group1.begin(), group1.end());
    
    sort(group2.begin(), group2.end(), [](const auto &a , const auto &b){
        return a.second > b.second;
    });
    vect<pair<ll,ll>> optimal_order;
    for (const auto& p : group1) {
        optimal_order.pb(p);
    }
    for (const auto& p : group2) {
        optimal_order.pb(p);
    }
    ll res = calctime(optimal_order);
    
    cout << res;
    
    return 0;
}