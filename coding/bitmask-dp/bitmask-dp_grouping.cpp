#include <bits/stdc++.h>
using namespace std;
#define filename "grouping"
#define ll                  long long
#define llmin               LLONG_MIN
#define llmax               LLONG_MAX
#define pb                  push_back
#define vect                vector
#define FOR(i , m , n)      for (int i=m ; i<n ; i++)
#define FOR_r(i , m , n)    for (int i=m ; i>n ; i--)
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
    ll n ; cin >> n;
    vect<vect<int>> v(n , vect<int>(n));
    FOR(i , 0 , n) FOR(j , 0 , n) cin >> v[i][j];

    vect<ll> dp(1<<n);
    for (int s = 0 ; s< (1<<n) ; s++){
        ll cost = 0;
        for (int i = 0 ; i < n ; i++){
            if (!(s & (1<<i))) continue;
            for (int j = i+1 ; j < n ; j++){ // chỉ xét j > i
                if (s & (1<<j)) cost += v[i][j];
            }
        }
        dp[s] = cost;

        for (int s_mask = s ; s_mask ; s_mask = (s_mask-1)&s){
            int sub = s ^ s_mask;
            dp[s] = max(dp[s] , dp[sub] + dp[s_mask]);
        }
    }
    cout << dp[(1<<n) - 1];
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