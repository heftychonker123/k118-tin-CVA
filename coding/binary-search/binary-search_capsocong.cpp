#include <bits/stdc++.h>
using namespace std;
#define filename "capsocong"
#define ll long long
#define vect vector


void IO(){
    if (fopen(filename".inp" , "r"))
    {
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    }
}


bool comp(const vector<ll>& a, const vector<ll>& b) {
    if (a[0] != b[0]) return a[0] < b[0];
    if (a[1] != b[1]) return a[1] < b[1];
    return a[2] < b[2];
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    IO();
    ll n ; cin >> n;
    vect<ll> v(n); for (int i=0 ; i<n ; i++) cin >> v[i];
    sort(v.begin() , v.end());
    vect<vect<ll>> validProgression;
    for (int i=0 ; i<n ; i++){
        for (int j=i+1 ; j<n ; j++){
            ll delta = v[j] - v[i];
            if (delta > 0){
                ll k = lower_bound(v.begin() + j + 1 , v.end() , v[j] + delta) - v.begin();
                if (k!=n+1 && (v[k] - v[j]) == delta){
                    validProgression.push_back({v[i] , v[j] , v[k]});
                }
            }
        }
    }
    if (validProgression.size() == 0) cout << "0 0 0";
    else{
        vect<ll> res = *min_element(validProgression.begin() , validProgression.end() , comp);
        for (const ll &i : res) cout << i << " ";
    }
    return 0;
}