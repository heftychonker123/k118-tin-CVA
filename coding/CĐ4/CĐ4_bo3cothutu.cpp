#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string hasOrderedTriplet(const vector<int>& A) {
    int N = A.size();
    vector<int> minLeft(N), maxRight(N);

    // Tính min bên trái
    minLeft[0] = A[0];
    for (int i = 1; i < N; ++i) {
        minLeft[i] = min(minLeft[i - 1], A[i]);
    }

    // Tính max bên phải
    maxRight[N - 1] = A[N - 1];
    for (int i = N - 2; i >= 0; --i) {
        maxRight[i] = max(maxRight[i + 1], A[i]);
    }

    // Kiểm tra điều kiện
    for (int j = 1; j < N - 1; ++j) {
        if (minLeft[j - 1] < A[j] && A[j] < maxRight[j + 1]) {
            return "YES";
        }
    }
    return "NO";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        cout << hasOrderedTriplet(A) << endl;
    }
    return 0;
}
