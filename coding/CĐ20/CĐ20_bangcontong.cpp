#include <bits/stdc++.h>
using namespace std;
#define filename "bangcontong"
#define ll long long

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


    ll n,m ; cin >> n >> m; ll res = LLONG_MIN;
    vector<vector<ll>> table(n , vector<ll>(m));
    vector<vector<ll>> prefix(n+1 , vector<ll>(m));

    
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++) cin >> table[i][j];
    }
    for (int j=0 ; j<m ; j++){
        for (int i = 1 ; i <= n ; i ++){
            prefix[i][j] = prefix[i-1][j] + table[i-1][j];
        }
    }


    for (int t = 1 ; t<=n ; t++){
        for (int d = t ; d <= n ; d++){
            ll tempSum=0 , bestSum = LLONG_MIN;

            for (int c = 0 ; c < m ; c++){
                ll curr = prefix[d][c] - prefix[t-1][c];
                if (tempSum < 0) tempSum = curr;
                else tempSum += curr;
                bestSum = max(bestSum , tempSum);
            }

            res = max(bestSum , res);
        }
    }

    cout << res << "\n";
    return 0;
}