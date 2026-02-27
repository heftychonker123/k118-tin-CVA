#include <bits/stdc++.h>
using namespace std;
#define filename "timduongdi"
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

vect<pair<ll,ll>> dirs = {{-1,0} , {1,0} , {0,-1} , {0,1}};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen(filename".inp" , "r" , stdin);
    //freopen(filename".out" , "w" , stdout);
    ll m,n ; cin >> m >> n;
    ll x1,x2,y1,y2; cin >> x1 >> x2 >> y1 >> y2;
    x1-- ; x2-- ; y1-- ; y2--;
    vect<vect<ll>> v(m , vect<ll>(n));
    for (int i=0 ; i<m ; i++){
        for (int j=0 ; j<n ; j++){
            cin >> v[i][j];
        }
    }
    vect<vect<ll>> dp(m , vect<ll>(n,llmax));
    dp[x1][x2]=0;
    //Dijikstra's algorithm
    //Min heap
    priority_queue<
        pair<ll,pair<ll,ll>>,
        vect<pair<ll,pair<ll,ll>>>,
        greater<>
    > pq;

    pq.push({0,{x1,x2}});
    dp[x1][x2] = 0;

    while (!pq.empty()){
        auto [currCost, pos] = pq.top(); pq.pop();
        ll currx = pos.first, curry = pos.second;

        if (currCost > dp[currx][curry]) continue;

        for (auto [dx,dy] : dirs){
            ll nxtx = currx + dx, nxty = curry + dy;
            if (0 <= nxtx && nxtx < m && 0 <= nxty && nxty < n){
                ll nextCost = max(currCost, max(dp[currx][curry], v[nxtx][nxty] - v[currx][curry]));
                if (nextCost < dp[nxtx][nxty]){
                    dp[nxtx][nxty] = nextCost;
                    pq.push({nextCost,{nxtx,nxty}});
                }
            }
        }
    }
    cout << dp[y1][y2];
    return 0;
}