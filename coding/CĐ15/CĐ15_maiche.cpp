#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector
#define str string
#define llmax LLONG_MAX

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, K;
    cin >> n >> m >> K;

    vect<vect<ll>> v(n, vect<ll>(m));
    for (int i = 0; i < n; i++) {
        str p; cin >> p;
        for (int j = 0; j < m; j++) {
            v[i][j] = p[j] - '0';
        }
    }

    vect<pair<ll,ll>> validSize;
    for (int i = 1; i <= K; i++) {
        if (K % i == 0) {
            int j = K / i;
            if (i <= n && j <= m) validSize.push_back({i, j});
            if (j <= n && i <= m) validSize.push_back({j, i});
        }
    }
    if (validSize.empty()){
        cout << "-1\n";
        return 0;
    }

    // prefix sum
    vect<vect<ll>> pref(n+1 , vect<ll>(m+1,0));
    for (int i=1 ; i<=n ; i++){
        for (int j=1 ; j<=m ; j++){
            pref[i][j] = v[i-1][j-1] 
                       + pref[i-1][j] 
                       + pref[i][j-1] 
                       - pref[i-1][j-1];
        }
    }

    ll res = llmax;
    for (const auto &sz : validSize){
        ll length = sz.first , width = sz.second;
        for (int j=0 ; j<=n-length ; j++){
            for (int k=0 ; k<=m-width ; k++){
                ll x1 = j+1, y1 = k+1;
                ll x2 = j+length, y2 = k+width;
                ll temp = pref[x2][y2] 
                        - pref[x1-1][y2] 
                        - pref[x2][y1-1] 
                        + pref[x1-1][y1-1];
                res = min(res,temp);
            }
        }
    }

    if (res == llmax) cout << "-1\n";
    else cout << res << "\n";
    return 0;
}
