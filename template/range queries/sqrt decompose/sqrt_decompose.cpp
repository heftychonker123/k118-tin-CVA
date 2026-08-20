#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 2e5 + 1;
int K = 460;

vector<int> b(1000);
int a[MAXN];

void preprocess(int n){
    for (int i = 0 ; i<n ; i+=K){
        for (int j = 0 ; j<n ; j++){
            if (i + j < n){
                b[i] += a[i+j];
            }
        }
    }
}

int query(int l , int r){
    int res = 0;
    int k = l / K;
    int p = r / K;
    if (k == p){
        for (int i = l ; i <= r ; i++) res += a[i]; 
    }

    else{
        for (int i = l ; i < (k+1)*K ; i++) res += a[i];
        for (int i = k+1 ; i<p ; i++) res += b[i];
        for (int i = p * K ; i<=r ; i++) res += a[i];
    }

    return res;
}

signed main(){
    int n,q ; cin >> n >> q;
    for (int i = 0 ; i<n ; i++) cin >> a[i];
    preprocess(n);
    
    while (q--){
        int l,r ; cin >> l >> r;
        l-- ; r--;
        cout << query(l,r) << "\n"; 
    }
}