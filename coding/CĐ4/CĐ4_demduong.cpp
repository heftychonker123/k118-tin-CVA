#include <bits/stdc++.h>
using namespace std;


int main(){
    freopen("demduong.inp" , "r" , stdin);
    freopen("demduong.out" , "w" , stdout);
    int n; cin >> n;
    vector <int> v={};
    for (int i=0; i < n; i++){
        int t; cin >> t;
        v.push_back(t);
    }
    int ans=0;
    long long sum=0;
    for (const int & i : v){
        if (i > 0){
            sum+=i; ans++;
        }
    }
    cout << ans << " " << sum;
}