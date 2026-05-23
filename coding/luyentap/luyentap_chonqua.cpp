#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ; cin >> n;
    vector<int> v(n); for (int i = 0 ; i<n ; i++) cin >> v[i];
    int res = 0;
    for (int i = 0 ; i<n-1 ; i++){
        res = max(res , v[i] + v[i+1]);
    }
    cout << res;
}