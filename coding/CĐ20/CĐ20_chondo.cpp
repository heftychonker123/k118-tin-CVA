#include <bits/stdc++.h>
using namespace std;
#define filename "chondo"
#define ll long long
#define pb push_back
#define vect vector

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
    vect<ll> price(n) , weight(n);
    for (int i = 0 ; i<n ; i++) cin >> weight[i] >> price[i];
    vect<ll> prevDP(w+1 , 0);
    vect<vect<ll>> trace(n+1, vect<ll>(w+1 , false));
    for (int i=1 ; i<=n ; i++){
        vect<ll> currDP(w+1 , 0);
        for (int j=1 ; j<=w ; j++){
            ll exclude = prevDP[j];
            ll include = LLONG_MIN;
            if (j>=weight[i-1]){
                include = prevDP[j-weight[i-1]] + price[i-1];
            }
            if (include > exclude){
                currDP[j] = include;
                trace[i][j] = j - weight[i-1];
            }
            else{
                currDP[j] = exclude;
                trace[i][j] = j;
            }
        }
        for (const ll &i : prevDP) cout << i << " ";
        cout << "\n";
        prevDP = currDP;
    }
    for (const ll &i : prevDP) cout << i << " ";
    cout << "\n";
    cout << "\n";
}