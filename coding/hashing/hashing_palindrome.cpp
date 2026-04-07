#include <bits/stdc++.h>
using namespace std;
#define filename "palindrome"
#define ll                  long long
#define llmin               LLONG_MIN
#define llmax               LLONG_MAX
#define pb                  push_back
#define vect                vector
#define FOR(i , m , n)      for (int i=m ; i<n ; i++)
#define FOR_r(i , m , n)    for (int i=m ; i>n ; i--)
const ll BASE = 31 , MODULO = 1e9 + 7 , MAXN = 5005;
ll p[MAXN];

vect<ll> buildHash(string s){
    ll n = s.size();
    vect<ll> h(n+1);
    FOR(i , 1 , n+1){
        h[i] = (h[i-1]*BASE + (s[i-1] - 'a' + 1))%MODULO;
    }
    return h;
}

ll getHash(ll l , ll r , vect<ll>& Hash){
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
    ll n ; cin >> n;
    string s ; cin >> s;
    p[0] = 1;
    FOR(i,1,MAXN) p[i] = (p[i-1]*BASE) % MODULO;
    vect<ll> fHash = buildHash(s);
    reverse(s.begin() , s.end());
    vect<ll> rHash = buildHash(s);
    ll t ; cin >> t; 
    while (t--){
        ll l,r ; cin >> l >> r;
        ll n = s.size();
        ll fSub = getHash(l, r, fHash);
        ll rSub = getHash(n-r+1, n-l+1, rHash);
        if (fSub == rSub) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}


/* John 3:16
                    .-=====-.
                    | .""". |
                    | |   | |
                    | |   | |
                    | '---' |
                    |       |
                    |       |
 .-================-'       '-================-.
j|  _                                          |
g|.'o\                                    __   |
s| '-.'.                                .'o.`  |
 '-==='.'.=========-.       .-========.'.-'===-'
        '.`'._    .===,     |     _.-' /
          '._ '-./  ,//\   _| _.-'  _.'
             '-.| ,//'  \-'  `   .-'
                `//'_`--;    ;.-'
                  `\._ ;|    |
                     \`-'  . |
                     |_.-'-._|
                     \  _'_  /
                     |; -:- | 
                     || -.- \ 
                     |;     .\
                     / `'\'`\-;
                    ;`   '. `_/
                    |,`-._;  .;
                    `;\  `.-'-;
                     | \   \  |
                     |  `\  \ |
                     |   )  | |
                     |  /  /` /
                     | |  /|  |
                     | | / | /
                     | / |/ /|
                     | \ / / |
                     |  /o | |
                     |  |_/  |
                     |       |
                     |       |
                     |       |
                     |       |
                     |       |
                     |       |
                     |       |
                     '-=====-'
*/