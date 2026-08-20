#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> build(string s , ll base , ll mod){
    int n = s.size();
    vector<ll> hash(n + 1);
    for (int i = 1 ; i<=n ; i++) hash[i] = (1LL * hash[i-1] * base + (s[i-1] - 'a'))%mod;
    return hash;
}

ll getHash(int l , int r , vector<ll>& hash , ll p[] , ll mod){
    return (hash[r] - (hash[l-1] * p[r - l + 1])%mod + mod)%mod;
}

const int MAXL = 1e6 + 3;
ll base = 31 , p[MAXL];

// Always hash with 2 modulo
const ll mod1 = 1e9 + 7;
const ll mod2 = (1 << 31) - 1;
