#include <bits/stdc++.h>
using namespace std;
#define filename "hanhly"
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
    ll n,m ; cin >> n >> m;
    vect<vect<ll>> dp(n+1 , vect<ll>(m+1 , 0));
    vect<vect<ll>> trace(n+1 , vect<ll>(m+1 , -1));
    vect<pair<ll,ll>> t = {{0,0}};
    FOR(i , 1 , n+1){
        ll w,v ; cin >> w >> v;
        t.push_back({w,v});
        FOR(j , 1 , m+1){
            dp[i][j] = dp[i-1][j];
            trace[i][j] = j;
            if (j >= w){
                if (dp[i][j] <= dp[i-1][j-w] + v){
                    trace[i][j] = j-w;
                    dp[i][j] = dp[i-1][j-w] + v;
                }
            }
        }
    }

    ll i = n, j = max_element(dp[i].begin() , dp[i].end()) - dp[i].begin() + 1;
    cout << dp[i][j] << "\n"; // maximum value
    ll weight = 0;
    vect<int> chosen;

    while (i > 0 && j >= 0) {
        if (trace[i][j] != j) { // item i was chosen
            weight += t[i].first;
            chosen.push_back(i);
            j = trace[i][j];
        }
        i--;
    }
    for (int i = chosen.size()-1 ; i>-1 ; i--){
        cout << chosen[i] << " ";
    }
    cout << "\n";
    cout << weight << "\n"; // total weight of chosen items
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