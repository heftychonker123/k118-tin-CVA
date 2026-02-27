#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    sort(v.begin(), v.end());

    long long option1 = v[n-1] * v[n-2] * v[n-3]; // Top 3 largest
    long long option2 = v[0] * v[1] * v[n-1];     // Two smallest and largest

    cout << max(option1, option2);
    return 0;
}
