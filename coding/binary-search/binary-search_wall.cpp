#include <bits/stdc++.h>
using namespace std;
#define filename "wall"
#define ll long long
#define vect vector
bool check(ll val , vect<ll> a , vect<ll> b){
    ll i = 0 , j = 0;
    while (i < a.size() && j < b.size()){
        if (a[i] >= val){
            i++;
        } else {
            while (j < b.size() && a[i] + b[j] < val) j++;
            if (j >= b.size()) return false;
            i++; j++;
        }
    }
    return (i >= a.size());
}

void trace(ll val , vect<ll> a , vect<ll> b){
    vect<pair<ll,ll>> uv;
    ll i = 0 , j = 0;
    while (i < a.size() && j < b.size()){
        if (a[i] >= val){
            i++;
        } else {
            while (j < b.size() && a[i] + b[j] < val) j++;
            if (j >= b.size()) break;
            i++; j++;
            uv.push_back({i,j});
        }
    }
    cout << val << " " << uv.size() << "\n";
    for (const auto [u,v] : uv) cout << u << " " << v << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n ; cin >> n; vect<ll> a(n); for (int i=0 ; i<n ; i++) cin >> a[i];
    ll m ; cin >> m; vect<ll> b(m); for (int i=0 ; i<m ; i++) cin >> b[i];
    ll left = *min_element(a.begin() , a.end());
    ll right = *max_element(a.begin() , a.end()) + *max_element(b.begin() , b.end());
    ll res = 0;
    while (left<right){
        ll mid = left + (right-left)/2;
        if (check(mid , a , b)){
            res = mid;
            left = mid+1;
        }
        else right = mid;
    }
    trace(res,a,b);
    return 0;
}