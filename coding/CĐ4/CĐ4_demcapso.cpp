#include <bits/stdc++.h>
using namespace std;
using namespace std;

int main(){
    //freopen("DEMCAPSO.INP" , "r" , stdin);
    //freopen("DEMCAPSO.OUT" , "w" , stdout);
    int t; cin >> t;
    for (int z=0; z<t; z++){
        long long n; cin >> n;
        vector<long long> a(n);
        for (int i=0; i <n ; i++) cin >> a[i];
        long long ans=0;
        for(int i=0; i<n; i++){
            for (int j=i+1; j<n ; j++){
                if (a[i]*i>a[j]*j) ans++;
            }
        }
        cout << ans;
        cout << "\n";
    }
    return 0;
}