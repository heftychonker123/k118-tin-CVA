#include <bits/stdc++.h>
using namespace std;
#define filename "xephang"
#define ll                  long long
#define llmin               LLONG_MIN
#define llmax               LLONG_MAX
#define pb                  push_back
#define vect                vector
#define FOR(i , m , n)      for (int i=m ; i<n ; i++)
#define FOR_r(i , m , n)    for (int i=m ; i>n ; i--)


const ll MAXN = 2000 , MAXM = 2000;
vect<vect<ll>> sTs(MAXN , vect<ll>(4*MAXM));
ll m,n;


void update(ll pos , ll val , vect<ll>& sT , vect<ll>& a){
    ll l=0 , r = n-1 , idx = 0;
    a[pos] += val;
    while (l<r){
        sT[idx] = max(sT[idx] , a[pos]);
        ll mid = l + ((r - l) >> 1);
        idx <<= 1;
        if (pos > mid) l = mid+1;
        else{
            idx--;
            r = mid;
        }
    }
}

void update_row(ll row , ll val , vect<vect<ll>> & a){
    FOR(i , 0 , n) update(i , val , sTs[row] , a[row]);
}

void update_col(ll col , ll val , vect<vect<ll>>& a)
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
    ll q ; cin >> n >> m >> q;
    while (q--){
        ll queries ; cin >> queries;
        if (queries == 1){
            ll r,x ; cin >> r >> x;
            r--;
            update_row(r,x);
        }
        if (queries == 2){
            ll c,x ; cin >> c >> x;
            update_col(c,x);
        }
        if (queries == 3){
            ll x1,y1,x2,y2 ; cin >> x1 >> y1 >> x2 >> y2;
            minimium(x1,y1,x2,y2);
        }
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