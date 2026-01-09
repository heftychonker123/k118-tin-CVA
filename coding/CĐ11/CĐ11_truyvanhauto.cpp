#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; 
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<int> suffixDistinct(N);
    unordered_set<long long> seen;

    for (int i = N - 1; i >= 0; i--) {
        seen.insert(A[i]);
        suffixDistinct[i] = seen.size();
    }

    int Q; 
    cin >> Q;
    while (Q--) {
        int L; 
        cin >> L;
        cout << suffixDistinct[L] << "\n";
    }

    return 0;
}
