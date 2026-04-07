#include <bits/stdc++.h>
using namespace std;
#define filename "cycle_check"
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

ll find(vect<ll> &dsu , ll node){
    while (node!=dsu[node]) node = dsu[node];
    return node;
}

void DSUmerge(vect<ll> &dsu , vect<ll>& size , ll x , ll y){
    if (size[x] < size[y]) swap(x,y);
    size[x] += size[y];
    dsu[y] = x;
    return;
}
int main(){
    IO();
    ll n,m ; cin >> n >> m;
    vect<ll> dsu(n) , size(n);
    FOR(i , 0 , n){
        dsu[i] = i ; size[i] = 1;
    }

    FOR(i , 0 , m){
        ll a,b ; cin >> a >> b;
        a--;b--;
        ll rootA = find(dsu, a);
        ll rootB = find(dsu, b);
        if (rootA == rootB){
            cout << 1 << "\n";
            return 0;
        }
        DSUmerge(dsu, size, rootA, rootB);
    }
    cout << 0 << "\n";
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