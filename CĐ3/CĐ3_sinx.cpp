#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    long double x, m;
    cin >> x >> m;

    long double term = x;      // First term: x^1 / 1!
    long double sum = 0.0;
    int n = 1;

    while (fabsl(term) > m) {
        sum += term;
        n += 2;
        term *= -1 * x * x / (n * (n - 1));  // Efficient recurrence for sine
    }

    cout << fixed << setprecision(5) << sum;
}
