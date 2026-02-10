#include <bits/stdc++.h>
using namespace std;
#define filename "sudoku"
#define ll long long
#define pb push_back
#define vect vector
ll a[9][9];
bool isValid(ll row, ll col, ll num) {
    for (int i = 0; i < 9; i++) {
        if (a[row][i] == num || a[i][col] == num) return false;
    }
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[startRow + i][startCol + j] == num) return false;
        }
    }
    return true;
}

bool solve() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (a[i][j] == 0) { 
                for (int num = 1; num <= 9; num++) {
                    if (isValid(i, j, num)) {
                        a[i][j] = num;
                        if (solve()) return true;
                        a[i][j] = 0; 
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void IO() {
    freopen(filename ".inp", "r", stdin);
    freopen(filename ".out", "w", stdout);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    IO();

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char t ; cin >> t;
            if (t=='.') a[i][j] = 0;
            else a[i][j] = t-'0';
        }
    }

    if (solve()) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << a[i][j] << "";
            }
            cout << "\n";
        }
    } 
    else cout << "0";

    return 0;
}
