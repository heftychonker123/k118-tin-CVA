#include <bits/stdc++.h>
using namespace std;
#define filename "binary_lifting"
#define ll                  long long
#define llmin               LLONG_MIN
#define llmax               LLONG_MAX
#define pb                  push_back
#define vect                vector

vect<vect<ll>> preprocess(vect<ll> &tree, ll nodes) {
    ll LOG = log2(nodes) + 1;
    vect<vect<ll>> parents(nodes, vect<ll>(LOG, -1));

    for (ll i = 0; i < nodes; i++) {
        parents[i][0] = tree[i];
    }

    for (ll j = 1; j < LOG; j++) {
        for (ll i = 0; i < nodes; i++) {
            if (parents[i][j-1] != -1) {
                parents[i][j] = parents[ parents[i][j-1] ][j-1];
            }
        }
    }

    return parents; // The binary lifting table
}
//Example: kth Ancestor problem
ll kthAncestor(ll node , ll n , ll k , vect<vect<ll>> &parents){
    while (k>0){
        //Tìm x sao cho 2^x <= k
        ll powCnt = 0;
        while ((1LL<<powCnt) <= k) powCnt++; //(1LL<<powCNT) : tương đương 2^powCnt
        powCnt--;
        node = parents[node][powCnt];
        k -= (1LL << powCnt);
    }
    return node;
}


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
    return 0;
}