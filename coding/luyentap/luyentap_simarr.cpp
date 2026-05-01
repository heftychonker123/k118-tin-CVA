#include <bits/stdc++.h>
using namespace std;
#define filename "simarr"
#define ll long long
#define vect vector
#define FOR(i , m , n) for (int i=m ; i<n ; i++)

const ll BASE = 31;
const ll MAXN = 1e6 + 5;
const ll MODULO1 = 1e9+7;
const ll MODULO2 = (1LL << 31) - 1;

ll p1[MAXN], p2[MAXN];


vect<ll> Hashing(const vect<ll>& v, const ll MODULO){
    vect<ll> h(v.size()+1);
    FOR(i , 1 , v.size()+1){
        h[i] = (h[i-1]*BASE + v[i-1]) % MODULO;
    }
    return h;
}


ll getHash(ll l , ll r , const vect<ll>& Hash, const ll *p, ll MODULO){
    return (Hash[r] - (Hash[l-1] * p[r-l+1]) % MODULO + MODULO) % MODULO;
}


bool check(ll length , const vect<ll>& hashDiff1 , const vect<ll>& hashDiff2 , ll n){
    set<pair<ll,ll>> seen;
    for (ll i = 0; i + length <= n; i++){
        ll subhash1 = getHash(i+1, i+length, hashDiff1, p1, MODULO1);
        ll subhash2 = getHash(i+1, i+length, hashDiff2, p2, MODULO2);
        pair<ll,ll> key = {subhash1, subhash2};
        if (seen.count(key)) return true;
        seen.insert(key);
    }
    return false;
}

void IO(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen(filename".inp" , "r")){
        freopen(filename".inp" , "r" , stdin);
        freopen(filename".out" , "w" , stdout);
    }
}

int main(){
    IO();
    
    p1[0] = p2[0] = 1;
    FOR(i , 1 , MAXN){
        p1[i] = (p1[i-1]*BASE) % MODULO1;
        p2[i] = (p2[i-1]*BASE) % MODULO2;
    }

    ll t; cin >> t;
    while (t--){
        ll n; cin >> n;
        vect<ll> v(n); FOR(i , 0 , n) cin >> v[i];

        
        vect<ll> d(n-1);
        FOR(i , 0 , n-1) d[i] = v[i+1] - v[i] + 1000000000LL;

        
        vect<ll> hashDiff1 = Hashing(d , MODULO1);
        vect<ll> hashDiff2 = Hashing(d , MODULO2);

        
        ll l = 1, r = n-1, res = 0;
        while (l <= r){
            ll m = (l+r)/2;
            if (check(m , hashDiff1 , hashDiff2 , n-1)){
                res = m;
                l = m+1;
            } else {
                r = m-1;
            }
        }
        cout << (res+1) << "\n"; 
    }
    return 0;
}
