#include <bits/stdc++.h>
using namespace std;
#define filename "maxrect"
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

ll findRect(vect<ll>& v , ll n){
    stack<ll> st1;
    vect<ll> left(n);
    FOR(i , 1 , n+1){
        while (!st1.empty() && v[i-1] <= v[st1.top()-1]) st1.pop();
        left[i-1] = (st1.empty()? 0 : st1.top());
        st1.push(i);
    }
    stack<ll> st2;
    vect<ll> right(n);
    FOR_r(i , n , 0){
        while (!st2.empty() && v[i-1] <= v[st2.top()-1]) st2.pop();
        right[i-1] = (st2.empty()? n+1 : st2.top());
        st2.push(i);
    }
    ll res = 0;
    FOR(i , 1 , n+1){
        ll width = right[i-1] - left[i-1] - 1;
        res = max(res , width * v[i-1]);
    }
    return res;
}

ll solve(vect<string>& grid , ll m , ll n){
    vect<ll> h(n, 0);
    ll res = 0;
    FOR(i , 0 , m){
        FOR(j , 0 , n){
            if (grid[i][j] == 'W') h[j] += 1;
            else h[j] = 0;
        }
        res = max(res , findRect(h , n));
    }
    return res;
}

int main(){
    IO();
    ll m,n; cin >> m >> n;
    vect<string> v(m);
    FOR(i , 0 , m) cin >> v[i];
    cout << solve(v , m , n);
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