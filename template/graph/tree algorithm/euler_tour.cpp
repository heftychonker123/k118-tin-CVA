#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll MAXN = 2e5 + 5;
ll n,q;
vector<ll> tree[MAXN];
ll v[MAXN];

ll timer = 0;
ll tin[MAXN] , tout[MAXN];
ll euler_tour[MAXN * 2 - 1];
void dfs(ll u = 1 , ll p = 0){
    tin[u] = ++timer;

    // Path query trick for sum from root -> node
    euler_tour[tin[u]] = v[u];
    for (ll &i : tree[u]){
        if (i != p) dfs(i , u);
    }

    tout[u] = ++timer;
    euler_tour[tout[u]] = -v[u];
}

ll st[4*MAXN];
void update(ll pos , ll x , ll cl , ll cr , ll ci){
    if (cl == cr){
        st[ci] = x;
        return;
    }

    ll cm = (cl + cr)/2;
    if (pos <= cm) update(pos , x , cl , cm , ci * 2);
    else update(pos , x , cm + 1 , cr , ci * 2 + 1);
    st[ci] = st[ci * 2] + st[ci * 2 + 1];
}

ll query(ll l , ll r , ll cl , ll cr , ll ci){
    if (l > r) return 0LL;
    if (l == cl && r == cr) return st[ci];

    ll cm = (cl + cr)/2;
    ll left = query(l , min(r , cm) , cl , cm , ci * 2);
    ll right = query(max(l , cm + 1) , r , cm + 1 , cr , ci * 2 + 1);
    return left + right;
}

void solve(){
    dfs();
    for (ll i = 1 ; i<=2*n ; i++){
        update(i, euler_tour[i] , 1 , 2*n , 1);
    }

    while (q--){
        ll t; cin >> t;
        if (t == 1){
            ll s,x ; cin >> s >> x;
            v[s] = x;
            update(tin[s] , x , 1 , 2*n , 1);
            update(tout[s] , -x , 1 , 2*n , 1);
        }

        if (t == 2){
            ll s ; cin >> s;
            ll res = query(tin[1] , tin[s] , 1 , 2*n , 1);
            cout << res << "\n";
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (ll i = 1 ; i<=n ; i++) cin >> v[i];

    for (ll i = 1 ; i<n ; i++){
        ll a,b ; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    solve();
}