#include <bits/stdc++.h>
using namespace std;
#define filename "knapsack2"
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
    ll n,w ; cin >> n >> w;
    vect<ll> weight(n) , price(n);
    for (int i=0 ; i<n ; i++) cin >> weight[i] >> price[i];
    vect<ll> prevdp(w+1 , 0);
    for (int i=1 ; i<=n ; i++){
        vect<ll> currdp(w+1 , 0);
        for (int j=1 ; j<=w ; j++){
            ll exclude = prevdp[j];
            ll includeOnce = LLONG_MIN , includeTwice = LLONG_MIN;
            if (j>=weight[i-1]){
                includeOnce = prevdp[j-weight[i-1]] + price[i-1];
                includeTwice = currdp[j-weight[i-1]] + price[i-1];
            }
            currdp[j] = max({exclude , includeOnce , includeTwice});
        }
        prevdp = currdp;
    }
    cout << prevdp[w] << "\n";
    return 0;
}