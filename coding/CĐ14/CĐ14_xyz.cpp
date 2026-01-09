#include <bits/stdc++.h>
using namespace std;
#define filename "zxy"
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

bool check(vect<ll> n, ll size , ll k){
    ll temp = 0;
    ll count = 1;
    for (const ll &i : n){
        if (temp + i <= size){
            temp += i;
        } else {
            count++;
            temp = i;
        }
    }
    return count <= k;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    ll n, k; cin >> n >> k;
    vect<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    ll left = *max_element(v.begin(), v.end());
    ll right = accumulate(v.begin(), v.end(), 0LL);
    ll res = right;

    while (left <= right){
        ll mid = (left + right) / 2;
        if (check(v, mid, k)){
            res = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << res << "\n";
    return 0;
}
