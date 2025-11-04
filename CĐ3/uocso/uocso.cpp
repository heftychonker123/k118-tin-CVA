#include <bits/stdc++.h>
using namespace std;

long long countDivisors(long long n) {
    long long count = 0;
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            if (i == n / i) count += 1;
            else count += 2;
        }
    }
    return count;
}

int main() {
    freopen("uocso.inp" , "r" , stdin);
    freopen("uocso.out" , "w" , stdout);
    long long a, b;
    cin >> a >> b;

    long long maxDivisors = 0;
    vector<long long> divisorCounts;
    int firstPos = 0, countMax = 0;

    for (long long i = a; i <= b; ++i) {
        long long divs = countDivisors(i);
        divisorCounts.push_back(divs);
        if (divs > maxDivisors) maxDivisors = divs;
    }

    for (int i = b - a; i >= 0; --i) {
        if (divisorCounts[i] == maxDivisors) {
            firstPos = a+i;
            countMax++;
        }
    }

    cout << firstPos << " " << maxDivisors << " " << countMax << endl;
}
