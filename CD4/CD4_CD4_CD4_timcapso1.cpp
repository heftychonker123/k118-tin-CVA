#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, x; cin >> n >> x;
    vector<long long> v(n);
    for (int i=0; i<n ; i++) cin >> v[i];
    long long ans=0;
    for (int i=0 ; i<n-1 ; i++){
        if (v[i]+v[i+1]==x) ans++;
    }
    cout << ans;
    return 0;

}
