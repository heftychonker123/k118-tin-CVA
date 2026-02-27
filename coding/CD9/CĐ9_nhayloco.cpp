#include <bits/stdc++.h>
using namespace std;
#define filename "nhayloco"
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
vect<pair<ll,ll>> findpair(vect<ll> &v , ll target){
    vect<pair<ll,ll>> res;
    for (int i = 0; i < v.size(); i++) {
        auto it = lower_bound(v.begin() + i + 1, v.end(), target - v[i]);
        if (it != v.end() && v[i] + *it == target) {
            res.pb({i, it-v.begin()});
        }
    }
    return res;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n ; cin >> n;
    vect<ll> v(n); for (int i=0 ; i<n ; i++) cin >> v[i];
    // Thứ tự xử lý từng node là từ bé -> lớn
    //(vì phần tử bé nhất trong các connected components sẽ chỉ có các outgoing edges)
    sort(v.begin() , v.end());
    vect<ll> dp(n , 0);
    for (int i=0 ; i<n ; i++){
        vect<pair<ll,ll>> twoSum = findpair(v, v[i]);
        if (twoSum.empty()) dp[i] = 1;
        else{
            for (const auto [idx1 , idx2] : twoSum){
                dp[i] = max({dp[i] , dp[idx1] + 1 , dp[idx2] + 1});
            }
        }
    }
    cout << *max_element(dp.begin() , dp.end()) << "\n";
    return 0;
}