#include <iostream>
using namespace std;

int main() {
    freopen("nghiemnd.inp", "r" , stdin);
    freopen("nghiemnd.out", "w" , stdout);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    long long count = 0;

    for (int x = 1; a * x < d; ++x) {
        for (int y = 1; a * x + b * y < d; ++y) {
            int r = d - a * x - b * y;
            if (r > 0 && r % c == 0) {
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}
