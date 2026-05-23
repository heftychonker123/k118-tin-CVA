#include <bits/stdc++.h>
using namespace std;
#define filename "scc"
#define ll                  long long
#define llmin               LLONG_MIN
#define llmax               LLONG_MAX
#define pb                  push_back
#define vect                vector
#define FOR(i , m , n)      for (int i=m ; i<n ; i++)
#define FOR_r(i , m , n)    for (int i=m ; i>n ; i--)
const ll MAXN = 1e5 + 5;
vect<ll> graph[MAXN] , transpose[MAXN];
ll visited[MAXN];
vect<ll> order;

void dfs(ll node){
    visited[node] = true;
    for (ll i : graph[node]){
        if (!visited[i]) dfs(i);
    }
    order.pb(node);
}

void dfs_reverse(ll node , vect<ll>& scc , ll leader){
    scc[node] = leader;
    visited[node] = true;
    for (ll i : transpose[node]){
        if (!visited[i]) dfs_reverse(i,scc,leader);
    }
}

void Kosaraju(ll n){
    vect<ll> scc(n+1 , -1);
    FOR(i , 1 , n+1){
        if (!visited[i]) dfs(i);
    }
    fill(&visited[0] , &visited[MAXN] , false);
    reverse(order.begin() , order.end());
    ll cnt = 0;
    for (int i : order){
        if (!visited[i]){
            dfs_reverse(i , scc , ++cnt);
        }
    }
    cout << cnt << "\n";
    FOR(i , 1 , n+1) cout << scc[i] << " ";
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
        transpose[b].pb(a);
    }
    Kosaraju(n);
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