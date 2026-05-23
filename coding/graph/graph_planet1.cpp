#include <bits/stdc++.h>
using namespace std;
#define filename "planet1"
#define ll                  long long
#define llmin               LLONG_MIN
#define llmax               LLONG_MAX
#define pb                  push_back
#define vect                vector
#define FOR(i , m , n)      for (int i=m ; i<n ; i++)
#define FOR_r(i , m , n)    for (int i=m ; i>n ; i--)
const ll MAXN = 2*1e5 + 5;
ll des[MAXN+1][33];

void preprocess(vect<ll>& graph , ll nodes){
    FOR(i , 1 , nodes+1){
        des[i][0] = graph[i]; 
    }

    FOR(depth , 1 , 33){
        FOR(i , 1 , nodes + 1){
            des[i][depth] = des[des[i][depth-1]][depth-1];
        }
    }
}

ll getKthDescendant(ll nodes , ll k){
    ll curr = nodes;
    while (k > 0){
        ll powCnt = 0;
        while ((1LL << powCnt) <= k) powCnt++;
        powCnt--;
        curr = des[curr][powCnt];
        k -= (1LL << powCnt);
    }
    return curr;
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
    ll n,q ; cin >> n >> q;
    vect<ll> graph(n+1); FOR(i , 1 , n+1) cin >> graph[i];
    preprocess(graph , n);
    while (q--){
        ll x,t; cin >> x >> t;
        cout << getKthDescendant(x,t) << "\n";
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