#include <bits/stdc++.h>
using namespace std;
#define pb push_back 

int main() {
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        int n; cin >> n;
        if (n == 0) {
            cout << endl;
            continue;
        }

        vector<long long> v(n);
        for (int j = 0; j < n; j++) {
            cin >> v[j];
        }

        long long temp = v[n - 1];
        vector<long long> ans = {temp};

        for (int i = n - 2; i >= 0; i--) {
            if (v[i] > temp) {
                temp = v[i];
                ans.pb(temp);
            }
        }

        for (int i = ans.size() - 1; i > 0; i--) {
            cout << ans[i] << " ";
        }
        cout << ans[0] << endl;
    }
    return 0;
}
