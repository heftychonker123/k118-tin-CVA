#include <bits/stdc++.h>
using namespace std;
#define filename "tamgiacs"
#define ll long long
#define ld long double
#define str string
#define llmin LLONG_MIN
#define llmax LLONG_MAX
#define pb push_back
#define strri string::reverse_iterator
#define stri string::iterator
#define vect vector
#define sstream stringstream
#define umap unordered_map

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
    ll n ; cin >> n;
    vect<ll> prev;
    vect<vect<ll>> trace(n , vect<ll>(n , -1));
    for (int row = 0 ; row<n ; row++){
        vect<ll> dp(row+1);

        for (int j=0 ; j<=row ; j++){
            ll t ; cin >> t;
            if (prev.empty()) dp[j] = t;
            else{
                if (j==0){
                    dp[j] = prev[j] + t;
                    trace[row][j] = j;
                }
                else if (j==row){
                    dp[j] = prev[j-1] + t;
                    trace[row][j] = j-1;
                }
                else {
                    if (prev[j] >= prev[j-1]){
                        dp[j] = prev[j] + t;
                        trace[row][j] = j;
                    }
                    else{
                        dp[j] = prev[j-1] + t;
                        trace[row][j] = j-1;
                    }
                }
            }
        }

        prev = dp;
    }
    ll maxPos = max_element(prev.begin() , prev.end()) - prev.begin();
    cout << prev[maxPos] << "\n" ;
    ll row = n-1;
    vect<pair<ll,ll>> res;
    while (maxPos!=-1){
        res.pb({row+1 , maxPos+1});
        maxPos = trace[row][maxPos];
        row--;
    }
    for (int i = (int)res.size() - 1; i >= 0; i--) {
        cout << res[i].first << ' ' << res[i].second << '\n';
    }
}