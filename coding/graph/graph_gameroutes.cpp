#include <bits/stdc++.h>
using namespace std;
#define filename "gameroutes"
#define ll                  long long
#define llmin               LLONG_MIN
#define llmax               LLONG_MAX
#define pb                  push_back
#define vect                vector
#define FOR(i , m , n)      for (int i=m ; i<n ; i++)
#define FOR_r(i , m , n)    for (int i=m ; i>n ; i--)

const ll MAXN = 1e5 + 5 , MODULO = 1e9 + 7;
bool visited[MAXN];
vect<ll> graph[MAXN];
vect<ll> topo;

void toposort(ll node){
    visited[node] = true;
    for (ll i : graph[node]){
        if (!visited[i]) toposort(i);
    }
    topo.push_back(node);
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
    ll n,m ; cin >> n >> m;
    FOR(i , 0 , m){
        ll a,b ; cin >> a >> b;
        graph[a].pb(b);
    }
    toposort(1);

    vect<ll> dp(n+1 , 0);
    dp[1] = 1;
    reverse(topo.begin() , topo.end());
    for (int i : topo){
        if (dp[i] == 0) continue;
        else{
            for (int j : graph[i]){
                dp[j] += dp[i]%MODULO;
                dp[j]%=MODULO;
            }
        }
    }
    cout << dp[n]%MODULO << "\n";
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