#include <bits/stdc++.h>
using namespace std;
#define filename "dienso"
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
vect<ll> getRightSmaller(vect<ll>& v , ll n){
    stack<ll> st;
    vect<ll> res(n);
    FOR_r(i , n-1 , -1){
        while (!st.empty() && v[i] <= v[st.top()]) st.pop();
        res[i] = (st.empty()? n : st.top());
        st.push(i);
    }
    return res;
}

ll solve(vect<ll>& v , ll n){
    vect<ll> right = getRightSmaller(v , n);
    vect<bool> modified(n , false);
    ll res = 0;
    FOR(i , 0 , n){
        if (v[i] == 0) continue;
        if (modified[i]) continue;
        ll r = right[i]; res++;
        FOR(j , i , r){
            if (v[j] == v[i]) modified[j] = true;
        }
    }
    return res;
}
int main(){
    IO();
    ll t ; cin >> t;
    while (t--){
        ll n ; cin >> n;
        vect<ll> v(n); FOR(i , 0 , n ) cin >> v[i];
        cout << solve(v , n) << "\n";
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