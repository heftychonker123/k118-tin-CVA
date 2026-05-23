#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Persistent DSU: lưu cha và size theo thời gian
struct PerDSU {
    vector<vector<pair<ll,ll>>> dsu, s; // (time, value)

    PerDSU(ll n) {
        dsu.resize(n+1);
        s.resize(n+1);
        for (int i=1; i<=n; i++) {
            dsu[i].push_back({0,i});   // cha ban đầu
            s[i].push_back({0,1});     // size ban đầu
        }
    }

    ll find(ll node, ll timer) {
        auto it = upper_bound(dsu[node].begin(), dsu[node].end(), make_pair(timer,LLONG_MAX));
        ll idx = it - dsu[node].begin();
        if (idx > 0) idx--;
        while (node != dsu[node][idx].second) {
            node = dsu[node][idx].second;
            it = upper_bound(dsu[node].begin(), dsu[node].end(), make_pair(timer,LLONG_MAX));
            idx = it - dsu[node].begin();
            if (idx > 0) idx--;
        }
        return node;
    }

    void merge(ll a, ll b, ll timer) {
        a = find(a,timer);
        b = find(b,timer);
        if (a==b) return;
        if (s[a].back().second < s[b].back().second) swap(a,b);
        s[a].push_back({timer+1, s[a].back().second + s[b].back().second});
        dsu[b].push_back({timer+1, a});
    }
};

// Ví dụ: New Road Queries
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m,q; cin >> n >> m >> q;
    PerDSU t(n);

    for (int i=0; i<m; i++) {
        ll a,b; cin >> a >> b;
        t.merge(a,b,i);
    }

    while (q--) {
        ll a,b; cin >> a >> b;
        ll res = -1;
        ll l = 0, r = m;
        while (l<=r) {
            ll mid = (l+r)/2;
            if (t.find(a,mid) == t.find(b,mid)) {
                res = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        cout << res << "\n";
    }
    return 0;
}
