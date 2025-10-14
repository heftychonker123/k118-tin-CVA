#include <bits/stdc++.h>
using namespace std;
#define pb push_back 

int main(){
    int t; cin >> t;
    for (int i=0; i<t; i++){
        int n; cin >> n;
        vector<long> v={};
        vector<long> ans={};
        for (int j=0; j<t ; j++){
            long t; cin >> t;
            bool state=true;
            for (long l:v){
                if (t<l) state=false;
            }
            if (state) ans.pb(t);
            v.pb(t);
        }
        cout << ans.size() << "\n";
        for (long j:ans){
            cout << j << " ";
        }
    }
}