#include <bits/stdc++.h>
using namespace std;
#define filename "khaosat"
#define ll                  long long
#define llmin               LLONG_MIN
#define llmax               LLONG_MAX
#define pb                  push_back
#define vect                vector
#define FOR(i , m , n)      for (int i=m ; i<n ; i++)
#define FOR_r(i , m , n)    for (int i=m ; i>n ; i--)
using pll = pair<ll,ll>;

void IO(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen(filename".inp" , "r"))
    {
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    }
}

ll bfs(pll root , pll target , map<pll,vect<pll>> &graph){
    queue<pair<pll,ll>> q; set<pll> visited;
    q.push({root , 0}); visited.insert(root);
    while (!q.empty()){
        auto [curr,weight] = q.front() ; q.pop();
        if (curr == target) return weight;
        for (pll n : graph[curr]){
            if (!visited.count(n)){
                visited.insert(n);
                q.push({n , weight + 1});
            }
        }
    }
    return -1;
}
int main(){
    IO();
    string s ; cin >> s;
    map<pll,vect<pll>> graph;
    ll currx=0 , curry = 0;
    for (char i : s){
        ll nxtx = currx , nxty = curry;
        if (i == 'N') nxtx -- ;
        if (i == 'S') nxtx ++ ;
        if (i == 'E') nxty ++ ;
        if (i == 'W') nxty -- ;
        graph[{nxtx,nxty}].pb({currx,curry});
        graph[{currx,curry}].pb({nxtx,nxty});
        currx = nxtx , curry = nxty;
    }
    cout << bfs({0,0} , {currx,curry} , graph);
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