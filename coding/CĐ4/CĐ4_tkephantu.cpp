#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("THONGKE.inp" , "r" , stdin);
    freopen("THONGKE.out" , "w" , stdout);
    vector<int> v={};
    for (int i=0; i<100000; i++){
        v.push_back(0);
    }
    int n; cin >> n;
    for (int i=0; i<n ; i++){
        int t; cin >> t;
        v[t]+=1;
    }
    for (int i=0; i<100000;i++){
        if (v[i]>0) cout << i << ":"<<v[i]<<endl;
    }
}