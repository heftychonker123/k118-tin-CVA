#include <bits/stdc++.h>
using namespace std;
#define filename "concomp2"
#define ll                  long long
#define llmin               LLONG_MIN
#define llmax               LLONG_MAX
#define pb                  push_back
#define vect                vector
#define FOR(i , m , n)      for (int i=m ; i<n ; i++)
#define FOR_r(i , m , n)    for (int i=m ; i>n ; i--)
void IO(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen(filename".inp" , "r"))
    {
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    }
}
ll find(ll x, vect<ll>& dsu) {
    if (dsu[x] != x) dsu[x] = find(dsu[x], dsu);
    return dsu[x];
}

int main() {
    IO();
    ll n, m; cin >> n >> m;
    vect<ll> dsu(n), size(n, 1);
    for (int i = 0; i < n; i++) dsu[i] = i;

    FOR(i, 0, m) {
        ll a, b; cin >> a >> b; a--; b--;
        a = find(a, dsu);
        b = find(b, dsu);
        if (a == b) continue;
        if (size[a] < size[b]) swap(a, b);
        size[a] += size[b];
        dsu[b] = a;
    }

    set<ll> s;
    FOR(i, 0, n) s.insert(find(i, dsu));
    cout << s.size();
    return 0;
}
