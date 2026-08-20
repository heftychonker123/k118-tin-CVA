#include <bits/stdc++.h>
using namespace std;

const int MAXK = 1e6 + 1;
int spf[MAXK];
int cnt[MAXK];
void preprocess(){
    for (int i = 2 ; i<MAXK ; i++) spf[i] = i;
    for (int i = 2 ; i<MAXK ; i++){
        if (spf[i] == i){
            for (int j = i ; j<MAXK ; j+=i){
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

signed main(){
    preprocess();
    int n,k ; cin >> n >> k;
    vector<int> a(n); for (int i = 0 ; i<n ; i++) cin >> a[i];

    for (int i = 2 ; i<=k ; i++) cnt[spf[i]]++;
    for (int i : a) cout << cnt[i] << "\n";
}