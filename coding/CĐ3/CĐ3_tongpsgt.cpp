#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    freopen("TONGPSGT.INP", "r", stdin);
    freopen("TONGPSGT.OUT", "w", stdout);

    int n;
    cin >> n;

    double sum = 0.0;
    double factorial = 1.0;

    for (int i = 1; i <= n; ++i) {
        factorial *= i;
        sum += 1.0 / factorial;
    }

    cout << fixed << setprecision(10) << sum << endl;

    return 0;
}
