#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 1;

// Euler totient function
long long phi[MAXN];

void compute(){
    for (int i = 0 ; i<MAXN ; i++) phi[i] = i;
    for (int i = 2 ; i<MAXN ; i++){
        if (phi[i] == i){
            for (int j = i ; j<MAXN ; j+=i) phi[j] -= phi[j]/i;
        }
    }
    return;
}

signed main(){
    compute();
    int n = 20;
    //1	1	2	2	4	2	6	4	6	4	10	4	12	6	8	8	16	6	18	8
    for (int i=1 ; i<=20 ; i++) cout << phi[i] << "\n";
}