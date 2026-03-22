#include <bits/stdc++.h>
using namespace std;
#define filename            "TABLE"
#define ll                  long long
#define llmin               LLONG_MIN
#define llmax               LLONG_MAX
#define pb                  push_back
#define vect                vector
#define FOR(i , m , n)      for (int i=m ; i<n ; i++)
#define FOR_r(i , m , n)    for (int i=m ; i>n ; i--)
const ll MAXN =             1000;
const ll MAXM =             1000;


ll m,n ; 
ll v[MAXN][MAXM];
ll pref[MAXN+1][MAXM+1];


void IO(){
    if (fopen(filename".inp" , "r"))
    {
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    }
}

bool check(ll k){
    FOR(i, 0, m - k + 1) {
        FOR(j, 0, n - k + 1) {
            ll sum = pref[i+k][j+k] - pref[i][j+k] - pref[i+k][j] + pref[i][j];
            if (sum == k * k) return true;
        }
    }
    return false;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    IO();
    cin >> m >> n;
    FOR(i , 0 , m) FOR(j , 0 , n) cin >> v[i][j];
    FOR(i , 1 , m+1) FOR(j , 1 , n+1) 
        pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + v[i-1][j-1];
    ll res = 0;
    ll l=1 , r = min(m,n);
    while (l <= r){
        ll mid = l + (r-l)/2;
        if (check(mid)){
            res = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    cout << res << "\n";
    return 0;
}