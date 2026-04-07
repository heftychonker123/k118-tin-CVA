#include <bits/stdc++.h>
using namespace std;
#define filename "retphunxon"
#define ll                  long long
#define llmin               LLONG_MIN
#define llmax               LLONG_MAX
#define pb                  push_back
#define vect                vector
#define FOR(i , m , n)      for (int i=m ; i<n ; i++)
#define FOR_r(i , m , n)    for (int i=m ; i>n ; i--)
const int BASE = 31;
const ll MODULO = 1e9 + 7;
const ll MAXN = 1e5 + 5;

ll p[MAXN];
vect<ll> buildHash(string s){
    ll n = s.size();
    vect<ll> h(n+1);
    FOR(i , 1 , n+1){
        h[i] = (h[i-1]*BASE + s[i-1] - 'a' + 1)%MODULO;
    }
    return h;
}

ll getHash(ll l , ll r , vect<ll>& Hash){
    return (Hash[r] - (Hash[l-1]*p[r-l+1])%MODULO + MODULO)%MODULO;
}

bool check(ll idx , ll len , vect<ll>&Hash){
    if (len >= Hash.size()) return false;
    return getHash(idx , idx+len-1 , Hash) == Hash[len];
}

ll compute(ll idx , string s , vect<ll>& Hash){
    ll l = 1 , r = s.size();
    ll res = LLONG_MAX;
    while (l<=r){
        ll mid = l + (r-l)/2;
        if (check(idx,mid,Hash)){
            res = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    return (res != LLONG_MAX? res : 0);
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
    FOR(i, 1, MAXN) p[i] = (p[i-1]*BASE) % MODULO;

    string s ; cin >> s;
    ll n = s.size();
    vect<ll> Hash = buildHash(s);
    FOR(i , 1 , n+1){
        cout << compute(i , s , Hash) << " ";
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