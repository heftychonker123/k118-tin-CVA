#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Sum {
    ll value;
    int i, j;
    Sum(ll v, int a, int b) : value(v), i(a), j(b) {}
};

struct Compare {
    bool operator()(const Sum& a, const Sum& b) const {
        return a.value > b.value; // để tạo min-heap
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n, k;
    cin >> m >> n >> k;
    vector<ll> A(m), B(n);
    for (int i = 0; i < m; i++) cin >> A[i];
    for (int j = 0; j < n; j++) cin >> B[j];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    priority_queue<Sum, vector<Sum>, Compare> pq;
    pq.push(Sum(A[0] + B[0] , 0 , 0));

    while (k--){
        auto curr = pq.top(); pq.pop();
        cout << curr.value << " ";
        if (curr.i + 1 < m){
            ll sumI = curr.value - A[curr.i] + A[curr.i+1];
            pq.push(Sum(sumI , curr.i+1 , curr.j));
        }
        if (curr.j + 1 < n){
            ll sumJ = curr.value - B[curr.j] + B[curr.j+1];
            pq.push(Sum(sumJ , curr.i , curr.j+1));
        }
         
    }
    return 0;
}
