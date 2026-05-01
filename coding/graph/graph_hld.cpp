#include <bits/stdc++.h>
using namespace std;
#define filename "hld"
#define ll                  long long
#define llmin               LLONG_MIN
#define llmax               LLONG_MAX
#define pb                  push_back
#define vect                vector
#define FOR(i , m , n)      for (int i=m ; i<n ; i++)
#define FOR_r(i , m , n)    for (int i=m ; i>n ; i--)

const ll MAXN = 1000;
ll mat[MAXN][MAXN] , dist[MAXN][MAXN] , trace[MAXN][MAXN];

void floyd(ll n) {
    fill(&dist[0][0], &dist[0][0] + MAXN * MAXN, (ll)1e15);
    fill(&trace[0][0], &trace[0][0] + MAXN * MAXN, -1);

    FOR(i, 0, n) dist[i][i] = 0;
    FOR(i, 0, n) FOR(j, 0, n) if (mat[i][j]!=0) dist[i][j] = mat[i][j];

    FOR(k, 0, n) {
        FOR(i, 0, n) {
            FOR(j, 0, n) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    trace[i][j] = k;
                }
            }
        }
    }
}

vect<ll> traceback(ll r, ll c) {
    if (trace[r][c] == -1) return {r, c};
    ll k = trace[r][c];
    vect<ll> left = traceback(r, k);
    vect<ll> right = traceback(k, c);
    left.pop_back();
    left.insert(left.end(), right.begin(), right.end());
    return left;
}



void solve(ll n){
    ll bestDist = LLONG_MAX, bestCity = -1;
    FOR(i, 0, n){
        ll longest = 0;
        FOR(j, 0, n){
            longest = max(longest, dist[j][i]);
        }
        if (longest < bestDist){
            bestDist = longest;
            bestCity = i+1;
        }
    }
    cout << bestCity << " " << bestDist << "\n";

    FOR(i, 0, n){
        if (i == bestCity-1) continue;
        vect<ll> path = traceback(i, bestCity-1);
        for (ll v : path) cout << v+1 << " ";
        cout << "\n";
    }
}

void IO(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen(filename".inp" , "r"))
    {
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    }
}
int main(){
    IO();
    ll n ; cin >> n;
    memset(mat , 0 ,  sizeof(mat));
    FOR(i , 0 , n) FOR(j , 0 , n) cin >> mat[i][j];
    floyd(n);
    solve(n);
    return 0;
}


/* John 3:16
                    .-=====-.
                    | .""". |
                    | |   | |
                    | |   | |
                    | '---' |
                    |       |
                    |       |
 .-================-'       '-================-.
j|  _                                          |
g|.'o\                                    __   |
s| '-.'.                                .'o.`  |
 '-==='.'.=========-.       .-========.'.-'===-'
        '.`'._    .===,     |     _.-' /
          '._ '-./  ,//\   _| _.-'  _.'
             '-.| ,//'  \-'  `   .-'
                `//'_`--;    ;.-'
                  `\._ ;|    |
                     \`-'  . |
                     |_.-'-._|
                     \  _'_  /
                     |; -:- | 
                     || -.- \ 
                     |;     .\
                     / `'\'`\-;
                    ;`   '. `_/
                    |,`-._;  .;
                    `;\  `.-'-;
                     | \   \  |
                     |  `\  \ |
                     |   )  | |
                     |  /  /` /
                     | |  /|  |
                     | | / | /
                     | / |/ /|
                     | \ / / |
                     |  /o | |
                     |  |_/  |
                     |       |
                     |       |
                     |       |
                     |       |
                     |       |
                     |       |
                     |       |
                     '-=====-'
*/