#include <bits/stdc++.h>
using namespace std;
#define filename "themduongdi"
#define ll                  long long
#define llmin               LLONG_MIN
#define llmax               LLONG_MAX
#define pb                  push_back
#define vect                vector
#define FOR(i , m , n)      for (int i=m ; i<n ; i++)
#define FOR_r(i , m , n)    for (int i=m ; i>n ; i--)

const ll MAXN = 1e4 + 5;
ll dsu[MAXN] , deg[MAXN] , Size[MAXN];

ll find(ll node){
    if (node == dsu[node]) return node;
    else return dsu[node] = find(dsu[node]);
}

void merge(ll a , ll b){
    a = find(a) , b = find(b);
    if (a==b) return;
    if (Size[a] < Size[b]) swap(a,b);
    Size[a] += Size[b];
    dsu[b] = a;
    return;
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
    ll res = 0;
    FOR(i , 1 , n+1){
        dsu[i] = i;
        Size[i] = 1;
    }

    FOR(i , 0 , m){
        ll a,b ; cin >> a >> b;
        merge(a,b); deg[a]++; deg[b]++;
    }

    FOR(i , 1 , n+1){
        FOR(j , i+1 , n+1){
            if ((deg[i] % 2 == 0 || deg[j] % 2 == 0) && find(i)!=find(i)){
                merge(i,j); deg[i]++; deg[j]++; res++;
            }
            if (deg[i]%2 != 0 && deg[j]%2 != 0){
                merge(i,j); deg[i]++; deg[j]++; res++;
            }
        }
    }
    cout << res;
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