#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("nptp.inp" , "r" , stdin);
    freopen("nptp.out" , "w" , stdout);
    string n; cin >> n;
    long long ans=0;
    for (int i=0; i<n.size(); i++){
        ans+= (int)(n[i]-'0') * pow(2, n.size()-i-1);
    }
    cout << ans;
    return 0;
}