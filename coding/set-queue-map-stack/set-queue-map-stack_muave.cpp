#include <bits/stdc++.h>
using namespace std;
#define filename "muave"
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
int main(){
    //freopen(filename".inp" , "r" , stdin);
    //freopen(filename".out" , "w" , stdout);
    ll n,m,k; cin >> n >> m >> k;
    queue<pair<ll,ll>> q;
    for (int i=0 ; i<n ; i++){
        ll t ; cin >> t;
        q.push({t,i});
    }
    vect<ll> visited(n);
    while (k--){
        if (q.empty()) continue;
        pair<ll,ll> enter = q.front();
        if (enter.first<=m){
            q.pop();
        }
        else{
            q.pop();
            q.push(enter);
        }
        visited[enter.second]++;
    }
    for (const ll &i : visited) cout << i << " ";
    return 0;
}