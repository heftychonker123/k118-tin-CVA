#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("testcase.inp" , "w" , stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    srand(time(nullptr));

    int n = rand() % 100000 + 5;   // strip length between 5 and 20
    int k = rand() % n + 1;    // number of folds between 1 and n

    cout << n << " " << k << "\n";

    for (int i = 0; i < k; i++) {
        int x = rand() % (n+1);   // fold position between 0 and n
        cout << x << "\n";
    }

    return 0;
}
