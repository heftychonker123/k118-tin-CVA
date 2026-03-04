#include <bits/stdc++.h>
using namespace std;
#define filename "lcs"
#define ll long long
#define str string


ll dp[3001][3001];
str a,b;
void IO(){
    if (fopen(filename".inp" , "r"))
    {
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    IO();
    cin >> a >> b;
    for (int i=1 ; i<=a.size() ; i++){
        for (int j=1 ; j<=b.size()  ; j++){
            dp[i][j] = 0;
            dp[i][j] = max(dp[i][j] , dp[i-1][j]);
            dp[i][j] = max(dp[i][j] , dp[i][j-1]);
            if (a[i-1] == b[j-1]) dp[i][j] = max(dp[i][j] , dp[i-1][j-1] + 1);
        }
    }
    cout << dp[a.size()][b.size()] << "\n";
    return 0;
}