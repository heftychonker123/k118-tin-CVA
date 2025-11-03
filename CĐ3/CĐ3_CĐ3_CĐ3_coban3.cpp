#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    // Dòng 1: In N chữ cái in hoa đầu tiên
    for (int i = 0; i < N; i++) {
        cout << char('A' + i) << " ";
    }
    cout << endl;

    // Dòng 2: In N chữ cái in thường cuối cùng
    for (int i = 26 - N; i < 26; i++) {
        cout << char('a' + i) << " ";
    }
    cout << endl;

    return 0;
}
