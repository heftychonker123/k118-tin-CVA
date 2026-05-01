#include <bits/stdc++.h>
using namespace std;
#define filename "highscore"
#define ll                  long long
#define llmin               LLONG_MIN
#define llmax               LLONG_MAX
#define pb                  push_back
#define vect                vector
#define FOR(i , m , n)      for (int i=m ; i<n ; i++)
#define FOR_r(i , m , n)    for (int i=m ; i>n ; i--)
#define pll pair<ll,ll>
void IO(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen(filename".inp" , "r"))
    {
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    }
}

void dfs_mark(ll node , set<ll>& visited , vect<vect<pll>> &graph){
    for (auto [n , temp] : graph[node]){
        if (!visited.count(n)){
            visited.insert(n);
            dfs_mark(n , visited , graph);
        }
    }
}

void bellman_ford(ll node , ll target , ll n , vect<pair<pll,ll>> &edges , 
                vect<vect<pll>>&transpose , vect<vect<pll>> &graph){
    vect<ll> dist(n+1 , -1e15);
    dist[node] = 0;
    FOR(i , 0 , n-1){
        for (auto [points , weight] : edges){
            ll a = points.first , b = points.second;
            dist[b] = max(dist[b] , dist[a] + weight);
        }
    }

    set<ll> visited1;
    dfs_mark(n , visited1 , transpose);
    set<ll> visited2;
    dfs_mark(1 , visited2 , graph);
    for (auto [points , weight] : edges){
        ll a = points.first , b = points.second;
        if (dist[a] + weight > dist[b] && (visited1.count(b)&&visited2.count(b))){
            cout << -1 << "\n";
            return;
        };
    }
    cout << dist[target] << "\n";
}

int main(){
    IO();
    ll n,m ; cin >> n >> m;
    vect<pair<pll,ll>> edges;
    vect<vect<pll>> transpose(n+1) , graph(n+1);
    FOR(i , 0 , m){
        ll a,b,c ; cin >> a >> b >> c;
        edges.push_back({{a,b} , c});
        transpose[b].push_back({a,c});
        graph[a].push_back({b,c});
    }
    bellman_ford(1 , n , n , edges , transpose , graph);
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