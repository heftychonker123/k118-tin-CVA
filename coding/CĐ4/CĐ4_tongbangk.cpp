#include <bits/stdc++.h>

using namespace std;
int main(){
    int n ; cin >> n ;
    long long x;
    vector<long long> v(n);
    long long ans=0;
    for (int i=0; i<n ; i++) cin >> v[i];
    cin>>x;
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n ; j++){
            if (v[i]+v[j]==x) ans++;
        }
    }
    cout << ans;
}
