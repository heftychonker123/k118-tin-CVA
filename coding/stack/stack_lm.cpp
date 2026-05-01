#include <bits/stdc++.h>
using namespace std;
#define filename "lm"
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

void traceback(vect<pair<ll,char>>& trace){
    ll i = 0;
    string res = "";
    while (i!=-1){
        auto [nxt , c] = trace[i];
        i = nxt; res += c;
    }
    reverse(res.begin() , res.end());
    cout << res;
}
int main(){
    IO();
    ll n ; cin >> n;
    string s ; cin >> s; sort(s.begin() , s.end());
    vect<ll> dp(n , -1);
    vect<pair<ll,char>> trace(n);
    queue<ll> q;
    for (char& i : s){
        if (i == '0') continue;
        ll t = (i-'0');
        if (dp[t%n] == -1){
            q.push(t%n) ; dp[t%n] = 1 , trace[t%n] = {-1 , i};
        }
    }


    while (!q.empty()){
        ll curr = q.front(); q.pop();
        for (char& c : s){
            int nxt = (curr*10 + (c-'0')) % n;
            if(dp[nxt]==-1){
                dp[nxt]=dp[curr]+1;
                trace[nxt]={curr,c};
                q.push(nxt);
            }

        }
    }

    if (dp[0] == -1) cout << 0;
    else traceback(trace);
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