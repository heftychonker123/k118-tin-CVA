#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vect vector
bool dp[101][(ll)1e5+1];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vect<ll> v; ll x; ll res;


    while (cin >> x) v.pb(x);
    dp[0][0] = true;
    ll sum = accumulate(v.begin() , v.end() , 0);

    for (int i=1 ; i<=v.size() ; i++){
        for (int j=0 ; j<=1e5 ; j++){
            if (dp[i-1][j]) dp[i][j] = true; // Excluding
            else{ // Including
                if (j< v[i-1]) continue;
                else if (dp[i-1][j-v[i-1]]) dp[i][j] = true;
            }
        }
    }
    for (int i=0 ; i<sum ; i++){
        if (dp[v.size()][i]) res = min(res , abs(sum-2*i));
    }
    cout << res << "\n";
    return 0;
}