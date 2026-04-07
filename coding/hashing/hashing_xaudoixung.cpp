#include <bits/stdc++.h>
using namespace std;
#define filename "xaudoixung"
#define ll long long
#define vect vector
#define FOR(i , m , n) for (int i=m ; i<n ; i++)
const ll BASE = 31 , MODULO = 1e9 + 7 , MAXN = 1000005;
ll p[MAXN];

vect<ll> buildHash(const string &s){
    ll n = s.size(); vect<ll> h(n+1);
    FOR(i , 1 , n+1){
        h[i] = (h[i-1]*BASE + (s[i-1] - 'a' + 1))%MODULO;
    }
    return h;
}

ll getHash(ll l , ll r , vect<ll> &Hash){
    return (Hash[r] - (Hash[l-1]*p[r-l+1])%MODULO + MODULO)%MODULO;
}

pair<ll,ll> palindrome(ll half_length , vect<ll>& fhash , vect<ll>& rhash, ll n){
    ll odd = half_length * 2 + 1;
    FOR(i , 1 , n - odd + 2){
        ll l = i , r = i+odd-1;
        ll fSub = getHash(l , r , fhash);
        ll rSub = getHash(n-r+1 , n-l+1 , rhash);
        if (fSub == rSub) return {odd, l-1};
    }
    ll even = half_length * 2 + 2;
    FOR(i , 1 , n - even + 2){
        ll l = i , r = i+even-1;
        ll fSub = getHash(l , r , fhash);
        ll rSub = getHash(n-r+1 , n-l+1 , rhash);
        if (fSub == rSub) return {even, l-1};
    }
    return {-1,-1};
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
    p[0] = 1;
    FOR(i,1,MAXN) p[i] = (p[i-1]*BASE) % MODULO;

    string s; cin >> s;
    ll n = s.size();
    vect<ll> fhash = buildHash(s);
    string rev = s; reverse(rev.begin(), rev.end());
    vect<ll> rhash = buildHash(rev);

    ll l = 1 , r = n/2 + 1;
    ll bestLen = 1, bestPos = 0;
    while (l<=r){
        ll m = (l+r)/2;
        auto res = palindrome(m , fhash , rhash, n);
        if (res.first != -1){
            bestLen = res.first;
            bestPos = res.second;
            l = m+1;
        } 
        else r = m-1;
    }
    cout << s.substr(bestPos, bestLen) << "\n";
    return 0;
}
