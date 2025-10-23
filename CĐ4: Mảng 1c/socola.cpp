#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    for (int j=0 ; j<t ; j++){
        int n; cin >> n;
        vector < long long> v(n);
        for (int i=0 ; i<n ; i++) cin >> v[i];
        cout << *min_element(v.begin(), v.end()) << "\n";
    }
}