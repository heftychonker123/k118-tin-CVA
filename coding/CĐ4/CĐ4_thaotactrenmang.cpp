#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("Thaotac1.inp" , "r" , stdin);
    //freopen("Thaotac1.out" , "w" , stdout);

    int n, q;
    cin >> n >> q;

    vector<long long> a(n);
    unordered_map<long long, long long> freq;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    for (long long x : a) {
        freq[x]++;
    }

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            long long x;
            cin >> x;
            freq[x]++;
        }
        else if (type == 2) {
            long long x;
            cin >> x;
            freq[x] = 0;
        }
        else if (type == 3) {
            long long x;
            cin >> x;
            long long total = 0;
            for (auto& [key, val] : freq) {
                if (key > x) {
                    total += key * val;
                }
            }
            cout << total << "\n";
        }
    }
    return 0;
}
