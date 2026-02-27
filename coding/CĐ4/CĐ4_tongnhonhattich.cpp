#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    for (int tc=0 ; tc<t ; tc++){
        int n ; cin >> n;
        long long ans=0;
        vector <long long> a(n) , b(n);
        for (int i=0 ; i<n ; i++) cin >> a[i];
        for (int i=0 ; i<n ; i++) cin >> b[i];
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for (int i=0 ; i<n ; i++){
            ans += a[i] * b[n-1-i];
        }
        cout << ans << endl;
    }
}