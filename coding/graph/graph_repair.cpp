#include <bits/stdc++.h>
using namespace std;
#define filename "repair"
#define ll                  long long
#define llmin               LLONG_MIN
#define llmax               LLONG_MAX
#define pb                  push_back
#define vect                vector
#define FOR(i , m , n)      for (int i=m ; i<n ; i++)
#define FOR_r(i , m , n)    for (int i=m ; i>n ; i--)

const ll MAXN = 1e5 + 5;
ll dsu[MAXN] , Size[MAXN];
struct Edge{
    ll a,b,c;
};
bool comp(Edge x , Edge y){
    return x.c < y.c;
}

// DSU data structures
ll find(ll node){
    if (node != dsu[node]) return dsu[node] = find(dsu[node]);
    else return node;
}

void merge(ll a , ll b){
    a = find(a) ; b = find(b);
    if (Size[a] < Size[b]) swap(a,b);
    Size[a] += Size[b];
    dsu[b] = a;
    return;
}
ll Kruskal(vect<Edge>& edges , ll nodes){
    sort(edges.begin() , edges.end() , comp);
    ll res = 0, total_edges = 0;
    for (auto i : edges){
        if (find(i.a) != find(i.b)){
            res += i.c;
            total_edges++;
            merge(i.a , i.b);
        }
    }
    return (total_edges == (nodes-1)? res : -1);
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
    ll n , m ; cin >> n >> m;
    vect<Edge> edges(m); FOR(i , 0 , m) cin >> edges[i].a >> edges[i].b >> edges[i].c;

    FOR(i , 1 , n+1){
        dsu[i] = i;
        Size[i] = 1;
    }
    ll res = Kruskal(edges , n);
    if (res != -1) cout << res;
    else cout << "IMPOSSIBLE";
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