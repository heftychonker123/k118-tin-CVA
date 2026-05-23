#include <bits/stdc++.h>
using namespace std;
#define filename "xaydungd"
#define ll                  long long
#define llmin               LLONG_MIN
#define llmax               LLONG_MAX
#define pb                  push_back
#define vect                vector
#define FOR(i , m , n)      for (int i=m ; i<n ; i++)
#define FOR_r(i , m , n)    for (int i=m ; i>n ; i--)
const ll MAXN = 1e4 + 5;

ll dsu[MAXN+1] , s[MAXN+1];

ll find(ll node){
    if (node != dsu[node]) return dsu[node] = find(dsu[node]);
    else return node;
}

void merge(ll a , ll b){
    a = find(a) ; b = find(b);
    if (s[a] < s[b]) swap(a,b);
    dsu[b] = a;
    s[a] += s[b];
}

bool comp(const array<ll,3>& a, const array<ll,3>& b){
    return a[2] < b[2];
}

ll kruskal(vector<array<ll,3>>& edges , ll nodes){
    sort(edges.begin(), edges.end(), comp);
    ll res = LLONG_MIN;
    for(auto &e : edges){
        ll a = e[0], b = e[1];
        if(find(a) != find(b)){
            res = max(res, e[2]);
            merge(a,b);
        }
    }
    return res;
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
    FOR(i , 1 , n+1){
        dsu[i] = i ; s[i] = 1;
    }
    vect<array<ll,3>> edges(m);
    FOR(i , 0 , m) cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    cout << kruskal(edges , n);
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