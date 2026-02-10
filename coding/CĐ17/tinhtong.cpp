#include <bits/stdc++.h>
using namespace std;
#define filename "dequy_tinhtong"
#define ld long double
#define ll long long
ll sum(ll n){
    if (n==1) return -1;
    else{
        if (n%2==0) return n + sum(n-1);
        else return -n + sum(n-1);
    }
}

void solve() {
    ll n; 
    cin >> n;
    cout << sum(n);
}

void IO() {
    freopen(filename ".inp", "r", stdin);
    freopen(filename ".out", "w", stdout);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //IO();
    solve();
    return 0;
}
