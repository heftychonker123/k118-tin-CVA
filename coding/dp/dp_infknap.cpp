#include <bits/stdc++.h>
using namespace std;
#define filename "infknap"
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
    ll n,v ; cin >> n >> v;
    vect<ll> weight(n) , price(n);
    for (int i=0 ; i<n ; i++) cin >> weight[i] >> price[i];
    vect<ll> dp(v+1) , choice(v+1 , -1);
    for (int i=0 ; i<n ; i++){
        for (int j = weight[i] ; j<=v ; j++){
            if (dp[j-weight[i]] + price[i]> dp[j]){
                choice[j] = i;
                dp[j] = dp[j-weight[i]] + price[i];
            }
        }
    }
    int col = max_element(dp.begin() , dp.end()) - dp.begin();
    cout << dp[col] << "\n";
    vect<ll> count(n);
    while (col > 0){
        int i = choice[col];
        if (i==-1) break;
        count[i]++;
        col -= weight[i];
    }
    for (const ll &i : count) cout << i << "\n";
}