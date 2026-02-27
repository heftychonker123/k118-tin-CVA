#include <bits/stdc++.h>
using namespace std;
#define filename "quatet"
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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n ; cin >> n;
    ll a[n][3] ;
    for (int i=0 ; i<n ; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
    ll dp[n+1][3];
    for (int i=0 ; i<=n ; i++){
        for (int j=0 ; j<=2 ; j++) dp[i][j] = 0;
    }
    for (int i=1 ; i<=n ; i++){
        for (int j=0 ; j<3 ; j++){
            for (int k=0 ; k<3 ; k++){
                if (k==j) continue;
                else dp[i][j] = max(dp[i][j] , dp[i-1][k]);
            }
            dp[i][j] += a[i-1][j];
        }
    }
    cout << *max_element(dp[n] , dp[n]+3);
    return 0;
}