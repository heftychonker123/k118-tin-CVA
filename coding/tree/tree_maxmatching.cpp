#include <bits/stdc++.h>
using namespace std;
#define filename "maxmatching"
#define ll                  long long
#define llmin               LLONG_MIN
#define llmax               LLONG_MAX
#define pb                  push_back
#define vect                vector
#define FOR(i , m , n)      for (int i=m ; i<n ; i++)
#define FOR_r(i , m , n)    for (int i=m ; i>n ; i--)
const ll MAXN = 2*1e6;

vect<ll> graph[MAXN];
vect<ll> tree[MAXN];
ll dp[MAXN][2];
void dfs(ll node = 1 , ll parent = 0){
    for (ll i : graph[node]){
        if (i!=parent){
            tree[node].push_back(i);
            dfs(i , node);
        }
    }
}

void dfs_matching(ll node = 1){
    if (tree[node].empty()){
        dp[node][0] = 0; dp[node][1] = 0;
        return;
    }
    ll bestMatch = llmax;
    for (ll i : tree[node]){
        dfs_matching(i);
        bestMatch = min(dp[i][0] - dp[i][1] , bestMatch);
        dp[node][0] += max(dp[i][1] , dp[i][0]);
    }

    for (ll i : tree[node]){
        dp[node][1] = max(dp[node][1] , dp[i][0] + 1 + dp[node][0] - max(dp[i][0] , dp[i][1]));
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
    ll n; cin >> n;
    FOR(i , 1 , n){
        ll a,b ; cin >> a >> b;
        graph[a].pb(b); graph[b].pb(a);
    }
    dfs();
    dfs_matching();
    cout << max(dp[1][1] , dp[1][0]);
    return 0;
}


/* John 3:16
                           |~~~~~~~|
                           |       |
                         |~~~~~~~~~~~| 
                         |  I N R I  |
                         |___________|
                           |       |                             
|~.\\\_\~~~~~~~~~~~~~~xx~~~         ~~~~~~~~~~~~~~~~~~~~~/_//;~|
|  \  o \_         ,XXXXX),                         _..-~ o /  |
|    ~~\  ~-.     XXXXX`)))),                 _.--~~   .-~~~   |
 ~~~~~~~`\   ~\~~~XXX' _/ ';))     |~~~~~~..-~     _.-~ ~~~~~~~ 
          `\   ~~--`_\~\, ;;;\)__.---.~~~      _.-~
            ~-.       `:;;/;; \          _..-~~
               ~-._      `''        /-~-~ 
                   `\              /  /
                     |         ,   | |
                      |  '        /  |
                       \/;          |
                        ;;          |
                        `;   .       |
                        |~~~-----.....|
                       | \             \
                      | /\~~--...__    |
                      (|  `\       __-\|
                      ||    \_   /~    |
                      |)     \~-'      |
                       |      | \      '
                       |      |  \    :
                        \     |  |    |
                         |    )  (    ) 
                          \  /;  /\  |
                          |    |/   |
                          |    |   |
                           \  .'  ||
                           |  |  | |
                           (  | |  |
                           |   \ \ |
                           || o `.)|
                           |`\\\\) |
                           |       |
                           |       |
                           |       |
*/