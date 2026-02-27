#include <bits/stdc++.h>
using namespace std;

int n;
int cnt = 0;
vector<int> col;        // col[i] = vị trí quân hậu ở hàng i
vector<bool> uc;   // đánh dấu cột đã dùng
vector<bool> d1; // chéo chính (i - j + n)
vector<bool> d2; // chéo phụ (i + j)

void inkq() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (col[i] == j) cout << 1 << "";
            else cout << "0";
        }
        cout << "\n";
    }
    cout << "\n";
}

void backtrack(int row) {
    if (row > n) {
        inkq();
        return;
    }
    for (int j = 1; j <= n; j++) {
        if (!uc[j] && !d1[row - j + n] && !d2[row + j]) {
            col[row] = j;
            uc[j] = d1[row - j + n] = d2[row + j] = true;

            backtrack(row + 1);

            uc[j] = d1[row - j + n] = d2[row + j] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("nconhau.inp", "r", stdin);
    //freopen("nconhau.out", "w", stdout);
    cin >> n;
    col.assign(n + 1, 0);
    uc.assign(n + 1, false);
    d1.assign(2 * n + 1, false);
    d2.assign(2 * n + 1, false);

    backtrack(1);
    return 0;
}
