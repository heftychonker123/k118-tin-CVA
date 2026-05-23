#include <bits/stdc++.h>
using namespace std;
#define filename "elevator"
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
    ll n , x ; cin >> n >> x;
    vect<ll> v(n); FOR(i , 0 , n) cin >> v[i];
    vect<pair<ll,ll>> dp((1<<n));
    dp[0] = {1, 0}; // 1 chuyến, trọng lượng 0
    for (int s = 1; s < (1<<n); s++) {
        dp[s] = {n+1, 0}; // khởi tạo lớn
        for (int i = 0; i < n; i++) {
            if (s & (1<<i)) {
                auto prev = dp[s ^ (1<<i)];
                if (prev.second + v[i] <= x) {
                    // thêm vào chuyến cuối
                    auto candidate = make_pair(prev.first, prev.second + v[i]);
                    dp[s] = min(dp[s], candidate);
                } else {
                    // mở chuyến mới
                    auto candidate = make_pair(prev.first + 1, v[i]);
                    dp[s] = min(dp[s], candidate);
                }
            }
        }
    }
    cout << dp[(1<<n)-1].first;
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