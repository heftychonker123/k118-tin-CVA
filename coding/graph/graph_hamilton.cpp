#include <bits/stdc++.h>
using namespace std;
#define filename "hamilton"
#define ll                  long long
#define llmin               LLONG_MIN
#define llmax               LLONG_MAX
#define pb                  push_back
#define vect                vector
#define FOR(i , m , n)      for (int i=m ; i<n ; i++)
#define FOR_r(i , m , n)    for (int i=m ; i>n ; i--)
const ll MAXN = 1e6 + 5;
ll stop = false;
set<ll> adj[MAXN];
bool visited[MAXN];
ll n,m;

void dfs(ll node, vect<ll>& path, ll start) {
    if (stop) return;
    visited[node] = true;
    path.push_back(node);

    if (path.size() == n) {
        
        if (adj[node].count(start)) {
            stop = true;
            for (ll i : path) cout << i+1 << " ";
            cout << start+1; 
        }
        visited[node] = false;
        path.pop_back();
        return;
    }

    for (ll i : adj[node]) {
        if (!visited[i]) dfs(i, path, start);
    }

    visited[node] = false;
    path.pop_back();
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
    cin >> n >> m;
    FOR(i , 0 , m){
        ll a,b ; cin >> a >> b;
        adj[a-1].insert(b-1);
        adj[b-1].insert(a-1);
    }
    FOR(i, 0, n) {
        vect<ll> path;
        dfs(i, path , i);
        if (stop) break;
    }


    if (!stop) cout << 0;
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