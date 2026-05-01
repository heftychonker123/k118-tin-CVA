#include <bits/stdc++.h>
using namespace std;
#define filename "hvixaucon"
#define ll                  long long
#define llmin               LLONG_MIN
#define llmax               LLONG_MAX
#define pb                  push_back
#define vect                vector
#define FOR(i , m , n)      for (int i=m ; i<n ; i++)
#define FOR_r(i , m , n)    for (int i=m ; i>n ; i--)
const ll BASE = 31 , MODULO = 1e9 + 7 , MAXN = 2*1e5 + 6;
ll p[MAXN];
vect<ll> Hash(string& v , ll n){
    vect<ll> h(n+1);
    FOR(i , 1 , n+1) h[i] = (h[i-1]*BASE + (v[i-1] - 'a' + 1))%MODULO;
    return h;
}

ll gethash(ll l , ll r , vect<ll> &Hash){
    return (Hash[r] - (Hash[l-1]*p[r-l+1])%MODULO + MODULO)%MODULO;
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
    p[0] = 1;
    FOR(i , 1 , MAXN) p[i] = (p[i-1]*BASE)%MODULO;


    string a,b ; cin >> a >> b;
    ll n=a.size() , m = b.size();
    set<ll> setHash;
    vect<ll> hash1(26) , hash2(26);
    FOR(i , 0 , n) hash1[a[i] - 'a']++;
    FOR(i , 0 , n) hash2[b[i] - 'a']++;
    vect<ll> hashb = Hash(b,m);



    bool equiv = true;
    FOR(j , 0 , 26){
        if (hash2[j] != hash1[j]) equiv = false; 
    }
    if (equiv){
        ll subHash = gethash(1 , n , hashb);
        setHash.insert(subHash);
    }


    FOR(i , 1 , m-n+1){
        hash2[b[i-1] - 'a']--;
        hash2[b[i+n-1] - 'a']++;
        equiv = true;
        FOR(j , 0 , 26){
            if (hash2[j] != hash1[j]) equiv = false; 
        }
        if (equiv){
            ll subHash = gethash(i+1 , i+n , hashb);
            setHash.insert(subHash);
        }
    }
    cout << setHash.size();
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