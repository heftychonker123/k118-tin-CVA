#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 2e5 + 5;
ll sparse[MAXN][32];

void buildSparse(int a[] , ll len){
    for (int i = 1 ; i<=len ; i++){
        sparse[i][0] = a[i];
    }

    for (int j = 1 ; j<32 ; j++){
        for (ll i = 1 ; i<=len ; i++){
            if (i + (1LL << j) <= len) 
                sparse[i][j] = min(sparse[i][j-1] , sparse[i + (1LL << j)][j-1]);
        }
    }
}
int log2(int x){
    return (x ? __builtin_clz(1) - __builtin_clz(x) : -1);
}

ll minQuery(int l , int r){
    int log = log2(r-l+1);
    return min(sparse[l][log] , sparse[r - (1<<log) + 1][log]);
}
