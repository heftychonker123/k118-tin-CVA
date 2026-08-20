#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
const bool debug = false;
const string filename = "TINHTONG";

const int MOD = 1e9 + 7;
const ll INF = 1e16;

const int MAXN = 2e5 + 5;
ll st[4 * MAXN];

void update(int pos , ll x , int cl , int cr , int ci){
    if (cl == cr){
        st[ci] = x;
        return;
    }

    int cm = (cl + cr)/2;
    if (pos <= cm) update(pos , x , cl , cm , ci*2);
    else update(pos , x , cm + 1 , cr , ci * 2 + 1);
    st[ci] = st[ci * 2] + st[ci * 2 + 1];
}

ll query(int l , int r , int cl , int cr , int ci){
    if (l > r) return 0LL;
    if (l == cl && r == cr) return st[ci];

    int cm = (cl + cr)/2;
    ll left = query(l , min(cm,r) , cl , cm , ci * 2);
    ll right = query(max(l , cm + 1) , r , cl , cr , ci * 2 + 1);
    return left + right;
}