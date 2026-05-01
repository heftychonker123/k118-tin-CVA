#include <bits/stdc++.h>
using namespace std;
#define filename "euler"
#define ll                  long long
#define llmin               LLONG_MIN
#define llmax               LLONG_MAX
#define pb                  push_back
#define vect                vector
#define FOR(i , m , n)      for (int i=m ; i<n ; i++)
#define FOR_r(i , m , n)    for (int i=m ; i>n ; i--)

const ll MAXN = 1e6 + 5;
set<ll> adj[MAXN];
vect<ll> Hierholzer(ll node = 0){
    vect<ll> currPath , path;
    currPath.pb(node);
    while (!currPath.empty()){
        ll curr = currPath.back();
        if (!adj[curr].empty()){
            ll u = *(adj[curr].begin());
            adj[curr].erase(u);
            auto it = find(adj[u].begin(), adj[u].end(), curr);
            if (it != adj[u].end()) adj[u].erase(it);
            currPath.push_back(u);
        }
        else{
            path.pb(currPath.back());
            currPath.pop_back();
        }
    }
    return path;
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
        adj[a-1].insert(b-1);
        adj[b-1].insert(a-1);
    }
    vect<ll> path = Hierholzer();
    if (path.size() < m+1) cout << 0;
    else{
        reverse(path.begin() , path.end());
        for (ll i : path) cout << i+1 << " ";
    }
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