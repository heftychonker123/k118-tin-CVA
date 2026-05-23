#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("sdb.INP","r",stdin);
    freopen("sdb.OUT","w",stdout);

    int n; cin >> n;
    vector<ll> a(n);
    unordered_map<ll,int> freq;
    freq.reserve(n*2);
    freq.max_load_factor(0.7);

    for(int i=0;i<n;i++){
        cin >> a[i];
        freq[a[i]]++;
    }

    vector<ll> res;
    res.reserve(n);
    for(ll x : a){
        if(freq[x]==1) res.push_back(x);
    }

    cout << res.size() << '\n';
    for(ll x : res) cout << x << '\n';
}
