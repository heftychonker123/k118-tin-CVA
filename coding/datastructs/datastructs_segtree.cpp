//1-indexed segment tree implementation

#include <bits/stdc++.h>
using namespace std;
#define filename "segtree"
#define ll                  long long
#define llmin               LLONG_MIN
#define llmax               LLONG_MAX
#define pb                  push_back
#define vect                vector
#define FOR(i , m , n)      for (int i=m ; i<n ; i++)
#define FOR_r(i , m , n)    for (int i=m ; i>n ; i--)
ll n ; vect<ll> a ; vect<ll> sT;

//Build function for a sum segment tree
ll build(ll l=1 , ll r=n , ll idx = 1){
    if (l==r) return a[l];
    ll mid = l + (r-l)/2;
    sT[2*idx] = build(l , mid , 2*idx);
    sT[2*idx+1] = build(mid+1 , r , 2*idx+1); 
    return sT[idx] = sT[2*idx]+sT[2*idx+1];
}

// Getting sum of an segment
ll sum(ll x , ll y,
        ll tl = 1 , ll tr = n , ll idx = 1){
    // Truong hop 1: x,y la mot khoang trong segment tree
    if (x==tl && y == tr) return sT[idx]; // return tong cua khoang nay
    // Truong hop 2: x,y nam o ben phai/trai cua segment hien thoi
    ll mid = tl + (tr-tl)/2;
    if (x <= mid && y <= mid){
        return sum(x,y,tl,mid,2*idx);
    }
    else if (x>mid && y>mid){
        return sum(x,y,mid+1,tr , 2*idx+1);
    }
    // Truong hop 3: x,y ko nam trong mot segment nao
    else{
        return sum(x,mid,tl,mid,2*idx) + sum(mid+1 , y , mid+1 , tr , 2*idx+1);
    }
}

void update(ll pos , ll val){
    ll l = 1 , r = n , idx=1;
    while (l<r){
        ll m = l + (r-l)>>1;
        idx<<=1;
        sT[idx] += val;
        if (pos<=m) r = m;
        else {
            l = m + 1;
            idx++;
        }
    }
    return;   
}

int main(){
    cin >> n;
    a.resize(n + 1);
    FOR(i, 1, n + 1) cin >> a[i];
    sT.resize(4*n+1);
    build();
    FOR(i ,0 , 4*n + 1) cout << sT[i] << " ";
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