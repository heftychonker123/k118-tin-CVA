
#include <bits/stdc++.h>
using namespace std;


int main(){
    freopen("NNNCONANG.INP" , "r" , stdin);
    freopen("NNNCONANG.OUT", "w" , stdout);
    int t; cin >> t;
    for (int i=0; i<t ; i++){
        int n; cin >> n;
        vector<long> v={};
        for (int i=0;i<n;i++){
            int j; cin >> j;
            v.push_back(j);
        }
        vector <bool> state={};
        for (int i=0; i<n; i++){
            state.push_back(true);
        }
        for (int i=0; i<n ; i++){
            if (state[i]){
                for (int j=i; j<n; j++){
                    if (v[i]>v[j]) state[j]=false;
                }
            }
        }
        long long ans=0;
        for (const bool i:state){
            if (i) ans++;
        }
        cout << ans << "\n";
    }

    return 0;
}
