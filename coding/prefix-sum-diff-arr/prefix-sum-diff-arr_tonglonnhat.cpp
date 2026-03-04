#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,q; cin >> n >> q;
    vect<ll> v(n);
    for (int i=0 ; i<n ; i++) cin >> v[i];
    sort(v.begin(), v.end()); // sort tăng dần

    vect<ll> op(n+2,0);
    while (q--){
        ll x,y; cin >> x >> y;
        op[x]++;
        op[y+1]--;
    }
    for (int i=1; i<=n; i++) op[i] += op[i-1];

    // sort tần suất từ 1..n
    sort(op.begin()+1, op.begin()+n+1);

    ll res=0;
    for (int i=1; i<=n; i++){
        res += op[i] * v[i-1];
    }
    cout << res << "\n";
    return 0;
}
