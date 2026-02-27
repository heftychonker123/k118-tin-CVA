#include <bits/stdc++.h>
using namespace std;
#define filename "Xauchung3"
#define ll long long
#define str string

void IO(){
    if (fopen(filename".inp", "r")) {
        freopen(filename".inp", "r", stdin);
        freopen(filename".out", "w", stdout);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    IO();
    
    str s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    
    ll n1 = s1.size();
    ll n2 = s2.size();
    ll n3 = s3.size();
    
    ll dp[n1+1][n2+1][n3+1];
    memset(dp, 0, sizeof(dp));
    
    for (ll i = 1; i <= n1; i++) {
        for (ll j = 1; j <= n2; j++) {
            for (ll k = 1; k <= n3; k++) {
                if (s1[i-1] == s2[j-1] && s1[i-1] == s3[k-1]) {
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                } else {
                    dp[i][j][k] = max({dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]});
                }
            }
        }
    }
    
    string lcs = "";
    ll i = n1, j = n2, k = n3;
    
    while (i > 0 && j > 0 && k > 0) {
        if (s1[i-1] == s2[j-1] && s1[i-1] == s3[k-1]) {
            lcs = s1[i-1] + lcs;
            i--; j--; k--;
        } else {
            ll maxVal = max({dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]});
            if (dp[i-1][j][k] == maxVal) {
                i--;
            } else if (dp[i][j-1][k] == maxVal) {
                j--;
            } else {
                k--;
            }
        }
    }
    
    cout << lcs;
    return 0;
}
