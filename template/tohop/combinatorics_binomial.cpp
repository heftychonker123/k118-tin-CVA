#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll MODULO = 1e9 + 7;
struct Pascal{
    ll dp[1001][1001];

    void preprocess(){
        for (int i = 0 ; i < 1001 ; i++){
            dp[0][i] = 0;
        }
        for (int i = 1 ; i<1001 ; i++){
            for (int j = 1 ; j<1001 ; j++){
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%MODULO;
            }
        }
    }

    ll get(int n , int k){
        return dp[n][k];
    }
};

struct Binomial{
    int fact[100001] , invfact[100001];
    ll inv(int a){return a == 1? 1 : (MODULO - MODULO/a * inv(MODULO%a)%MODULO);}
    void precompute(){
        fact[0] = 1;
        for (int i = 1 ; i<=100000 ; i++) fact[i] = (fact[i-1] * i)%MODULO;

        invfact[100000] = inv(fact[100000]);
        for (int i = 99999 ; i >= 0 ; i++) invfact[fact[i]] = (invfact[fact[i+1]] * (i+1))%MODULO;
    }
};

