#include <bits/stdc++.h>
using namespace std;
#define ll long long 

const int MAXN = 2e5 + 1; 
int n; pair<int,int> dolls[MAXN];

const int MAXQ = 2e5 + 1;
int q; pair<pair<int,int> , int> queries[MAXQ]; int ans[MAXQ];

#define fi first 
#define se second 

void solve(){
    sort(dolls + 1 , dolls + n + 1 , [](auto &a , auto &b){if (a.fi != b.fi) return a.fi > b.fi; else return a.se < b.se;});
    sort(queries + 1 , queries + q + 1 , [](auto &a , auto &b){if (a.fi != b.fi) return a.fi > b.fi; else return a.se < b.se;});

    vector<pair<int,int>> dp;

    int curr = 1;
    for (int i = 1 ; i <= q ; i++){
        auto query = queries[i];
        while (curr <= n && dolls[curr].first >= query.fi.fi){
            auto pos = upper_bound(dp.begin() , dp.end() , (pair<int,int>){dolls[curr].se , INT_MAX});
            if (pos == dp.end()) dp.push_back({dolls[curr].se , dolls[curr].fi});
            else *pos = {dolls[curr].se , dolls[curr].fi};

            curr++;
        }
        ans[query.se] = upper_bound(dp.begin() , dp.end() , (pair<int,int>){query.fi.se , INT_MAX}) - dp.begin();
    }

    for (int i = 1 ; i<=q ; i++) cout << ans[i] << '\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1 ; i<=n ; i++) cin >> dolls[i].fi >> dolls[i].se;

    cin >> q;
    for (int i = 1 ; i<=q ; i++){
        cin >> queries[i].fi.fi >> queries[i].fi.se;
        queries[i].se = i;
    }

    solve();
}