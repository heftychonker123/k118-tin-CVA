#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int main(){
    int n; cin >> n;
    vector <long long> v={};
    for (int i=0 ; i<n ; i++){
        long long t; cin >> t;
        long long ans=true;
        for (const long long i:v){
            if (i==t) ans=false;
        }
        if (ans){
            cout << t << " ";
            v.pb(t);
        }
    }
    return 0;
}