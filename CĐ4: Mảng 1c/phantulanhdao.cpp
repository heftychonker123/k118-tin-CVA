#include <bits/stdc++.h>
using namespace std;
#define pb push_back 

int main(){
    freopen("LANHDAO.inp" , "r" , stdin);
    freopen("LANHDAO.out" , "w" , stdout);
    int t; cin >> t;
    for (int i=0; i<t; i++){
        int n; cin >> n;
        vector<long> v={};
        vector<long> ans={};
        for (int j=0; j<n ; j++){
            long t; cin >> t;
            v.pb(t);
        }
        for (int j=0; j<n ; j++){
            bool state=true;
            for (int l=j+1; l<n; l++){
                if (v[j]<=v[l]) state=false;
            }
            if (state) ans.pb(v[j]);
        }
        for (long i:ans){
            cout << i << " ";
        }
        cout << endl;
    }
}