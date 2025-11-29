#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    for(int i=0 ; i<t ; i++){
        int n; cin >> n;
        vector<long long> v(1000,0);
        for (int i=0; i<n ; i++){
            long long t; cin >> t;
            v[t-1]++;
        }
        long long max=-1;
        long long ans;
        for (int i=0; i<1000; i++){
            if (v[i]>3) max=i+1;
        }
        ans=v[max-1]/4;
        if (max==-1) {
            cout << -1;
        }
        else cout << max*max << " " << ans;
        cout << endl;
    }
    return 0;

}