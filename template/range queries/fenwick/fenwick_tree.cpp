#include <bits/stdc++.h>
using namespace std;
#define ll long long
using pii = pair<ll,ll>;
#define fi first 
#define se second

const bool debug = false;
const int MAXN = 1e5 + 3;
int fen[MAXN] , n;

void update(int x , int v){
    for (; x<=n ; x += x & (-x)) fen[x] += v;
}

int query(int x){
    int res = 0;
    for (; x >= 1; x &= x - 1) res += fen[x];
    return res;
}

signed main(){
    if (fopen("n.inp" , "r")){
        freopen("n.inp" , "r" , stdin);
        freopen("n.out" , "w" , stdout);
    }
}