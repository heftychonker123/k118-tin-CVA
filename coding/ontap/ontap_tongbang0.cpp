#include <bits/stdc++.h>
using namespace std;
#define filename "Bai2"
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    ll n; 
    cin >> n;
    vector<ll> pref(n+1, 0);
    for (int i = 1; i <= n; i++){
        ll t; cin >> t;
        pref[i] = pref[i-1] + t;
    }

    unordered_map<ll, pair<ll,ll>> freq;
    for (ll i = 0; i <= n; i++){
        if (freq.find(pref[i]) == freq.end()){
            freq[pref[i]] = {i, i};
        } else {
            freq[pref[i]].first = min(freq[pref[i]].first, i);
            freq[pref[i]].second = max(freq[pref[i]].second, i);
        }
    }

    ll res = -1;
    for (const auto &p : freq){
        auto [start, end] = p.second;
        if (start != end){
            res = max(res, end - start);
        }
    }

    if (res == -1) cout << "NO SOLUTION\n";
    else cout << res << "\n";

    return 0;
}
