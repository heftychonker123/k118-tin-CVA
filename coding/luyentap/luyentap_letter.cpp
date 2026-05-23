#include <bits/stdc++.h>
using namespace std;
#define filename "letter"
#define ll                  long long
#define llmin               LLONG_MIN
#define llmax               LLONG_MAX
#define pb                  push_back
#define vect                vector
#define FOR(i , m , n)      for (int i=m ; i<n ; i++)
#define FOR_r(i , m , n)    for (int i=m ; i>n ; i--)
bool running = true;
void IO(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen(filename".inp" , "r"))
    {
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    }
}

void nxtgen(vect<ll>& v , ll n , ll k){
    ll j = k-1;
    while (j>=0 && v[j] == n+j-k) j--;
    if (j == -1){
        running = false;
        return;
    }
    
    v[j]++;
    FOR(i , j+1 , k) v[i] = v[j] + i-j;
    return;
}

int main(){
    IO();
    ll n,k ; cin >> n >> k;
    vect<vect<ll>> dist(n , vect<ll>(n));
    FOR(i , 0 , n) FOR(j , 0 , n) cin >> dist[i][j];
    ll best = LLONG_MAX;
    vect<ll> v; FOR(i , 0 , k) v.push_back(i);
    vect<ll> res;
    while (running){
        ll longest = LLONG_MIN;
        FOR(i , 0 , n){
            ll temp = LLONG_MAX;
            for (ll j : v) temp = min(temp , dist[i][j]);
            longest = max(temp , longest);
        }
        if (best > longest){
            best = longest;
            res = v;
        }
        nxtgen(v,n,k);
    }
    cout << best << "\n";
    for (ll i : res) cout << i+1 << " ";
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