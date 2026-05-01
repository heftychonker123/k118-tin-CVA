#include <bits/stdc++.h>
using namespace std;
#define ll                  long long
#define llmin               LLONG_MIN
#define llmax               LLONG_MAX
#define pb                  push_back
#define vect                vector
#define FOR(i , m , n)      for (int i=m ; i<n ; i++)
#define FOR_r(i , m , n)    for (int i=m ; i>n ; i--)
const ll MAXN = 1e5+5;
vect<ll> adj[MAXN];
ll depth[MAXN] , parent[MAXN];

void dfs_iterative(int start){
    vect<pair<int,int>> st;
    st.push_back({start,0});
    depth[start] = 0;
    parent[start] = 0;

    while(!st.empty()){
        auto [n,p] = st.back();
        st.pop_back();
        for(int u: adj[n]){
            if (depth[u] < depth[n] + 1){
                parent[u] = n;
                depth[u] = depth[n] + 1;
            }
            st.push_back({u,n});
        }
    }
}
int main(){
    fill(depth, depth+MAXN, -1);
    fill(parent, parent+MAXN, 0);
    ll n ; cin >> n;
    ll m ; cin >> m;
    FOR(i , 0 , m){
        ll a,b ; cin >> a >> b;
        adj[a].push_back(b);
    }
    dfs_iterative(1);
    if (depth[n] == -1) cout << "IMPOSSIBLE";
    else{
        vect<ll> path;
        ll i = n;
        while (i!=0){
            path.push_back(i);
            i = parent[i];
        }
        cout << path.size() << "\n";
        FOR_r(i , path.size()-1 , -1) cout << path[i] << " ";
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