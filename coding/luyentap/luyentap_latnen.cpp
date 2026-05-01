#include <bits/stdc++.h>
using namespace std;
#define filename "build"
#define ll                  long long
#define llmin               LLONG_MIN
#define llmax               LLONG_MAX
#define pb                  push_back
#define vect                vector
#define FOR(i , m , n)      for (int i=m ; i<n ; i++)
#define FOR_r(i , m , n)    for (int i=m ; i>n ; i--)
const ll MAXN = 105;
string dp[MAXN];

string addBigNum(string a , string b){
    if (a.size() > b.size()) swap(a,b);
    ll j = 0 , carry = 0;
    string res;
    while (j < a.size()){
        ll currdigit = (a[a.size()-j-1] - '0') + (b[b.size()-j-1] - '0') + carry;
        res += (currdigit%10 + '0'); carry = currdigit/10;
        j++;
    }
    while (j<b.size()){
        ll currdigit = (b[b.size()-j-1] - '0') + carry;
        res += (char)(currdigit%10 + '0'); carry = currdigit/10;
        j++;
    }
    if (carry > 0) res += (char)(carry+'0');
    reverse(res.begin() , res.end());
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
    ll t ; cin >> t;
    dp[0] = "1" ; dp[1] = "1";
    FOR(i , 2 , MAXN) dp[i] = addBigNum(dp[i-1] , dp[i-2]);
    while (t--){
        ll n ; cin >> n;
        cout << dp[n] << "\n";
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