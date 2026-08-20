#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct ModInvExp{
    ll MODULO;

    ll exp(ll a , ll b){
        ll x = a%MODULO;
        ll res = 1;
        while (b!=0){
            if (b%2 == 0) res = (res*x)%MODULO;
            x = (x*x)%MODULO;
            b/=2;
        }
    }

    ll modinv(ll a){
        return exp(a , MODULO-2);
    }
};

struct ModInvEuclid{
    ll MODULO;
    ll inv[100001];
    void precompute(){
        inv[1] = 1;
        for (int i = 2 ; i < 100001 ; i++) inv[i] = MODULO - MODULO/i * inv[MODULO%i] % MODULO;
    }

    ll modinv(ll a){
        return inv[a];
    }
};

signed main(){

}