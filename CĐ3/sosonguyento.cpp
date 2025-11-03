#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("nguyento.inp" , "r" , stdin);
    freopen("nguyento.out" , "w" , stdout);
    int n;
    cin >> n;
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    int ans=0;
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i])
            ans++;
    }
    cout << ans;

    return 0;
}
