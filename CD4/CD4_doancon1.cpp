#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector < long double> v(n);
    for (int i=0; i<n ; i++) cin >> v[i];
    int ans=0;
    int temp=1;
    for (int i=0 ; i<n-1 ; i++){
        if (v[i]<v[i+1]) temp++;
        else{
            ans=max(ans,temp);
            temp=1;
        }
    }
    ans=max(ans,temp);
    cout << ans;
    return 0;
}
