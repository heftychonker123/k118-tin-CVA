#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int t = 0; t<n-i; t++){
            cout << "  ";
        }
        int num = i;
        // In phần tăng
        for (int j = 1; j <= i; j++) {
            cout << num << " ";
            num++;
        }
        // In phần giảm
        num -= 2;
        for (int j = 1; j < i; j++) {
            cout << num << " ";
            num--;
        }
        cout << endl;
    }
    return 0;
}
