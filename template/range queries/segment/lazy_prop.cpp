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
ll st[MAXN * 4];
ll lazy[MAXN * 4];

void update_range(int l, int r, ll x, int cl, int cr, int ci) {
    if (l > r) return;
    if (l == cl && r == cr) {
        lazy[ci] += x;
        return;
    }

    int cm = (cl + cr) / 2;
    update_range(l, min(r, cm), x, cl, cm, ci * 2);
    update_range(max(l, cm + 1), r, x, cm + 1, cr, ci * 2 + 1);
}

void prop(int ci){
    lazy[ci * 2] += lazy[ci];
    lazy[ci * 2 + 1] += lazy[ci];
    lazy[ci] = 0;
}

ll query_range(int l , int r , int cl , int cr , int ci){
    if (l > r) return 0;
    if (l == cl && r == cr) return st[ci] + lazy[ci];

    int cm = (cl + cr)/2;
    prop(ci);
    ll left = query_range(l, min(r, cm), cl, cm, ci * 2);
    ll right = query_range(max(l, cm + 1), r, cm + 1, cr, ci * 2 + 1);
    return left + right;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    if (fopen((filename + ".inp").c_str(), "r")){
        freopen((filename + ".inp").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
    int n , q ; cin >> n >> q;
    for (int i = 1 ; i<=n ; i++){
        ll t ; cin >> t;
        update_range(i , i , t , 1 , n , 1);
    }

    while (q--){
        int t ; cin >> t;
        if (t == 1){
            int a,b; ll u ; cin >> a >> b >> u;
            update_range(a,b,u,1,n,1);
        }

        if (t == 2){
            int k ; cin >> k;
            cout << query_range(k , k , 1 , n , 1) << "\n";
        }
    }
}

