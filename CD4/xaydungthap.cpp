#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("XAYDUNGTHAP.inp" , "r" , stdin);
    //freopen("XAYDUNGTHAP.out" , "w" , stdout);
    vector<int> v={};
    for (int i=0; i<1000; i++){
        v.push_back(0);
    }
    int n; cin >> n;
    for (int i=0; i<n ; i++){
        int t; cin >> t;
        v[t]+=1;
    }
    int max=0;
    int ans=0;
    for (int i : v){
        if (i>0){
            if (i>max) max=i;
            ans++;
        }
    }
    cout << max << " " << ans;
}