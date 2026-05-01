#include <bits/stdc++.h>
using namespace std;
#define filename "tduongdi"
#define ll                  long long
#define llmin               LLONG_MIN
#define llmax               LLONG_MAX
#define pb                  push_back
#define vect                vector
#define FOR(i , m , n)      for (int i=m ; i<n ; i++)
#define FOR_r(i , m , n)    for (int i=m ; i>n ; i--)
const ll MAXN = 1e6 + 5;
set<ll> adj[MAXN];
bool visited[MAXN];


vect<pair<ll,ll>> addEdges(ll nodes) {
    vect<pair<ll,ll>> addedEdges;
    vect<ll> oddVertices;

    FOR(i, 0, nodes) {
        if (adj[i].size() % 2 == 1) {
            oddVertices.pb(i);
        }
    }

    for (ll i = 0; i < oddVertices.size()/2; i++) {
        ll u = oddVertices[i];
        ll v = oddVertices[oddVertices.size()-i-1];
        adj[u].insert(v);
        adj[v].insert(u);
        addedEdges.pb({u, v});
    }

    return addedEdges;
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
    fill(&visited[0] , &visited[MAXN] , false);
    ll n,m ; cin >> n >> m;
    FOR(i , 0 , m){
        ll a,b ; cin >> a >> b;
        adj[a-1].insert(b-1);
        adj[b-1].insert(a-1);
    }

    vect<pair<ll,ll>> addedEdges = addEdges(n);
    if (addedEdges.empty()) cout << 0;
    else{
        cout << addedEdges.size() << "\n";
        for (auto& [x,y] : addedEdges) cout << x+1 << " " << y+1 << "\n";
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