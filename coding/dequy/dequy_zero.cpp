#include <bits/stdc++.h>
using namespace std;
#define filename "zero"
#define ll long long

bool visited[100001];
void recur(ll n){
    if (n==0|| visited[n]) return;
    visited[n] = true;
    for (int i=1 ; i*i<=n ; i++){
        if (n%i == 0){
            ll t = n+i-n/i-1;
            recur(t);
        }
    }
}

void solve(){
    ll n; 
    cin >> n;
    recur(n);
    vector<ll> res;
    for (int i=0 ; i<n ; i++){
        if (visited[i]) res.push_back(i);
    }
    cout << res.size()+1 << "\n";
    cout << "0 ";
    for (const ll &i : res) cout << i << " ";
    cout << "\n";
}

void IO(){
    freopen(filename".inp", "r", stdin);
    freopen(filename".out", "w", stdout);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //IO();
    solve();
    return 0;
}